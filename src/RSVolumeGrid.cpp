#include "RSHead.h"
namespace py = pybind11;

void bindRSVolumeGrid(py::module&m)
{
	py::class_<RSVolumeGrid>(m, "RSVolumeGrid")
		.def("GetName", &RSVolumeGrid::GetName)
		.def("GetMatrix", py::overload_cast<>(&RSVolumeGrid::GetMatrix, py::const_))
		.def("GetMatrix", py::overload_cast<unsigned int>(&RSVolumeGrid::GetMatrix, py::const_))
		.def("SetName", &RSVolumeGrid::SetName)
		.def("GetFriendlyName", &RSVolumeGrid::GetFriendlyName)
		.def("SetFriendlyName", &RSVolumeGrid::SetFriendlyName)
		.def("SetIsTransformationBlurred", &RSVolumeGrid::SetIsTransformationBlurred)
		.def("IsTransformationBlurred", &RSVolumeGrid::IsTransformationBlurred)
		.def("GetFlag", &RSVolumeGrid::GetFlag)
		.def("SetFlag", &RSVolumeGrid::SetFlag)
		.def("GetCachedMeshFlags", &RSVolumeGrid::GetCachedMeshFlags)
		.def("SetCachedMeshFlags", &RSVolumeGrid::SetCachedMeshFlags)
		.def("GetNumTransformationSteps", &RSVolumeGrid::GetNumTransformationSteps)
		.def("SetMatrix", &RSVolumeGrid::SetMatrix)
		.def("SetMaterial", &RSVolumeGrid::SetMaterial)
		.def("GetMaterial", &RSVolumeGrid::GetMaterial, py::return_value_policy::reference)
		.def("GetMatteInfo", &RSVolumeGrid::GetMatteInfo)
		.def("SetMatteInfo", &RSVolumeGrid::SetMatteInfo)
		.def("SetInternalTransform", &RSVolumeGrid::SetInternalTransform)
		.def("GetInternalTransform", &RSVolumeGrid::GetInternalTransform)
		.def("SetVelocityGridNames", &RSVolumeGrid::SetVelocityGridNames)
		.def("GetVelocityGridNames", &RSVolumeGrid::GetVelocityGridNames)
		.def("SetMotionBlurScale", &RSVolumeGrid::SetMotionBlurScale)
		.def("GetMotionBlurScale", &RSVolumeGrid::GetMotionBlurScale)
		.def("SetMotionBlurTimeOffset", &RSVolumeGrid::SetMotionBlurTimeOffset)
		.def("GetMotionBlurTimeOffset", &RSVolumeGrid::GetMotionBlurTimeOffset)
		.def("SetMotionBlurUseGlobalOptions", &RSVolumeGrid::SetMotionBlurUseGlobalOptions)
		.def("GetMotionBlurUseGlobalOptions", &RSVolumeGrid::GetMotionBlurUseGlobalOptions)
		.def("SetMotionBlurComputeInVoxelSpace", &RSVolumeGrid::SetMotionBlurComputeInVoxelSpace)
		.def("GetMotionBlurComputeInVoxelSpace", &RSVolumeGrid::GetMotionBlurComputeInVoxelSpace)
		.def("GetOpenVDBFilenameAbsolute", &RSVolumeGrid::GetOpenVDBFilenameAbsolute)
		.def("SetOpenVDBFilename", &RSVolumeGrid::SetOpenVDBFilename)
		.def("BeginAddingVoxels", &RSVolumeGrid::BeginAddingVoxels)
		.def("SetVoxels", &RSVolumeGrid::SetVoxels)
		.def("EndAddingVoxels", &RSVolumeGrid::EndAddingVoxels)
		.def("InstantiateFrom", &RSVolumeGrid::InstantiateFrom);

	m.def("RS_VolumeGrid_New", &RS_VolumeGrid_New, py::return_value_policy::reference);
	m.def("RS_VolumeGrid_Delete", &RS_VolumeGrid_Delete);

	py::class_<RSVolumeGridPreviewData>(m, "RSVolumeGridPreviewData")
		.def("GetAABBMinCorner", &RSVolumeGridPreviewData::GetAABBMinCorner)
		.def("GetAABBMaxCorner", &RSVolumeGridPreviewData::GetAABBMaxCorner)
		.def("GetVoxelMinCorner", &RSVolumeGridPreviewData::GetVoxelMinCorner)
		.def("GetVoxelMaxCorner", &RSVolumeGridPreviewData::GetVoxelMaxCorner)
		.def("GetInternalTransform", &RSVolumeGridPreviewData::GetInternalTransform)
		.def("GetPointPositions", &RSVolumeGridPreviewData::GetPointPositions)
		.def("GetGridNames", &RSVolumeGridPreviewData::GetGridNames);




	m.def("RS_VolumeGridPreviewData_LoadFromFile", &RS_VolumeGridPreviewData_LoadFromFile, py::return_value_policy::reference);
	m.def("RS_VolumeGridPreviewData_Delete", &RS_VolumeGridPreviewData_Delete);
}
