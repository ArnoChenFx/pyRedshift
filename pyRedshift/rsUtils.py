#coding:utf-8
from .pyRedshift import *
from .pyRedshift.RS_Texture import *
from .pyRedshift.RS_Light import *
from .pyRedshift.RS_ShaderNode import *
from .pyRedshift.RS_Material import *
from .pyRedshift.RS_Attributes import *
from .pyRedshift.RS_Camera import *
from .pyRedshift.RS_VolumeGrid import *
from .pyRedshift.RS_Scene import *
from .pyRedshift.RS_Proxy import *
import os

def nodeSetParameterData(shaderNode,paramName,data):
    paramIndex = shaderNode.GetParameterIndex(paramName)
    return shaderNode.SetParameterData(paramIndex,data)

def py_end_redshift():
    RS_Log.RS_Log_Shutdown()
    RS_Renderer.RS_Renderer_Shutdown()


def getAllTextures(node,data,containNode=True):
    count = node.GetParameterCount()
    for i in xrange(count):
        if node.IsParameterATexture(i):
            
            file = node.ParameterDataToString(i)
            file = file.replace("texture: ", "")
            if file.startswith("("):
                file = file[1:-1]
            #print "Texture: ", file
            
            if containNode:
                data[file] = [node,i]
            else:
                data[file] = [node.GetClassName(),i]
		
        elif node.IsParameterTexturable(i):
            inNode = node.GetNode(i)
            if inNode:
                #print node.GetClassName(),"-->",i ,"-->",node.GetParameterName(i),"-->" ,inNode.GetClassName()
                getAllTextures(inNode,data,containNode)


def getMaterialData(mat,containNode = True):
    data = {}
    graphs = []
    surface = mat.GetShaderNodeGraph("RS_SF_SURFACE")
    if surface and surface not in graphs:
        getAllTextures(surface,data,containNode)
        graphs.append(surface)

    if mat.HasDisplacementShader():
        disp = mat.GetShaderNodeGraph("RS_SF_DISPLACEMENT")
        if disp not in graphs:
            getAllTextures(disp,data,containNode)
            graphs.append(disp)

    bump = mat.GetShaderNodeGraph("RS_SF_BUMPMAP")
    if bump and bump not in graphs:
        getAllTextures(bump,data,containNode)
        graphs.append(bump)

    volume = mat.GetShaderNodeGraph("RS_SF_VOLUME")
    if volume and volume not in graphs:
        getAllTextures(volume,data,containNode)
        graphs.append(volume)

    env = mat.GetShaderNodeGraph("RS_SF_ENVIRONMENT")
    if env and env not in graphs:
        getAllTextures(env,data,containNode)
        graphs.append(env)

    photo = mat.GetShaderNodeGraph("RS_SF_PHOTON")
    if photo and photo not in graphs:
        getAllTextures(photo,data,containNode)
        graphs.append(photo)

    shadow = mat.GetShaderNodeGraph("RS_SF_SHADOW")
    if shadow and shadow not in graphs:
        getAllTextures(shadow,data,containNode)
        graphs.append(shadow)

    return data
    

def changeTextureParam(node,idx,file):
    pRSTexture = RS_Texture_Get(file)
    node.BeginUpdate()
    node.SetParameterData(idx, pRSTexture)
    node.EndUpdate()
    RS_Texture_Release(pRSTexture)
		

def getFileName(file):
    path,name = os.path.split(file)
    name,ext = os.path.splitext(name)
    return name


def fixPath(path):
    path = path.replace("\\","/")
    paths = path.split(":")
    if len(paths)>1:
        d = paths[0][-1]
        paths.remove(paths[0])
        path = d + ":" + ":".join(paths)
    return path

#sceneMaterialData ---> [{materialName:{texturePath:[shaderNode,paramIndex]}},index]     
