#include "RSHead.h"
namespace py = pybind11;

void bindRSRenderChannels(py::module&m)
{
	py::enum_<RSBlockSinkFileMetadataType>(m, "RSBlockSinkFileMetadataType")
		.value("MetadataType_string", MetadataType_string)
		.value("MetadataType_int", MetadataType_int)
		.value("MetadataType_float", MetadataType_float)
		.value("MetadataType_vector2", MetadataType_vector2)
		.value("MetadataType_vector3", MetadataType_vector3)
		.value("MetadataType_vector4", MetadataType_vector4)
		.value("MetadataType_matrix4x4", MetadataType_matrix4x4)
		.value("MetadataType_matrix3x3", MetadataType_matrix3x3)
		.value("MetadataType_invalid", MetadataType_invalid)
		.export_values();

	py::class_<RSBlockSinkMetadataEntry>(m, "RSBlockSinkMetadataEntry")
		.def(py::init<const char* , const char*>())
		.def(py::init<const char*, float>())
		.def(py::init<const char*, const RSVector2&>())
		.def(py::init<const char*, const RSVector3&>())
		.def(py::init<const char*, const RSVector4&>())
		.def(py::init<const char*, const RSMatrix3x3&>())
		.def(py::init<const char*, const RSMatrix4x4&>())
		.def_readwrite("name", &RSBlockSinkMetadataEntry::name)
		.def_readwrite("type", &RSBlockSinkMetadataEntry::type)
		.def_readwrite("stringVal", &RSBlockSinkMetadataEntry::stringVal)
		.def_readwrite("intVal", &RSBlockSinkMetadataEntry::intVal)
		.def_readwrite("floatVal", &RSBlockSinkMetadataEntry::floatVal)
		.def_readwrite("vector2Val", &RSBlockSinkMetadataEntry::vector2Val)
		.def_readwrite("vector3Val", &RSBlockSinkMetadataEntry::vector3Val)
		.def_readwrite("vector4Val", &RSBlockSinkMetadataEntry::vector4Val)
		.def_readwrite("matrix4x4Val", &RSBlockSinkMetadataEntry::matrix4x4Val)
		.def_readwrite("matrix3x3Val", &RSBlockSinkMetadataEntry::matrix3x3Val);
		
	py::class_<RSBlockSink>(m, "RSBlockSink")
		.def("GetClassIdentifier", &RSBlockSink::GetClassIdentifier)
		.def("IsDisplaySink", &RSBlockSink::IsDisplaySink)
		.def("IsFileBlockSink", &RSBlockSink::IsFileBlockSink)
		.def("IsDeep", &RSBlockSink::IsDeep)
		.def("NeedsSamples", &RSBlockSink::NeedsSamples)
		.def("NeedsDeepSamples", &RSBlockSink::NeedsDeepSamples)
		.def("NotifyWillRenderBlock", &RSBlockSink::NotifyWillRenderBlock)
		.def("PreRender", &RSBlockSink::PreRender)
		.def("PostRender", &RSBlockSink::PostRender)
		.def("SetMetadata", &RSBlockSink::SetMetadata)
		.def("SetPreviewPassthroughBlockSink", &RSBlockSink::SetPreviewPassthroughBlockSink)
		.def("OutputSamples", &RSBlockSink::OutputSamples)
		.def("OutputDeepSamples", &RSBlockSink::OutputDeepSamples)
		.def("OutputBlock", &RSBlockSink::OutputBlock)
		.def("OutputDeepBlock", &RSBlockSink::OutputDeepBlock)
		.def("SaveToStream", &RSBlockSink::SaveToStream)
		.def("LoadFromStream", &RSBlockSink::LoadFromStream)
		.def("GetFilename", &RSBlockSink::GetFilename)
		.def("SetFilename", &RSBlockSink::SetFilename)
		.def("GetWidth", &RSBlockSink::GetWidth)
		.def("GetHeight", &RSBlockSink::GetHeight)
		.def("ChangeWidthHeight", &RSBlockSink::ChangeWidthHeight)
		.def("LayerParticipatesInAutoCrop", &RSBlockSink::LayerParticipatesInAutoCrop)
		.def("Dilate", &RSBlockSink::Dilate)
		.def("GetParentRenderChannel", &RSBlockSink::GetParentRenderChannel, py::return_value_policy::reference)
		.def("_SetParentRenderChannel", &RSBlockSink::_SetParentRenderChannel)
		.def("Save", &RSBlockSink::Save)
		.def("SaveTiled", &RSBlockSink::SaveTiled);


	py::class_<RSBlockSinkSamples>(m, "RSBlockSinkSamples")
		.def("GetNumEntries", &RSBlockSinkSamples::GetNumEntries)
		.def("GetEntryPixelCoordinates", &RSBlockSinkSamples::GetEntryPixelCoordinates)
		.def("GetEntryOffset", &RSBlockSinkSamples::GetEntryOffset)
		.def("GetEntryNumSamples", &RSBlockSinkSamples::GetEntryNumSamples)
		.def("GetEntrySamples", &RSBlockSinkSamples::GetEntrySamples)
		.def("ComputeEntryFloatCoords", &RSBlockSinkSamples::ComputeEntryFloatCoords)
		.def("GetStride", &RSBlockSinkSamples::GetStride)
		.def("GetNumSamples", &RSBlockSinkSamples::GetNumSamples)
		.def("GetAllSamples", &RSBlockSinkSamples::GetAllSamples);

	py::class_<RSBlockSinkDeepSamples>(m, "RSBlockSinkDeepSamples")
		.def("GetNumEntries", &RSBlockSinkDeepSamples::GetNumEntries)
		.def("GetEntryPixelCoordinates", &RSBlockSinkDeepSamples::GetEntryPixelCoordinates)
		.def("GetEntryNeighbor", &RSBlockSinkDeepSamples::GetEntryNeighbor)
		.def("GetNumChainsInEntry", &RSBlockSinkDeepSamples::GetNumChainsInEntry)
		.def("GetEntryChainSampleOffset", &RSBlockSinkDeepSamples::GetEntryChainSampleOffset)
		.def("ComputeEntryFloatCoords", &RSBlockSinkDeepSamples::ComputeEntryFloatCoords)
		.def("GetEntryChainSampleCount", &RSBlockSinkDeepSamples::GetEntryChainSampleCount)
		.def("ComputeEntryFloatCoords", &RSBlockSinkDeepSamples::ComputeEntryFloatCoords)
		.def("GetNumSamples", &RSBlockSinkDeepSamples::GetNumSamples)
		.def("GetSortedFilteredsamplesForEntry", &RSBlockSinkDeepSamples::GetSortedFilteredsamplesForEntry);


	py::class_<RSBlockSinkFileFormatInfo>(m, "RSBlockSinkFileFormatInfo")
		.def(py::init<>())
		.def_readwrite("exrIsTiled", &RSBlockSinkFileFormatInfo::exrIsTiled)
		.def_readwrite("exrCompression", &RSBlockSinkFileFormatInfo::exrCompression)
		.def_readwrite("exrDwaCompressionLevel", &RSBlockSinkFileFormatInfo::exrDwaCompressionLevel)
		.def_readwrite("tiffIsTiled", &RSBlockSinkFileFormatInfo::tiffIsTiled)
		.def_readwrite("tiffCompression", &RSBlockSinkFileFormatInfo::tiffCompression)
		.def_readwrite("jpegQuality", &RSBlockSinkFileFormatInfo::jpegQuality);

	py::class_<RSBlockSinkFile, RSBlockSink>(m, "RSBlockSinkFile")
		.def("GetNumLayers", &RSBlockSinkFile::GetNumLayers)
		.def("GetFileFormatInfo", &RSBlockSinkFile::GetFileFormatInfo)
		.def("GetIsDeep", &RSBlockSinkFile::GetIsDeep)
		.def("GetIsMultipart", &RSBlockSinkFile::GetIsMultipart)
		.def("GetLayerGammas", &RSBlockSinkFile::GetLayerGammas)
		.def("GetLayerInternalDataTypes", &RSBlockSinkFile::GetLayerInternalDataTypes)
		.def("GetLayerDataTypes", &RSBlockSinkFile::GetLayerDataTypes)
		.def("GetLayerBitDepths", &RSBlockSinkFile::GetLayerBitDepths)
		.def("GetLayerNames", &RSBlockSinkFile::GetLayerNames)
		.def("GetAutocrop", &RSBlockSinkFile::GetAutocrop)
		.def("GetDenoisePassId", &RSBlockSinkFile::GetDenoisePassId)
		.def("GetFinalImageBuffer", &RSBlockSinkFile::GetFinalImageBuffer);


	py::enum_<RSBlockSinkCryptomatteType>(m, "RSBlockSinkCryptomatteType")
		.value("RS_BLOCKSINKCRYPTOMATTETYPE_MESHID", RS_BLOCKSINKCRYPTOMATTETYPE_MESHID)
		.value("RS_BLOCKSINKCRYPTOMATTETYPE_MATERIALID", RS_BLOCKSINKCRYPTOMATTETYPE_MATERIALID)
		.value("RS_BLOCKSINKCRYPTOMATTETYPE_USEROBJECTID", RS_BLOCKSINKCRYPTOMATTETYPE_USEROBJECTID)
		.value("RS_BLOCKSINKCRYPTOMATTETYPE_MESHIDUSINGFROMTOARRAYS", RS_BLOCKSINKCRYPTOMATTETYPE_MESHIDUSINGFROMTOARRAYS)
		.export_values();

	py::class_<RSBlockSinkCryptomatte, RSBlockSink>(m, "RSBlockSinkCryptomatte")
		.def("GetFromMeshNameArray", &RSBlockSinkCryptomatte::GetFromMeshNameArray)
		.def("GetToAssetNameArray", &RSBlockSinkCryptomatte::GetToAssetNameArray);

	py::class_<RSRenderChannelBase>(m, "RSRenderChannelBase")
		.def("GetType", &RSRenderChannelBase::GetType)
		.def("IsEnabled", &RSRenderChannelBase::IsEnabled)
		.def("SetIsEnabled", &RSRenderChannelBase::SetIsEnabled)
		.def("GetDataType", &RSRenderChannelBase::GetDataType)
		.def("GetBitDepth", &RSRenderChannelBase::GetBitDepth)
		.def("AddBlockSink", &RSRenderChannelBase::AddBlockSink)
		.def("SetNumBlockSinks", &RSRenderChannelBase::SetNumBlockSinks)
		.def("GetNumBlockSinks", &RSRenderChannelBase::GetNumBlockSinks)
		.def("SetBlockSink", &RSRenderChannelBase::SetBlockSink)
		.def("GetBlockSink", &RSRenderChannelBase::GetBlockSink, py::return_value_policy::reference)
		.def("GetBlockSinkLayerID", &RSRenderChannelBase::GetBlockSinkLayerID)
		.def("GetChannelName", &RSRenderChannelBase::GetChannelName)
		.def("SetChannelName", &RSRenderChannelBase::SetChannelName)
		.def("ShouldBeDenoised", &RSRenderChannelBase::ShouldBeDenoised)
		.def("SetShouldBeDenoised", &RSRenderChannelBase::SetShouldBeDenoised);

	py::class_<RSRenderChannelMain, RSRenderChannelBase>(m, "RSRenderChannelMain")
		.def("CopyFrom", &RSRenderChannelMain::CopyFrom);

	py::class_<RSRenderChannelWorld, RSRenderChannelBase>(m, "RSRenderChannelWorld")
		.def("GetFilterMode", &RSRenderChannelWorld::GetFilterMode)
		.def("SetFilterMode", &RSRenderChannelWorld::SetFilterMode)
		.def("GetScale", &RSRenderChannelWorld::GetScale)
		.def("SetScale", &RSRenderChannelWorld::SetScale)
		.def("SetEnvironmentRaysToBlack", &RSRenderChannelWorld::SetEnvironmentRaysToBlack)
		.def("GetEnvironmentRaysAreBlack", &RSRenderChannelWorld::GetEnvironmentRaysAreBlack)
		.def("CopyFrom", &RSRenderChannelWorld::CopyFrom);

	py::class_<RSRenderChannelDepth, RSRenderChannelBase>(m, "RSRenderChannelDepth")
		.def("GetFilterMode", &RSRenderChannelDepth::GetFilterMode)
		.def("SetFilterMode", &RSRenderChannelDepth::SetFilterMode)
		.def("SetDepthMode", &RSRenderChannelDepth::SetDepthMode)
		.def("GetDepthMode", &RSRenderChannelDepth::GetDepthMode)
		.def("GetUseCameraNearFar", &RSRenderChannelDepth::GetUseCameraNearFar)
		.def("SetUseCameraNearFar", &RSRenderChannelDepth::SetUseCameraNearFar)
		.def("GetMinDepth", &RSRenderChannelDepth::GetMinDepth)
		.def("SetMinDepth", &RSRenderChannelDepth::SetMinDepth)
		.def("GetMaxDepth", &RSRenderChannelDepth::GetMaxDepth)
		.def("SetMaxDepth", &RSRenderChannelDepth::SetMaxDepth)
		.def("SetEnvironmentRaysToBlack", &RSRenderChannelDepth::SetEnvironmentRaysToBlack)
		.def("GetEnvironmentRaysAreBlack", &RSRenderChannelDepth::GetEnvironmentRaysAreBlack)
		.def("CopyFrom", &RSRenderChannelDepth::CopyFrom);


	py::class_<RSRenderChannelMotionVector, RSRenderChannelBase>(m, "RSRenderChannelMotionVector")
		.def("GetDoFiltering", &RSRenderChannelMotionVector::GetDoFiltering)
		.def("SetDoFiltering", &RSRenderChannelMotionVector::SetDoFiltering)
		.def("GetOutputRawVectors", &RSRenderChannelMotionVector::GetOutputRawVectors)
		.def("SetOutputRawVectors", &RSRenderChannelMotionVector::SetOutputRawVectors)
		.def("GetNoClamp", &RSRenderChannelMotionVector::GetNoClamp)
		.def("SetNoClamp", &RSRenderChannelMotionVector::SetNoClamp)
		.def("GetMaxMotionInPixels", &RSRenderChannelMotionVector::GetMaxMotionInPixels)
		.def("SetMaxMotionInPixels", &RSRenderChannelMotionVector::SetMaxMotionInPixels)
		.def("GetImageOutputMin", &RSRenderChannelMotionVector::GetImageOutputMin)
		.def("SetImageOutputMin", &RSRenderChannelMotionVector::SetImageOutputMin)
		.def("GetImageOutputMax", &RSRenderChannelMotionVector::GetImageOutputMax)
		.def("SetImageOutputMax", &RSRenderChannelMotionVector::SetImageOutputMax)
		.def("CopyFrom", &RSRenderChannelMotionVector::CopyFrom);


	py::class_<RSRenderChannelPuzzleMatte, RSRenderChannelBase>(m, "RSRenderChannelPuzzleMatte")
		.def("GetMode", &RSRenderChannelPuzzleMatte::GetMode)
		.def("SetMode", &RSRenderChannelPuzzleMatte::SetMode)
		.def("GetRedID", &RSRenderChannelPuzzleMatte::GetRedID)
		.def("SetRedID", &RSRenderChannelPuzzleMatte::SetRedID)
		.def("GetGreenID", &RSRenderChannelPuzzleMatte::GetGreenID)
		.def("SetGreenID", &RSRenderChannelPuzzleMatte::SetGreenID)
		.def("GetBlueID", &RSRenderChannelPuzzleMatte::GetBlueID)
		.def("SetBlueID", &RSRenderChannelPuzzleMatte::SetBlueID)
		.def("GetEnableReflectionRefraction", &RSRenderChannelPuzzleMatte::GetEnableReflectionRefraction)
		.def("SetEnableReflectionRefraction", &RSRenderChannelPuzzleMatte::SetEnableReflectionRefraction)
		.def("CopyFrom", &RSRenderChannelPuzzleMatte::CopyFrom);

	py::class_<RSRenderChannelObjectID, RSRenderChannelBase>(m, "RSRenderChannelObjectID")
		.def("GetScale", &RSRenderChannelObjectID::GetScale)
		.def("SetScale", &RSRenderChannelObjectID::SetScale)
		.def("CopyFrom", &RSRenderChannelObjectID::CopyFrom);

	py::class_<RSRenderChannelRVMeshID, RSRenderChannelBase>(m, "RSRenderChannelRVMeshID")
		.def("CopyFrom", &RSRenderChannelRVMeshID::CopyFrom);

	py::class_<RSRenderChannelRVMaterialID, RSRenderChannelBase>(m, "RSRenderChannelRVMaterialID")
		.def("CopyFrom", &RSRenderChannelRVMaterialID::CopyFrom);

	py::class_<RSRenderChannelMaterialAOV, RSRenderChannelBase>(m, "RSRenderChannelMaterialAOV")
		.def("SetType", &RSRenderChannelMaterialAOV::SetType)
		.def("GetDataType", &RSRenderChannelMaterialAOV::GetDataType)
		.def("GetEnableColorProcessing", &RSRenderChannelMaterialAOV::GetEnableColorProcessing)
		.def("SetEnableColorProcessing", &RSRenderChannelMaterialAOV::SetEnableColorProcessing)
		.def("GetPassShaderGraph", &RSRenderChannelMaterialAOV::GetPassShaderGraph, py::return_value_policy::reference)
		.def("SetPassShaderGraph", &RSRenderChannelMaterialAOV::SetPassShaderGraph)
		.def("SetLightGroupName", &RSRenderChannelMaterialAOV::SetLightGroupName)
		.def("SetSecondaryRayVisibility", &RSRenderChannelMaterialAOV::SetSecondaryRayVisibility)
		.def("SetEnvironmentRaysToBlack", &RSRenderChannelMaterialAOV::SetEnvironmentRaysToBlack)
		.def("GetEnvironmentRaysAreBlack", &RSRenderChannelMaterialAOV::GetEnvironmentRaysAreBlack)
		.def("CopyFrom", &RSRenderChannelMaterialAOV::CopyFrom);

	m.def("RS_BlockSinkFile_New", &RS_BlockSinkFile_New, py::return_value_policy::reference);
	m.def("RS_BlockSinkFile_Delete", &RS_BlockSinkFile_Delete);
	m.def("RS_BlockSinkCryptomatte_New", &RS_BlockSinkCryptomatte_New, py::return_value_policy::reference);
	m.def("RS_BlockSinkCryptomatte_Delete", &RS_BlockSinkCryptomatte_Delete);
	m.def("RS_RenderChannel_Main_New", &RS_RenderChannel_Main_New, py::return_value_policy::reference);
	m.def("RS_RenderChannel_Main_Delete", &RS_RenderChannel_Main_Delete);
	m.def("RS_RenderChannel_World_New", &RS_RenderChannel_World_New, py::return_value_policy::reference);
	m.def("RS_RenderChannel_World_Delete", &RS_RenderChannel_World_Delete);
	m.def("RS_RenderChannel_Depth_New", &RS_RenderChannel_Depth_New, py::return_value_policy::reference);
	m.def("RS_RenderChannel_Depth_Delete", &RS_RenderChannel_Depth_Delete);
	m.def("RS_RenderChannel_MotionVector_New", &RS_RenderChannel_MotionVector_New, py::return_value_policy::reference);
	m.def("RS_RenderChannel_MotionVector_Delete", &RS_RenderChannel_MotionVector_Delete);
	m.def("RS_RenderChannel_PuzzleMatte_New", &RS_RenderChannel_PuzzleMatte_New, py::return_value_policy::reference);
	m.def("RS_RenderChannel_PuzzleMatte_Delete", &RS_RenderChannel_PuzzleMatte_Delete);
	m.def("RS_RenderChannel_ObjectID_New", &RS_RenderChannel_ObjectID_New, py::return_value_policy::reference);
	m.def("RS_RenderChannel_ObjectID_Delete", &RS_RenderChannel_ObjectID_Delete);
	m.def("RS_RenderChannel_RVMeshID_New", &RS_RenderChannel_RVMeshID_New, py::return_value_policy::reference);
	m.def("RS_RenderChannel_RVMeshID_Delete", &RS_RenderChannel_RVMeshID_Delete);
	m.def("RS_RenderChannel_RVMaterialID_New", &RS_RenderChannel_RVMaterialID_New, py::return_value_policy::reference);
	m.def("RS_RenderChannel_RVMaterialID_Delete", &RS_RenderChannel_RVMaterialID_Delete);
	m.def("RS_RenderChannel_MaterialAOV_New", &RS_RenderChannel_MaterialAOV_New, py::return_value_policy::reference);
	m.def("RS_RenderChannel_MaterialAOV_Delete", &RS_RenderChannel_MaterialAOV_Delete);

	m.def("RS_RenderChannel_ResetAll", &RS_RenderChannel_ResetAll);
	m.def("RS_RenderChannel_MaterialAOVCanApplyColorProcessing", &RS_RenderChannel_MaterialAOVCanApplyColorProcessing);
	m.def("RS_RenderChannel_MaterialAOVBytesPerPixel", &RS_RenderChannel_MaterialAOVBytesPerPixel);
	m.def("RS_RenderChannel_MaterialAOVSupportsLightGroups", &RS_RenderChannel_MaterialAOVSupportsLightGroups);
	m.def("RS_RenderChannel_MaterialAOVSupportsSettingEnvironmentRaysToBlack", &RS_RenderChannel_MaterialAOVSupportsSettingEnvironmentRaysToBlack);
	m.def("RS_RenderChannel_MaterialAOVSupportsSecondaryRayVisibility", &RS_RenderChannel_MaterialAOVSupportsSecondaryRayVisibility);
	
	m.def("RS_RenderChannel_GetMain", &RS_RenderChannel_GetMain, py::return_value_policy::reference);
	m.def("RS_RenderChannel_SetMain", &RS_RenderChannel_SetMain);
	m.def("RS_RenderChannel_GetWorld", &RS_RenderChannel_GetWorld, py::return_value_policy::reference);
	m.def("RS_RenderChannel_SetWorld", &RS_RenderChannel_SetWorld);
	m.def("RS_RenderChannel_GetDepth", &RS_RenderChannel_GetDepth, py::return_value_policy::reference);
	m.def("RS_RenderChannel_SetDepth", &RS_RenderChannel_SetDepth);
	m.def("RS_RenderChannel_GetMotionVector", &RS_RenderChannel_GetMotionVector, py::return_value_policy::reference);
	m.def("RS_RenderChannel_SetMotionVector", &RS_RenderChannel_SetMotionVector);

	m.def("RS_RenderChannel_SetNumPuzzleMattes", &RS_RenderChannel_SetNumPuzzleMattes);
	m.def("RS_RenderChannel_SetNumPuzzleMattes", &RS_RenderChannel_SetNumPuzzleMattes);

	m.def("RS_RenderChannel_GetPuzzleMatte", &RS_RenderChannel_GetPuzzleMatte, py::return_value_policy::reference);
	m.def("RS_RenderChannel_SetPuzzleMatte", &RS_RenderChannel_SetPuzzleMatte);
	m.def("RS_RenderChannel_GetObjectID", &RS_RenderChannel_GetObjectID, py::return_value_policy::reference);
	m.def("RS_RenderChannel_SetObjectID", &RS_RenderChannel_SetObjectID);
	m.def("RS_RenderChannel_GetRVMeshID", &RS_RenderChannel_GetRVMeshID, py::return_value_policy::reference);
	m.def("RS_RenderChannel_SetRVMeshID", &RS_RenderChannel_SetRVMeshID);

	m.def("RS_RenderChannel_GetRVMaterialID", &RS_RenderChannel_GetRVMaterialID, py::return_value_policy::reference);
	m.def("RS_RenderChannel_SetRVMaterialID", &RS_RenderChannel_SetRVMaterialID);

	m.def("RS_RenderChannel_SetNumMaterialAOVs", &RS_RenderChannel_SetNumMaterialAOVs);
	m.def("RS_RenderChannel_GetNumMaterialAOVs", &RS_RenderChannel_GetNumMaterialAOVs);

	m.def("RS_RenderChannel_GetMaterialAOV", &RS_RenderChannel_GetMaterialAOV, py::return_value_policy::reference);
	m.def("RS_RenderChannel_SetMaterialAOV", &RS_RenderChannel_SetMaterialAOV);

	m.def("RS_RenderChannel_GetAllBlockSinksOfAllRenderChannels", &RS_RenderChannel_GetAllBlockSinksOfAllRenderChannels);
}
