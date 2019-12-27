#include "RSHead.h"
namespace py = pybind11;
using namespace pybind11::literals;

class MyLogSink : public RSLogSink
{
	
	void Log(RSLogLevel level, const char* msg, size_t nCharsMSG)
	{
		if (showLog)
		{
			RSString strippedTags = msg;
			RS_Utility_StripHTMLTags(strippedTags);
			printf("%s", strippedTags.c_str());
			fflush(stdout);
		}
	}
public:
	bool showLog = true;
};

void start_redshift(bool showLog = true)
{
	RSString pathConfigPath, coreDataPath, localDataPath, proceduralsPath, prefsFileFullPath, licensePath;
	RS_Renderer_ObtainNecessaryPaths(pathConfigPath, coreDataPath, localDataPath, proceduralsPath, prefsFileFullPath, licensePath);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// LOG INIT
	RS_Log_Init(localDataPath);


	MyLogSink* pMyLogSink = new MyLogSink;
	pMyLogSink->showLog = showLog;
	RS_Log_AddSink(pMyLogSink);


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// INIT BASE RENDERER SYSTEMS
	RS_Renderer_SetPreferencesFilePath(prefsFileFullPath);
	RS_Renderer_Init();
	RS_Renderer_SetCoreDataPath(coreDataPath);
	RS_Renderer_SetLicensePath(licensePath);
	RS_Renderer_SetProceduralPath(proceduralsPath);

	unsigned int textureCacheBudgetMB = RS_Renderer_GetDefaultTextureCacheBudgetGB() * 1024;
	if (const char* var = getenv("REDSHIFT_TEXTURECACHEBUDGET"))
	{
		int textureCacheBudgetGB_query = atoi(var);
		RSLogMessage(Debug, "Querying texture cache buget from REDSHIFT_TEXTURECACHEBUDGET: %d GB", textureCacheBudgetGB_query);
		textureCacheBudgetMB = (unsigned int)textureCacheBudgetGB_query * 1024;
	}
	else
	{
		int textureCacheBudgetGB_query;
		RS_Renderer_GetPreferenceValue("TextureCacheBudgetGB", textureCacheBudgetGB_query, RS_Renderer_GetDefaultTextureCacheBudgetGB());
		textureCacheBudgetMB = (unsigned int)textureCacheBudgetGB_query * 1024;
		RSLogMessage(Debug, "Querying texture cache buget from preferences.xml: %d GB", textureCacheBudgetGB_query);
	}

	RSString cacheFolder_query;
	if (const char* var = getenv("REDSHIFT_CACHEPATH"))
	{
		cacheFolder_query = var;
		RSLogMessage(Debug, "Querying cache path from REDSHIFT_CACHEPATH: %s", (const char*)cacheFolder_query);
	}
	else
	{
		RS_Renderer_GetPreferenceValue("CacheFolder", cacheFolder_query, RS_Renderer_GetDefaultCacheFolder());
		RSLogMessage(Debug, "Querying cache path from preferences.xml: %s", (const char*)cacheFolder_query);
	}

	RS_Renderer_SetCachePath((const char*)cacheFolder_query, textureCacheBudgetMB);

	// Reads a preferences.xml (see above) and sets the GPU device ordinal array
	RSArray<int> selectedCudaDeviceOrdinals;
	RS_Renderer_GetSelectedCudaDeviceOrdinalsFromPreferences(selectedCudaDeviceOrdinals);
	RS_Renderer_Create((unsigned int)selectedCudaDeviceOrdinals.Length(), (int*)&selectedCudaDeviceOrdinals[0]);


	delete pMyLogSink;
	
}


void end_redshift()
{
	RS_Renderer_Destroy();
	RS_Log_Shutdown();
	RS_Renderer_Shutdown();
}

void bindRSRenderer(py::module&m)
{
	py::class_<RSRendererMemStatus>(m, "RSRendererMemStatus")
		.def("GetCurrentStageString", &RSRendererMemStatus::GetCurrentStageString)
		.def("GetTotalFreeMem", &RSRendererMemStatus::GetTotalFreeMem)
		.def("GetFixedOverheadMem", &RSRendererMemStatus::GetFixedOverheadMem)
		.def("GetGeometryMemUploaded", &RSRendererMemStatus::GetGeometryMemUploaded)
		.def("GetGeometryMemMax", &RSRendererMemStatus::GetGeometryMemMax)
		.def("GetTextureMemUploaded", &RSRendererMemStatus::GetTextureMemUploaded)
		.def("GetTextureMemMax", &RSRendererMemStatus::GetTextureMemMax)
		.def("GetRayMemUsed", &RSRendererMemStatus::GetRayMemUsed)
		.def("GetMatrixMemUsed", &RSRendererMemStatus::GetMatrixMemUsed)
		.def("GetSpriteNodeTextureMemUsed", &RSRendererMemStatus::GetSpriteNodeTextureMemUsed)
		.def("GetPhotonMemUsed", &RSRendererMemStatus::GetPhotonMemUsed)
		.def("GetICPMemUsed", &RSRendererMemStatus::GetICPMemUsed)
		.def("GetIPCMemUsed", &RSRendererMemStatus::GetIPCMemUsed)
		.def("GetSSSMemUsed", &RSRendererMemStatus::GetSSSMemUsed);

	py::class_<RSProfilerControl>(m, "RSProfilerControl")
		.def("EnableAccessor", &RSProfilerControl::EnableAccessor)
		.def("DoTimerBreakdownAccessor", &RSProfilerControl::DoTimerBreakdownAccessor)
		.def("RTHDetailAccessor", &RSProfilerControl::RTHDetailAccessor)
		.def("PCDetailAccessor", &RSProfilerControl::PCDetailAccessor)
		.def("PRIPCDetailAccessor", &RSProfilerControl::PRIPCDetailAccessor)
		.def("PRICPDetailAccessor", &RSProfilerControl::PRICPDetailAccessor)
		.def("PRSSSDetailAccessor", &RSProfilerControl::PRSSSDetailAccessor)
		.def("RenderingDetailAccessor", &RSProfilerControl::RenderingDetailAccessor)
		.def("VMPDetailAccessor", &RSProfilerControl::VMPDetailAccessor)
		.def("RTUDetailAccessor", &RSProfilerControl::RTUDetailAccessor)
		.def("SPDetailAccessor", &RSProfilerControl::SPDetailAccessor)
		.def("PRDetailAccessor", &RSProfilerControl::PRDetailAccessor)
		.def("AODetailAccessor", &RSProfilerControl::AODetailAccessor)
		.def("DLDetailAccessor", &RSProfilerControl::DLDetailAccessor)
		.def("ILDetailAccessor", &RSProfilerControl::ILDetailAccessor)
		.def("SSDetailAccessor", &RSProfilerControl::SSDetailAccessor)
		.def("SSSDetailAccessor", &RSProfilerControl::SSSDetailAccessor)
		.def("SHDetailAccessor", &RSProfilerControl::SHDetailAccessor)
		.def("TXDetailAccessor", &RSProfilerControl::TXDetailAccessor);

	m.def("RS_Renderer_GetVersion", &RS_Renderer_GetVersion);
	m.def("RS_Renderer_GetVersionString", &RS_Renderer_GetVersionString);
	m.def("RS_Renderer_IsDemo", &RS_Renderer_IsDemo);
	m.def("RS_Renderer_Init", &RS_Renderer_Init);
	m.def("RS_Renderer_Shutdown", &RS_Renderer_Shutdown);
	m.def("RS_Renderer_CheckComputeCapability", &RS_Renderer_CheckComputeCapability);
	m.def("RS_Renderer_EnumerateSupportedDevices", &RS_Renderer_EnumerateSupportedDevices);
	m.def("RS_Renderer_Create", py::overload_cast<const char *, unsigned int, int*>(&RS_Renderer_Create));
	m.def("RS_Renderer_Create", py::overload_cast<unsigned int, int*>(&RS_Renderer_Create));
	m.def("RS_Renderer_Destroy", &RS_Renderer_Destroy);
	m.def("RS_Renderer_MinimalDestroyToTerminateThreads", &RS_Renderer_MinimalDestroyToTerminateThreads);
	m.def("RS_Renderer_GetMaxNumActiveDevices", &RS_Renderer_GetMaxNumActiveDevices);
	m.def("RS_Renderer_GetNumActiveDevices", &RS_Renderer_GetNumActiveDevices);
	m.def("RS_Renderer_GetDeviceName", &RS_Renderer_GetDeviceName);
	m.def("RS_Renderer_GetDevicePCIBusID", &RS_Renderer_GetDevicePCIBusID);
	m.def("RS_Renderer_GetMemStatus", &RS_Renderer_GetMemStatus);
	m.def("RS_Renderer_GetProfiler", &RS_Renderer_GetProfiler);


	py::class_<RSAbortChecker, std::unique_ptr<RSAbortChecker, py::nodelete>>(m, "RSAbortChecker")
		.def("ShouldAbort", &RSAbortChecker::ShouldAbort);

	py::class_<RSProgressReporter, std::unique_ptr<RSProgressReporter, py::nodelete>>(m, "RSProgressReporter")
		.def("SetProgress", &RSProgressReporter::SetProgress)
		.def("SetRenderingProgress", &RSProgressReporter::SetRenderingProgress);

	m.def("RS_Renderer_Render", &RS_Renderer_Render);
	m.def("RS_Renderer_ObtainNecessaryPaths", &RS_Renderer_ObtainNecessaryPaths);
	m.def("RS_Renderer_GetDefaultCachePath", &RS_Renderer_GetDefaultCachePath);
	m.def("RS_Renderer_SetCoreDataPath", &RS_Renderer_SetCoreDataPath);
	m.def("RS_Renderer_SetLicensePath", &RS_Renderer_SetLicensePath);
	m.def("RS_Renderer_GetCoreDataPath", &RS_Renderer_GetCoreDataPath);
	m.def("RS_Renderer_GetCachePath", &RS_Renderer_GetCachePath);
	m.def("RS_Renderer_GetCachePath_Meshes", &RS_Renderer_GetCachePath_Meshes);
	m.def("RS_Renderer_GetProceduralPath", &RS_Renderer_GetProceduralPath);

	m.def("RS_Renderer_PathOverridesClear", &RS_Renderer_PathOverridesClear);
	m.def("RS_Renderer_PathOverridesAddFromEnvVariables", &RS_Renderer_PathOverridesAddFromEnvVariables);
	m.def("RS_Renderer_PathOverridesAddFromArrays", &RS_Renderer_PathOverridesAddFromArrays);
	m.def("RS_Renderer_PathOverridesAreEnabled", &RS_Renderer_PathOverridesAreEnabled);
	m.def("RS_Renderer_PathOverrideApply", &RS_Renderer_PathOverrideApply);
	m.def("RS_Renderer_SetPreferencesFilePath", &RS_Renderer_SetPreferencesFilePath);
	m.def("RS_Renderer_GetPreferenceType", &RS_Renderer_GetPreferenceType);
	m.def("RS_Renderer_GetPreferenceValue", py::overload_cast<const char*, RSString&, const char*>(&RS_Renderer_GetPreferenceValue), "prefName"_a, "value"_a, "def"_a = "");
	m.def("RS_Renderer_GetPreferenceValue", py::overload_cast<const char*, int&, int>(&RS_Renderer_GetPreferenceValue), "prefName"_a, "value"_a, "def"_a = 0);
	m.def("RS_Renderer_SetPreferenceValue", py::overload_cast<const char*, const char* , bool>(&RS_Renderer_SetPreferenceValue), "prefName"_a, "value"_a, "save"_a = true);
	m.def("RS_Renderer_SetPreferenceValue", py::overload_cast<const char*, int , bool>(&RS_Renderer_SetPreferenceValue), "prefName"_a, "value"_a, "save"_a = true);
	m.def("RS_Renderer_GetDefaultCacheFolder", &RS_Renderer_GetDefaultCacheFolder);
	m.def("RS_Renderer_GetDefaultTextureCacheBudgetGB", &RS_Renderer_GetDefaultTextureCacheBudgetGB);
	m.def("RS_Renderer_GetDefaultCudaDevice", &RS_Renderer_GetDefaultCudaDevice);
	m.def("RS_Renderer_GetDefaultCudaDeviceName", &RS_Renderer_GetDefaultCudaDeviceName);
	m.def("RS_Renderer_GetSelectedCudaDeviceOrdinalsFromPreferences", &RS_Renderer_GetSelectedCudaDeviceOrdinalsFromPreferences);
	m.def("RS_Renderer_SetSamplingGamma", &RS_Renderer_SetSamplingGamma);
	m.def("RS_Renderer_GetSamplingGamma", &RS_Renderer_GetSamplingGamma);
	m.def("RS_Renderer_SetDisplayGamma", &RS_Renderer_SetDisplayGamma);
	m.def("RS_Renderer_GetDisplayGamma", &RS_Renderer_GetDisplayGamma);

	m.def("RS_Renderer_SetColorInputGamma", &RS_Renderer_SetColorInputGamma);
	m.def("RS_Renderer_GetColorInputGamma", &RS_Renderer_GetColorInputGamma);
	m.def("RS_Renderer_SetDCCGamma", &RS_Renderer_SetDCCGamma);
	m.def("RS_Renderer_GetDCCGamma", &RS_Renderer_GetDCCGamma);
	m.def("RS_Renderer_SetBakeData", &RS_Renderer_SetBakeData);
	m.def("RS_Renderer_SetBakeDataTileInfo", &RS_Renderer_SetBakeDataTileInfo);
	m.def("RS_Renderer_SetGlobalEnvironmentShader", &RS_Renderer_SetGlobalEnvironmentShader);
	m.def("RS_Renderer_SetGlobalVolumeShader", &RS_Renderer_SetGlobalVolumeShader);
	m.def("RS_Renderer_DrawToneMappingCurvesAndSaveToFile", &RS_Renderer_DrawToneMappingCurvesAndSaveToFile);

	m.def("RS_Renderer_GetTextRenderer", &RS_Renderer_GetTextRenderer, py::return_value_policy::reference);
	m.def("RS_Renderer_GetCurrentCamera", &RS_Renderer_GetCurrentCamera, py::return_value_policy::reference);
	m.def("RS_Renderer_GetCurrentScene", &RS_Renderer_GetCurrentScene, py::return_value_policy::reference);
	m.def("RS_Renderer_DebugLogAllResources", &RS_Renderer_DebugLogAllResources);
	m.def("RS_Renderer_ShouldSkipRenderingStage", &RS_Renderer_ShouldSkipRenderingStage);
	m.def("RS_Renderer_EnableFastVRAMUpdates", &RS_Renderer_EnableFastVRAMUpdates);
	m.def("RS_Renderer_SetBenchmarkEnabled", &RS_Renderer_SetBenchmarkEnabled);
	m.def("RS_Renderer_GetShaderDebuggingModeEnabled", &RS_Renderer_GetShaderDebuggingModeEnabled);
	m.def("RS_Renderer_FreeStackAllocatorVRAM", &RS_Renderer_FreeStackAllocatorVRAM);
	m.def("RS_Renderer_DisableCUDAShutdownAsserts", &RS_Renderer_DisableCUDAShutdownAsserts);
	m.def("RS_Renderer_ShouldAbort", &RS_Renderer_ShouldAbort);
	m.def("RS_Renderer_CancelRendering", &RS_Renderer_CancelRendering);
	m.def("RS_Renderer_GetCurrentStage", &RS_Renderer_GetCurrentStage);

	py::enum_<RSRendererStage>(m, "RSRendererStage")
		.value("RS_RENDERERSTAGE_PREPARATION", RS_RENDERERSTAGE_PREPARATION)
		.value("RS_RENDERERSTAGE_PHOTON_CASTING", RS_RENDERERSTAGE_PHOTON_CASTING)
		.value("RS_RENDERERSTAGE_IRRADIANCE_POINT_CLOUD", RS_RENDERERSTAGE_IRRADIANCE_POINT_CLOUD)
		.value("RS_RENDERERSTAGE_IRRADIANCE_CACHING", RS_RENDERERSTAGE_IRRADIANCE_CACHING)
		.value("RS_RENDERERSTAGE_SUBSURFACE_SCATTERING", RS_RENDERERSTAGE_SUBSURFACE_SCATTERING)
		.value("RS_RENDERERSTAGE_RENDERING", RS_RENDERERSTAGE_RENDERING)
		.value("RS_RENDERERSTAGE_INVALID", RS_RENDERERSTAGE_INVALID)
		.export_values();

	py::enum_<RSRenderOptionType>(m, "RSRenderOptionType")
		.value("RS_RENDEROPTIONTYPE_BOOL", RS_RENDEROPTIONTYPE_BOOL)
		.value("RS_RENDEROPTIONTYPE_UINT", RS_RENDEROPTIONTYPE_UINT)
		.value("RS_RENDEROPTIONTYPE_INT", RS_RENDEROPTIONTYPE_INT)
		.value("RS_RENDEROPTIONTYPE_FLOAT", RS_RENDEROPTIONTYPE_FLOAT)
		.value("RS_RENDEROPTIONTYPE_VECTOR2", RS_RENDEROPTIONTYPE_VECTOR2)
		.value("RS_RENDEROPTIONTYPE_VECTOR3", RS_RENDEROPTIONTYPE_VECTOR3)
		.value("RS_RENDEROPTIONTYPE_VECTOR4", RS_RENDEROPTIONTYPE_VECTOR4)
		.value("RS_RENDEROPTIONTYPE_STRING", RS_RENDEROPTIONTYPE_STRING)
		.value("RS_RENDEROPTIONTYPE_INVALID", RS_RENDEROPTIONTYPE_INVALID)
		.export_values();

	m.def("RS_RenderOption_AssertOrWarnIfOptionNotFound", &RS_RenderOption_AssertOrWarnIfOptionNotFound);
	m.def("RS_RenderOption_ResetAllToDefaults", &RS_RenderOption_ResetAllToDefaults);
	m.def("RS_RenderOption_Validate", &RS_RenderOption_Validate);


	py::class_<RSRenderOptions>(m, "RSRenderOptions")
		.def("ResetAllToDefaults", &RSRenderOptions::ResetAllToDefaults)
		.def("Validate", &RSRenderOptions::Validate)
		.def("Hash", &RSRenderOptions::Hash)
		.def("Exists", &RSRenderOptions::Exists)
		.def("GetType", &RSRenderOptions::GetType)
		.def("IsEnum", &RSRenderOptions::IsEnum)
		.def("GetNumEntriesForEnum", &RSRenderOptions::GetNumEntriesForEnum)
		.def("GetEntryForEnum", &RSRenderOptions::GetEntryForEnum)
		.def("GetPrettyNameForEnum", &RSRenderOptions::GetPrettyNameForEnum)
		.def("GetBool", &RSRenderOptions::GetBool)
		.def("SetBool", &RSRenderOptions::SetBool)
		.def("GetInt", &RSRenderOptions::GetInt)
		.def("SetInt", &RSRenderOptions::SetInt)
		.def("GetUInt", &RSRenderOptions::GetUInt)
		.def("SetUInt", &RSRenderOptions::SetUInt)
		.def("GetFloat", &RSRenderOptions::GetFloat)
		.def("SetFloat", &RSRenderOptions::SetFloat)
		.def("GetVector2", &RSRenderOptions::GetVector2)
		.def("SetVector2", &RSRenderOptions::SetVector2)
		.def("GetVector3", &RSRenderOptions::GetVector3)
		.def("SetVector3", &RSRenderOptions::SetVector3)
		.def("GetVector4", &RSRenderOptions::GetVector4)
		.def("SetVector4", &RSRenderOptions::SetVector4)
		.def("GetString", &RSRenderOptions::GetString)
		.def("SetString", &RSRenderOptions::SetString)
		.def("SetNumIrradiancePointCloudAdditionalFilenames", &RSRenderOptions::SetNumIrradiancePointCloudAdditionalFilenames)
		.def("GetNumIrradiancePointCloudAdditionalFilenames", &RSRenderOptions::GetNumIrradiancePointCloudAdditionalFilenames)
		.def("SetIrradiancePointCloudAdditionalFilename", &RSRenderOptions::SetIrradiancePointCloudAdditionalFilename)
		.def("GetIrradiancePointCloudAdditionalFilename", &RSRenderOptions::GetIrradiancePointCloudAdditionalFilename)
		.def("SetNumIrradianceCacheAdditionalFilenames", &RSRenderOptions::SetNumIrradianceCacheAdditionalFilenames)
		.def("GetNumIrradianceCacheAdditionalFilenames", &RSRenderOptions::GetNumIrradianceCacheAdditionalFilenames)
		.def("SetIrradianceCacheAdditionalFilename", &RSRenderOptions::SetIrradianceCacheAdditionalFilename)
		.def("GetIrradianceCacheAdditionalFilename", &RSRenderOptions::GetIrradianceCacheAdditionalFilename)
		.def("ReplacePointBasedTechniqueFilePaths", &RSRenderOptions::ReplacePointBasedTechniqueFilePaths)
		.def("SetMotionBlurEfficiencyLookupTable", &RSRenderOptions::SetMotionBlurEfficiencyLookupTable)
		.def("GetMotionBlurEfficiencyLookupTable", &RSRenderOptions::GetMotionBlurEfficiencyLookupTable)
		.def("CopyFrom", &RSRenderOptions::CopyFrom);


	m.def("RS_RenderOption_New", &RS_RenderOption_New, py::return_value_policy::reference);
	m.def("RS_RenderOption_Delete", &RS_RenderOption_Delete);
	m.def("RS_RenderOption_SetCurrentFromObject", &RS_RenderOption_SetCurrentFromObject);
	m.def("RS_RenderOption_GetCurrentIntoObject", &RS_RenderOption_GetCurrentIntoObject);
	m.def("RS_RenderOption_Exists", &RS_RenderOption_Exists);
	m.def("RS_RenderOption_GetNumAvailableOptions", &RS_RenderOption_GetNumAvailableOptions);
	m.def("RS_RenderOption_GetOptionName", &RS_RenderOption_GetOptionName);
	m.def("RS_RenderOption_IsEnum", &RS_RenderOption_IsEnum);
	m.def("RS_RenderOption_GetNumEntriesForEnum", &RS_RenderOption_GetNumEntriesForEnum);
	m.def("RS_RenderOption_GetEntryForEnum", &RS_RenderOption_GetEntryForEnum);
	m.def("RS_RenderOption_GetPrettyNameForEnum", &RS_RenderOption_GetPrettyNameForEnum);
	m.def("RS_RenderOption_GetType", &RS_RenderOption_GetType);
	m.def("RS_RenderOption_GetTypeAsString", &RS_RenderOption_GetTypeAsString);


	m.def("RS_RenderOption_GetBool", &RS_RenderOption_GetBool);
	m.def("RS_RenderOption_SetBool", &RS_RenderOption_SetBool);
	m.def("RS_RenderOption_GetInt", &RS_RenderOption_GetInt);
	m.def("RS_RenderOption_SetInt", &RS_RenderOption_SetInt);
	m.def("RS_RenderOption_GetUInt", &RS_RenderOption_GetUInt);
	m.def("RS_RenderOption_SetUInt", &RS_RenderOption_SetUInt);
	m.def("RS_RenderOption_GetFloat", &RS_RenderOption_GetFloat);
	m.def("RS_RenderOption_SetFloat", &RS_RenderOption_SetFloat);
	m.def("RS_RenderOption_GetVector2", &RS_RenderOption_GetVector2);
	m.def("RS_RenderOption_SetVector2", &RS_RenderOption_SetVector2);
	m.def("RS_RenderOption_GetVector3", &RS_RenderOption_GetVector3);
	m.def("RS_RenderOption_SetVector3", &RS_RenderOption_SetVector3);
	m.def("RS_RenderOption_GetVector4", &RS_RenderOption_GetVector4);
	m.def("RS_RenderOption_SetVector4", &RS_RenderOption_SetVector4);
	m.def("RS_RenderOption_GetString", &RS_RenderOption_GetString);
	m.def("RS_RenderOption_SetNumIrradiancePointCloudAdditionalFilenames", &RS_RenderOption_SetNumIrradiancePointCloudAdditionalFilenames);
	m.def("RS_RenderOption_GetNumIrradiancePointCloudAdditionalFilenames", &RS_RenderOption_GetNumIrradiancePointCloudAdditionalFilenames);
	m.def("RS_RenderOption_SetIrradiancePointCloudAdditionalFilename", &RS_RenderOption_SetIrradiancePointCloudAdditionalFilename);
	m.def("RS_RenderOption_GetIrradiancePointCloudAdditionalFilename", &RS_RenderOption_GetIrradiancePointCloudAdditionalFilename);
	m.def("RS_RenderOption_SetNumIrradianceCacheAdditionalFilenames", &RS_RenderOption_SetNumIrradianceCacheAdditionalFilenames);
	m.def("RS_RenderOption_GetNumIrradianceCacheAdditionalFilenames", &RS_RenderOption_GetNumIrradianceCacheAdditionalFilenames);
	m.def("RS_RenderOption_SetIrradianceCacheAdditionalFilename", &RS_RenderOption_SetIrradianceCacheAdditionalFilename);
	m.def("RS_RenderOption_GetIrradianceCacheAdditionalFilename", &RS_RenderOption_GetIrradianceCacheAdditionalFilename);
	m.def("RS_RenderOption_ReplacePointBasedTechniqueFilePaths", &RS_RenderOption_ReplacePointBasedTechniqueFilePaths);

	m.def("RS_RenderOption_SetMotionBlurEfficiencyLookupTable", &RS_RenderOption_SetMotionBlurEfficiencyLookupTable);
	m.def("RS_RenderOption_GetMotionBlurEfficiencyLookupTable", &RS_RenderOption_GetMotionBlurEfficiencyLookupTable);
	m.def("RS_RenderOption_GetDefaultBool", &RS_RenderOption_GetDefaultBool);
	m.def("RS_RenderOption_GetDefaultInt", &RS_RenderOption_GetDefaultInt);
	m.def("RS_RenderOption_GetDefaultUInt", &RS_RenderOption_GetDefaultUInt);
	m.def("RS_RenderOption_GetDefaultFloat", &RS_RenderOption_GetDefaultFloat);
	m.def("RS_RenderOption_GetDefaultVector2", &RS_RenderOption_GetDefaultVector2);
	m.def("RS_RenderOption_GetDefaultVector3", &RS_RenderOption_GetDefaultVector3);
	m.def("RS_RenderOption_GetDefaultVector4", &RS_RenderOption_GetDefaultVector4);
	m.def("RS_RenderOption_GetDefaultString", &RS_RenderOption_GetDefaultString);
	m.def("RS_RenderOption_GetMinMaxInt", &RS_RenderOption_GetMinMaxInt);
	m.def("RS_RenderOption_GetMinMaxUInt", &RS_RenderOption_GetMinMaxUInt);
	m.def("RS_RenderOption_GetMinMaxFloat", &RS_RenderOption_GetMinMaxFloat);
	m.def("RS_DEBUG_DumpErrorCallstack", &RS_DEBUG_DumpErrorCallstack);
	m.def("RS_DEBUG_WriteMiniDump", &RS_DEBUG_WriteMiniDump);

	m.def("start_redshift", &start_redshift,py::arg("showLog") = true);
	m.def("end_redshift", &end_redshift);
}
