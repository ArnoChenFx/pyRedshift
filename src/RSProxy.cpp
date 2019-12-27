#include "RSHead.h"
namespace py = pybind11;
using namespace pybind11::literals;

void ProxySaveToScene(RSProxy* proxy, RSScene* scene)
{
	int numMeshes = proxy->GetNumMeshes();
	for (int i = 0; i < numMeshes; ++i)
	{
		if (proxy->GetMeshEnabled(i))
			scene->AddMesh(proxy->GetMesh(i));
	}

	int numLights = proxy->GetNumLights();
	for (int i = 0; i < numLights; ++i)
	{
		if (proxy->GetLightEnabled(i))
		{
			scene->AddLight(proxy->GetLight(i));
			//cout << proxy->GetLight(i)->GetName() << endl;
		}
	}

	int numProceduals = proxy->GetNumProcedurals();
	for (int i = 0; i < numProceduals; ++i)
	{
		if (proxy->GetProceduralEnabled(i))
			scene->AddProcedural(proxy->GetProcedural(i));

	}

	int numVolumes = proxy->GetNumVolumeGrids();
	for (int i = 0; i < numVolumes; ++i)
	{
		if (proxy->GetVolumeGridEnabled(i))
			scene->AddVolumeGrid(proxy->GetVolumeGrid(i));
	}

	int numProxys = proxy->GetNumProxies();
	for (int i = 0; i < numProxys; ++i)
	{
		if (proxy->GetProxyEnabled(i))
		{
			RSProxy* subProxy = proxy->GetProxy(i);
			RSMatrix4x4 mat = subProxy->GetMatrix();
			subProxy->SetIsTransformationBlurred(false);
			subProxy->SetMatrix(mat);
			scene->AddProxy(subProxy);
			//cout << subProxy->GetFilenameAbsolute() << endl;
		}
	}
}



void ProxySaveToFile(RSProxy* proxy,const char* path,bool compression = true)
{
	//RSCamera *cam = RS_Camera_New();
	RSScene *scene = RS_Scene_New();
	RSProxy* newProxy = RS_Proxy_New("new proxy");
	ProxySaveToScene(proxy, scene);
	newProxy->SaveToFileFromScene(path, compression, *scene, nullptr);

	RS_Proxy_Delete(newProxy);
	//RS_Camera_Delete(cam);
	scene->ClearProxies();
	scene->ClearLights();
	scene->ClearMeshes();
	scene->ClearProcedurals();
	scene->ClearVolumeGrids();
	RS_Scene_Delete(scene);
}

void bindRSProxy(py::module&m)
{
	py::enum_<EProxyOverrideMode>(m, "EProxyOverrideMode")
		.value("RS_PROXY_OVERRIDEMODE_FROMFILE", RS_PROXY_OVERRIDEMODE_FROMFILE)
		.value("RS_PROXY_OVERRIDEMODE_FROMPROXY", RS_PROXY_OVERRIDEMODE_FROMPROXY)
		.value("RS_PROXY_OVERRIDEMODE_LEAVEALONE", RS_PROXY_OVERRIDEMODE_LEAVEALONE)
		.export_values();


	py::class_<RSProxy>(m, "RSProxy")
		.def("GetName", &RSProxy::GetName)
		.def("SetName", &RSProxy::SetName)
		.def("GetFilenameAbsolute", &RSProxy::GetFilenameAbsolute)
		.def("SetFilenameAbsolute", &RSProxy::SetFilenameAbsolute)
		.def("GetFilenameRelative", &RSProxy::GetFilenameRelative)
		.def("SetIsTransformationBlurred", &RSProxy::SetIsTransformationBlurred)
		.def("IsTransformationBlurred", &RSProxy::IsTransformationBlurred)
		.def("SetFlagOverrideMode", &RSProxy::SetFlagOverrideMode)
		.def("GetFlagOverrideMode", &RSProxy::GetFlagOverrideMode)
		.def("SetObjectIdOverrideMode", &RSProxy::SetObjectIdOverrideMode)
		.def("GetObjectIdOverrideMode", &RSProxy::GetObjectIdOverrideMode)
		.def("SetTessDispInfoOverrideMode", &RSProxy::SetTessDispInfoOverrideMode)
		.def("GetTessDispInfoOverrideMode", &RSProxy::GetTessDispInfoOverrideMode)
		.def("SetMatteInfoOverrideMode", &RSProxy::SetMatteInfoOverrideMode)
		.def("GetMatteInfoOverrideMode", &RSProxy::GetMatteInfoOverrideMode)
		.def("GetFlag", &RSProxy::GetFlag)
		.def("SetFlag", &RSProxy::SetFlag)
		.def("GetCachedMeshFlags", &RSProxy::GetCachedMeshFlags)
		.def("SetCachedMeshFlags", &RSProxy::SetCachedMeshFlags)
		.def("GetObjectId", &RSProxy::GetObjectId)
		.def("SetObjectId", &RSProxy::SetObjectId)
		.def("GetTessDispInfo", &RSProxy::GetTessDispInfo)
		.def("SetTessDispInfo", &RSProxy::SetTessDispInfo)
		.def("GetNumTransformationSteps", &RSProxy::GetNumTransformationSteps)
		.def("SetMatrix", &RSProxy::SetMatrix)
		.def("GetMatrix", py::overload_cast<>(&RSProxy::GetMatrix, py::const_))
		.def("GetMatrix", py::overload_cast<unsigned int>(&RSProxy::GetMatrix, py::const_))
		.def("SaveToFileFromScene", [](RSProxy &self, const char* filePath, bool enableCompression, RSScene* scene, RSCamera* pCamera)
			{self.SaveToFileFromScene(filePath, enableCompression, *scene, pCamera);})
		.def("SaveToFile", [](RSProxy &self, const char* filePath, bool enableCompression)
			{ProxySaveToFile(&self, filePath,enableCompression); })
		//.def("LoadFromFile", &RSProxy::LoadFromFile,"filePath"_a, "skipSceneData"_a, "pReturnedCamera"_a, "pMaterialReplacements"_a=NULL, "muteErrors"_a=false)
		.def("LoadFromFile", [](RSProxy &self, const char* filePath, bool skipSceneData, bool muteErrors = false) 
			{   RSCamera* cam = RS_Camera_New();
				self.LoadFromFile(filePath, skipSceneData, cam,  NULL,  muteErrors ); 
				return cam; }, py::return_value_policy::reference)
		.def("GetMaterials", &RSProxy::GetMaterials)
		.def("GetMatteInfo", &RSProxy::GetMatteInfo)
		.def("SetMatteInfo", &RSProxy::SetMatteInfo)
		.def("GetNumMeshes", &RSProxy::GetNumMeshes)
		.def("GetMesh", &RSProxy::GetMesh, py::return_value_policy::reference)
		.def("SetMeshEnabled", &RSProxy::SetMeshEnabled)
		.def("GetMeshEnabled", &RSProxy::GetMeshEnabled)
		.def("GetNumLights", &RSProxy::GetNumLights)
		.def("GetLight", &RSProxy::GetLight, py::return_value_policy::reference)
		.def("SetLightEnabled", &RSProxy::SetLightEnabled)
		.def("GetLightEnabled", &RSProxy::GetLightEnabled)
		.def("GetNumVolumeGrids", &RSProxy::GetNumVolumeGrids)
		.def("GetVolumeGrid", &RSProxy::GetVolumeGrid, py::return_value_policy::reference)
		.def("SetVolumeGridEnabled", &RSProxy::SetVolumeGridEnabled)
		.def("GetVolumeGridEnabled", &RSProxy::GetVolumeGridEnabled)
		.def("GetNumProxies", &RSProxy::GetNumProxies)
		.def("GetProxy", &RSProxy::GetProxy, py::return_value_policy::reference)
		.def("SetProxyEnabled", &RSProxy::SetProxyEnabled)
		.def("GetProxyEnabled", &RSProxy::GetProxyEnabled)
		.def("GetNumProcedurals", &RSProxy::GetNumProcedurals)
		.def("GetProcedural", &RSProxy::GetProcedural, py::return_value_policy::reference)
		.def("SetProceduralEnabled", &RSProxy::SetProceduralEnabled)
		.def("GetProceduralEnabled", &RSProxy::GetProceduralEnabled)
		.def("SetTraceSetsOverrideMode", &RSProxy::SetTraceSetsOverrideMode)
		.def("GetTraceSetsOverrideMode", &RSProxy::GetTraceSetsOverrideMode)
		.def("SetReflectionTraceSet", &RSProxy::SetReflectionTraceSet)
		.def("GetReflectionTraceSet", &RSProxy::GetReflectionTraceSet, py::return_value_policy::reference)
		.def("SetRefractionTraceSet", &RSProxy::SetRefractionTraceSet)
		.def("GetRefractionTraceSet", &RSProxy::GetRefractionTraceSet, py::return_value_policy::reference)
		.def("SetSSSTraceSet", &RSProxy::SetSSSTraceSet)
		.def("GetSSSTraceSet", &RSProxy::GetSSSTraceSet, py::return_value_policy::reference)
		.def("SetUserDataOverrideMode", &RSProxy::SetUserDataOverrideMode)
		.def("GetUserDataOverride", &RSProxy::GetUserDataOverride)
		.def("SetUserData", &RSProxy::SetUserData)
		.def("GetUserData", &RSProxy::GetUserData, py::return_value_policy::reference);


	py::class_<RSProxy::MaterialReplacement>(m, "MaterialReplacement")
		.def_readwrite("from", &RSProxy::MaterialReplacement::from)
		.def_readwrite("to", &RSProxy::MaterialReplacement::to);

	py::class_<RSProxyInstance>(m, "RSProxyInstance")
		.def("SetIsTransformationBlurred", &RSProxyInstance::SetIsTransformationBlurred)
		.def("IsTransformationBlurred", &RSProxyInstance::IsTransformationBlurred)
		.def("GetTemplate", &RSProxyInstance::GetTemplate, py::return_value_policy::reference)
		.def("SetTemplate", &RSProxyInstance::SetTemplate)
		.def("GetFlag", &RSProxyInstance::GetFlag)
		.def("GetCachedMeshFlags", &RSProxyInstance::GetCachedMeshFlags)
		.def("SetCachedMeshFlags", &RSProxyInstance::SetCachedMeshFlags)
		.def("SetMatrix", &RSProxyInstance::SetMatrix)
		.def("GetNumTransformationSteps", &RSProxyInstance::GetNumTransformationSteps)
		.def("GetMatrix", py::overload_cast<>(&RSProxyInstance::GetMatrix,py::const_))
		.def("GetMatrix", py::overload_cast<unsigned int>(&RSProxyInstance::GetMatrix, py::const_))
		.def("GetMatteInfo", &RSProxyInstance::GetMatteInfo)
		.def("SetMatteInfo", &RSProxyInstance::SetMatteInfo)
		.def("SetUserData", &RSProxyInstance::SetUserData)
		.def("GetUserData", &RSProxyInstance::GetUserData, py::return_value_policy::reference);

	m.def("RS_Proxy_New", &RS_Proxy_New, py::return_value_policy::reference);
	m.def("RS_Proxy_Delete", &RS_Proxy_Delete);
	m.def("RS_ProxyInstance_New", &RS_ProxyInstance_New, py::return_value_policy::reference);
	m.def("RS_ProxyInstance_Delete", &RS_ProxyInstance_Delete);


	py::class_<RSProxyHeaderData>(m, "RSProxyHeaderData")
		.def("GetVersion", &RSProxyHeaderData::GetVersion)
		.def("GetRedshiftVersion", &RSProxyHeaderData::GetRedshiftVersion)
		.def("GetHostName", &RSProxyHeaderData::GetHostName)
		.def("GetDate", &RSProxyHeaderData::GetDate)
		.def("GetOverallAABBMinCorner", &RSProxyHeaderData::GetOverallAABBMinCorner)
		.def("GetMaterialNames", &RSProxyHeaderData::GetMaterialNames)
		.def("GetMeshNames", &RSProxyHeaderData::GetMeshNames)
		.def("GetLightNames", &RSProxyHeaderData::GetLightNames)
		.def("GetVolumeGridNames", &RSProxyHeaderData::GetVolumeGridNames)
		.def("GetVolumeGridFilenames", &RSProxyHeaderData::GetVolumeGridFilenames)
		.def("GetProxyNames", &RSProxyHeaderData::GetProxyNames)
		.def("GetProxyFilenames", &RSProxyHeaderData::GetProxyFilenames)
		.def("GetProceduralNames", &RSProxyHeaderData::GetProceduralNames)
		.def("GetAttributeNames", &RSProxyHeaderData::GetAttributeNames)
		.def("GetTextureFilenames", &RSProxyHeaderData::GetTextureFilenames)
		.def("GetTiledTextureFilenames", &RSProxyHeaderData::GetTiledTextureFilenames);

	m.def("RS_ProxyData_ListDependencies", &RS_ProxyData_ListDependencies, "proxyFilename"_a, "dTiledTextureFilenames"_a, "dTextureFilenames"_a, "dProxyFilenames"_a,"dVolumeFilenames"_a,"bRecurse"_a=true);

	py::class_<RSProxyGeometryData>(m, "RSProxyGeometryData")
		.def("GetTriangleVertexPositions", &RSProxyGeometryData::GetTriangleVertexPositions)
		.def("GetTriangleVertexIndices", &RSProxyGeometryData::GetTriangleVertexIndices)
		.def("GetLineVertexPositions", &RSProxyGeometryData::GetLineVertexPositions)
		.def("GetPointPositions", &RSProxyGeometryData::GetPointPositions);


	m.def("RS_ProxyData_LoadHeaderDataFromFile", &RS_ProxyData_LoadHeaderDataFromFile, py::return_value_policy::reference);
	m.def("RS_ProxyHeaderData_Delete", &RS_ProxyHeaderData_Delete);
	m.def("RS_ProxyData_LoadGeometryDataFromFile", &RS_ProxyData_LoadGeometryDataFromFile, py::return_value_policy::reference);
	m.def("RS_ProxyGeometryData_Delete", &RS_ProxyGeometryData_Delete);

	m.def("ProxySaveToFile", &ProxySaveToFile);
	m.def("ProxySaveToScene", &ProxySaveToScene);
}
