import pyRedshift
reload(pyRedshift)
from pyRedshift import *
import hou
import os
    
def createGraph(rsNode,houNode,dataDict):
    count = rsNode.GetParameterCount()
    dataDict[rsNode] = houNode
    for i in xrange(count):
        #if not rsNode.IsParameterDCCConvertable(i):
        #  return
        isValue = True    
        rsNodeParamName = rsNode.GetParameterName(i)
        
        if rsNode.GetClassName() == "RSMath":
            isValue = False
            parm = houNode.parmTuple("input")
            if rsNodeParamName == "inputv1":
                color = rsNode.GetVector(i)
                parm.set([color.x,color.y,color.z,color.w])
            print rsNodeParamName,rsNode.ParameterDataToString(i)
                
        elif rsNode.IsParameterAColor(i):
            parm = houNode.parmTuple(rsNodeParamName)
            color = rsNode.GetVector(i)
            
            isValue = False
            if parm and color:
                num = rsNode.GetParameterNumVectorComponents(i)
                try:
                    if num == 3:
                        parm.set([color.x,color.y,color.z])    
                    elif num == 4:    
                        parm.set([color.x,color.y,color.z,color.w])  
                except:
                    print "color Parm: ",houNode.name(),rsNodeParamName
                    pass
            
        if rsNode.IsParameterATexture(i):
            isValue = False
            file = rsNode.ParameterDataToString(i)
            file = file.replace("(", "")
            file = file.replace(")", "")
            file = file.replace("texture: ", "")
            file = fixPath(file)
            parm = houNode.parm(rsNodeParamName)
            if not parm:
                parm = houNode.parm("tex0")
            if parm:    
                parm.set(file)                    
        elif rsNode.IsParameterTexturable(i):
            newRsNode = rsNode.GetNode(i)
            if newRsNode:
                isValue = False
                newRsNodeClass = newRsNode.GetClassName()
                houNodeParmIndex = houNode.inputIndex(rsNodeParamName)
                if houNodeParmIndex is not None:
                    #print "enable: ",rsNodeParamName," ",houNodeParmIndex," ",newRsNodeClass
                    if newRsNode in dataDict.keys():
                        newHouNode = dataDict[newRsNode]
                        houNode.setInput(houNodeParmIndex,newHouNode)
                    else:    
                        if newRsNodeClass == "ColorCorrection":
                            newRsNodeClass = "RSColorCorrection"
                        elif newRsNodeClass == "RSMath":
                            newRsNodeClass = "RSMathAbsColor"
                        newHouNode = None
                        try:
                            newHouNode = houNode.createInputNode(houNodeParmIndex,newRsNodeClass)
                        except:
                            try:
                                newHouNode = houNode.createInputNode(houNodeParmIndex,"RS"+newRsNodeClass)
                            except:
                                #print "no name: ",newRsNodeClass
                                pass
                        #print houNode.name()," connect to: ",newHouNode.name()
                        if newHouNode:
                            createGraph(newRsNode,newHouNode,dataDict)
                   
                        
                else:
                    print "disable: ",rsNodeParamName
        
        if rsNode.IsParameterAttributeSpaceID(i):
            #print houNode.name(),"-->",rsNodeParamName
            isValue = False
        elif rsNode.IsParameterAttributeUVSpaceID(i):
            isValue = False
        elif rsNode.IsParameterAttributeNonUVSpaceID(i):
            isValue = False
        elif rsNode.IsParameterACurve(i):
            print "Curve: ",houNode.name(),"-->",rsNodeParamName
            value = rsNode.ParameterDataToString(i)
            print value
            isValue = False
        elif rsNode.IsParameterAMonoCurve(i):
            print "MonoCurve: ",houNode.name(),"-->",rsNodeParamName
            isValue = False
        elif rsNode.IsParameterAColorCurve(i):
            print "ColorCurve: ",houNode.name(),"-->",rsNodeParamName
            isValue = False
        elif rsNode.IsParameterAnIESProfile(i):
            print "IESProfile: ",houNode.name(),"-->",rsNodeParamName
            isValue = False
        elif rsNode.IsParameterBumpInput(i):
            isValue = False
        #elif rsNode.IsParameterMixedInput(i):
        #    print houNode.name(),"-->",rsNodeParamName
        #    isValue = False
            
                        
        parm = None
        isString = False
        isFloat = False
        isInt = False
        if isValue:
            parm = houNode.parm(rsNodeParamName)
            if parm:
                try:
                    parm.evalAsFloat()
                    isFloat = True
                except:
                    isValue = False
                    isFloat = False
                    try:
                        parm.evalAsInt() 
                        isValue = True
                        isInt = True
                    except:
                        isValue = False 
                        isInt = False
                        try:
                            parm.evalAsString()
                            isValue = True  
                            isString = True
                        except:
                            isString = False
            if not parm:
                parm = houNode.parmTuple(rsNodeParamName)
                isValue = True
                
        if parm and isValue:
            #print houNode.name(),"-->",rsNodeParamName
            num = 0
            if isString:
                valueString = rsNode.ParameterDataToString(i)
                #if rsNodeParamName == "refl_endmode":
                #    print valueString
                if len(valueString) == 3:
                    valueString = valueString[1]
                parm.set(valueString)
                
            elif isFloat:
                value = rsNode.GetScalar(i)
                parm.set(value)
            elif isInt:
                value = rsNode.ParameterDataToString(i)
                if "true" in value:
                    parm.set(1)
                elif "false" in value:
                    parm.set(0)
                elif "." not in value:
                    value = rsNode.GetInteger(i)
                    parm.set(value)
            else:
                num = rsNode.GetParameterNumVectorComponents(i)   
            
            if num == 1:
                value = rsNode.GetDefault(i)
                parm.set(value.x)
                print rsNodeParamName,value.x
            elif num == 2: 
                valueTuple = rsNode.GetDefault(i)
                if valueTuple:
                    parm.set([valueTuple.x,valueTuple.y])
            elif num == 3: 
                valueTuple = rsNode.GetDefault(i)
                if valueTuple:
                    parm.set([valueTuple.x,valueTuple.y,valueTuple.z])
            elif num == 4: 
                valueTuple = rsNode.GetDefault(i)
                if valueTuple:
                    parm.set([valueTuple.x,valueTuple.y,valueTuple.z,valueTuple.w])
          
        
            
            
def createMat(mat,name=None):
    try:
        vopnet = hou.node("/mat").createNode("redshift_vopnet",name)
    except:
        vopnet = hou.node("/mat").createNode("redshift_vopnet")
    outputNode = vopnet.children()[0]
    
    graphs = []
    dataDict = {}
    
    surface = mat.GetShaderNodeGraph("RS_SF_SURFACE")
    if surface:
        surfaceRootNode = outputNode.createInputNode(0,surface.GetClassName())
        createGraph(surface,surfaceRootNode,dataDict)
        graphs.append(surface)

    if mat.HasDisplacementShader():
        disp = mat.GetShaderNodeGraph("RS_SF_DISPLACEMENT")
        if disp not in graphs:
            dispRootNode = outputNode.createInputNode(1,disp.GetClassName())
            createGraph(disp,dispRootNode,dataDict)
            graphs.append(disp)
    
    bump = mat.GetShaderNodeGraph("RS_SF_BUMPMAP")
    if bump and bump not in graphs:
        bumpRootNode = outputNode.createInputNode(2,bump.GetClassName())
        createGraph(bump,bumpRootNode,dataDict)
        graphs.append(bump)

    volume = mat.GetShaderNodeGraph("RS_SF_VOLUME")
    if volume and volume not in graphs:
        volumeRootNode = outputNode.createInputNode(4,volume.GetClassName())
        createGraph(volume,volumeRootNode,dataDict)
        graphs.append(volume)

    env = mat.GetShaderNodeGraph("RS_SF_ENVIRONMENT")
    if env and env not in graphs:
        envRootNode = outputNode.createInputNode(3,env.GetClassName())
        createGraph(env,envRootNode,dataDict)
        graphs.append(env)

    photo = mat.GetShaderNodeGraph("RS_SF_PHOTON")
    if photo and photo not in graphs:
        photoRootNode = outputNode.createInputNode(6,photo.GetClassName())
        createGraph(photo,photoRootNode,dataDict)
        graphs.append(photo)

    shadow = mat.GetShaderNodeGraph("RS_SF_SHADOW")
    if shadow and shadow not in graphs:
        shadowRootNode = outputNode.createInputNode(5,shadow.GetClassName())
        createGraph(shadow,shadowRootNode,dataDict)
        graphs.append(shadow)
        
    vopnet.layoutChildren()
    vopnet.moveToGoodPosition()
    return vopnet
    
 
def ProxyToMaterial(file_path):
    proxy = RS_Proxy_New("arno_proxy")
    cam = proxy.LoadFromFile(file_path,True,False)
    
    mats = proxy.GetMaterials()
    names = []
    for i in xrange(mats.Length()):
        material = mats[i].GetFriendlyName()
        material = material.replace(".","_")
        material = material.replace(" ","_")
        if material not in names:
            names.append(material)
            print "Material: ",material
            createMat(mats[i],material)
            
    RS_Camera.RS_Camera_Delete(cam)
    RS_Proxy.RS_Proxy_Delete(proxy)

# file_path = "D:/DATA/Download/temp/branch.rs"
# ProxyToMaterial(file_path)