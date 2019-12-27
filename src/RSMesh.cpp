#include "RSHead.h"
namespace py = pybind11;

void bindRSRSMesh(py::module&m)
{



	m.def("RS_CachedMeshFlag_GetDefault", &RS_CachedMeshFlag_GetDefault);
	m.def("RS_CachedMeshFlag_Set", &RS_CachedMeshFlag_Set);
	m.def("RS_CachedMeshFlag_Get", &RS_CachedMeshFlag_Get);

	py::class_<RSMatteInfo, std::unique_ptr<RSMatteInfo, py::nodelete>>(m, "RSMatteInfo")
		.def("SetShowBackground", &RSMatteInfo::SetShowBackground)
		.def("GetShowBackground", &RSMatteInfo::GetShowBackground)
		.def("SetAffectedByMatteLights", &RSMatteInfo::SetAffectedByMatteLights)
		.def("GetAffectedByMatteLights", &RSMatteInfo::GetAffectedByMatteLights)
		.def("SetShadowEnable", &RSMatteInfo::SetShadowEnable)
		.def("GetShadowEnable", &RSMatteInfo::GetShadowEnable)
		.def("SetShadowColor", &RSMatteInfo::SetShadowColor)
		.def("GetShadowColor", &RSMatteInfo::GetShadowColor)
		.def("SetShadowTransparency", &RSMatteInfo::SetShadowTransparency)
		.def("GetShadowTransparency", &RSMatteInfo::GetShadowTransparency)
		.def("SetShadowAffectsAlphaEnable", &RSMatteInfo::SetShadowAffectsAlphaEnable)
		.def("GetShadowAffectsAlphaEnable", &RSMatteInfo::GetShadowAffectsAlphaEnable)
		.def("SetAlpha", &RSMatteInfo::SetAlpha)
		.def("GetAlpha", &RSMatteInfo::GetAlpha)
		.def("SetReflectionScale", &RSMatteInfo::SetReflectionScale)
		.def("GetReflectionScale", &RSMatteInfo::GetReflectionScale)
		.def("SetRefractionScale", &RSMatteInfo::SetRefractionScale)
		.def("GetRefractionScale", &RSMatteInfo::GetRefractionScale)
		.def("SetDiffuseScale", &RSMatteInfo::SetDiffuseScale)
		.def("GetDiffuseScale", &RSMatteInfo::GetDiffuseScale)
		.def("CopySettingsFrom", &RSMatteInfo::CopySettingsFrom)
		.def("SetEnable", &RSMatteInfo::SetEnable)
		.def("GetEnabled", &RSMatteInfo::GetEnabled)
		.def("GetEnabledForSecondaryRays", &RSMatteInfo::GetEnabledForSecondaryRays)
		.def("SetReceiveShadowsFromMattesEnable", &RSMatteInfo::SetReceiveShadowsFromMattesEnable)
		.def("GetReceiveShadowsFromMattesEnable", &RSMatteInfo::GetReceiveShadowsFromMattesEnable)
		.def("SetIncludeInPuzzleMatte", &RSMatteInfo::SetIncludeInPuzzleMatte)
		.def("GetIncludeInPuzzleMatte", &RSMatteInfo::GetIncludeInPuzzleMatte)
		.def("SetSecondaryRayReflectionEnabled", &RSMatteInfo::SetSecondaryRayReflectionEnabled)
		.def("GetSecondaryRayReflectionEnabled", &RSMatteInfo::GetSecondaryRayReflectionEnabled)
		.def("SetSecondaryRayRefractionEnabled", &RSMatteInfo::SetSecondaryRayRefractionEnabled)
		.def("GetSecondaryRayRefractionEnabled", &RSMatteInfo::GetSecondaryRayRefractionEnabled)
		.def("SetSecondaryRayDiffuseEnabled", &RSMatteInfo::SetSecondaryRayDiffuseEnabled)
		.def("GetSecondaryRayDiffuseEnabled", &RSMatteInfo::GetSecondaryRayDiffuseEnabled)
		.def("SaveToStream", &RSMatteInfo::SaveToStream)
		.def("LoadFromStream", &RSMatteInfo::LoadFromStream);


	py::class_<RSMeshBase, std::unique_ptr<RSMeshBase, py::nodelete>>(m, "RSMeshBase")
		.def("GetName", &RSMeshBase::GetName)
		.def("SetName", &RSMeshBase::SetName)
		.def("GetFriendlyName", &RSMeshBase::GetFriendlyName)
		.def("SetFriendlyName", &RSMeshBase::SetFriendlyName)
		.def("GetUniqueID", &RSMeshBase::GetUniqueID)
		.def("SetObjectId", &RSMeshBase::SetObjectId)
		.def("GetObjectId", &RSMeshBase::GetObjectId)
		.def("SetIsTransformationBlurred", &RSMeshBase::SetIsTransformationBlurred)
		.def("IsTransformationBlurred", &RSMeshBase::IsTransformationBlurred)
		.def("GetFlag", &RSMeshBase::GetFlag)
		.def("SetFlag", &RSMeshBase::SetFlag)
		.def("GetCachedMeshFlags", &RSMeshBase::GetCachedMeshFlags)
		.def("SetCachedMeshFlags", &RSMeshBase::SetCachedMeshFlags)
		.def("GetNumTransformationSteps", &RSMeshBase::GetNumTransformationSteps)
		.def("SetMatrix", &RSMeshBase::SetMatrix)
		.def("GetMatrix", py::overload_cast<>(&RSMeshBase::GetMatrix, py::const_))
		.def("GetMatrix", py::overload_cast<unsigned int>(&RSMeshBase::GetMatrix, py::const_))
		.def("GetAttributesFormat", &RSMeshBase::GetAttributesFormat, py::return_value_policy::reference)
		.def("SetAttributesFormat", &RSMeshBase::SetAttributesFormat)
		.def("SetNumMaterials", &RSMeshBase::SetNumMaterials)
		.def("GetNumMaterials", &RSMeshBase::GetNumMaterials)
		.def("SetMaterial", &RSMeshBase::SetMaterial)
		.def("GetMaterial", &RSMeshBase::GetMaterial, py::return_value_policy::reference)
		.def("SetMaterials", &RSMeshBase::SetMaterials)
		.def("GetMatteInfo", &RSMeshBase::GetMatteInfo)
		.def("SetMatteInfo", &RSMeshBase::SetMatteInfo)
		.def("SetUserData", &RSMeshBase::SetUserData)
		.def("GetUserData", &RSMeshBase::GetUserData, py::return_value_policy::reference)
		.def("BeginPrimitives", &RSMeshBase::BeginPrimitives)
		.def("SetParentProceduralInfo", &RSMeshBase::SetParentProceduralInfo)
		.def("SetReflectionTraceSet", &RSMeshBase::SetReflectionTraceSet)
		.def("GetReflectionTraceSet", &RSMeshBase::GetReflectionTraceSet, py::return_value_policy::reference)
		.def("SetRefractionTraceSet", &RSMeshBase::SetRefractionTraceSet)
		.def("GetRefractionTraceSet", &RSMeshBase::GetRefractionTraceSet, py::return_value_policy::reference)
		.def("SetSSSTraceSet", &RSMeshBase::SetSSSTraceSet)
		.def("GetSSSTraceSet", &RSMeshBase::GetSSSTraceSet, py::return_value_policy::reference);

	py::class_<RSTessDispInfo>(m, "RSTessDispInfo")
		.def("GetTessellationEnabled", &RSTessDispInfo::GetTessellationEnabled)
		.def("SetTessellationEnabled", &RSTessDispInfo::SetTessellationEnabled)
		.def("GetDisplacementEnabled", &RSTessDispInfo::GetDisplacementEnabled)
		.def("SetDisplacementEnabled", &RSTessDispInfo::SetDisplacementEnabled)
		.def("GetScreenSpaceAdaptive", &RSTessDispInfo::GetScreenSpaceAdaptive)
		.def("SetScreenSpaceAdaptive", &RSTessDispInfo::SetScreenSpaceAdaptive)
		.def("GetDoSmoothSubdivision", &RSTessDispInfo::GetDoSmoothSubdivision)
		.def("SetDoSmoothSubdivision", &RSTessDispInfo::SetDoSmoothSubdivision)
		.def("GetForceCCSS", &RSTessDispInfo::GetForceCCSS)
		.def("SetForceCCSS", &RSTessDispInfo::SetForceCCSS)
		.def("GetMinTessellationLength", &RSTessDispInfo::GetMinTessellationLength)
		.def("SetMinTessellationLength", &RSTessDispInfo::SetMinTessellationLength)
		.def("GetMaxTessellationSubdivs", &RSTessDispInfo::GetMaxTessellationSubdivs)
		.def("SetMaxTessellationSubdivs", &RSTessDispInfo::SetMaxTessellationSubdivs)
		.def("GetOutOfFrustumTessellationFactor", &RSTessDispInfo::GetOutOfFrustumTessellationFactor)
		.def("SetOutOfFrustumTessellationFactor", &RSTessDispInfo::SetOutOfFrustumTessellationFactor)
		.def("GetLimitOutOfFrustumTessellation", &RSTessDispInfo::GetLimitOutOfFrustumTessellation)
		.def("SetLimitOutOfFrustumTessellation", &RSTessDispInfo::SetLimitOutOfFrustumTessellation)
		.def("GetMaxOutOfFrustumTessellationSubdivs", &RSTessDispInfo::GetMaxOutOfFrustumTessellationSubdivs)
		.def("SetMaxOutOfFrustumTessellationSubdivs", &RSTessDispInfo::SetMaxOutOfFrustumTessellationSubdivs)
		.def("GetMaxDisplacement", &RSTessDispInfo::GetMaxDisplacement)
		.def("SetMaxDisplacement", &RSTessDispInfo::SetMaxDisplacement)
		.def("GetDisplacementScale", &RSTessDispInfo::GetDisplacementScale)
		.def("SetForceCCSS", &RSTessDispInfo::SetForceCCSS)
		.def("SetDisplacementScale", &RSTessDispInfo::SetDisplacementScale)
		.def("GetAutoBumpMapEnabled", &RSTessDispInfo::GetAutoBumpMapEnabled)
		.def("SetAutoBumpMapEnabled", &RSTessDispInfo::SetAutoBumpMapEnabled)
		.def("GetStreamIsSmoothed", &RSTessDispInfo::GetStreamIsSmoothed)
		.def("SetStreamIsSmoothed", &RSTessDispInfo::SetStreamIsSmoothed)
		.def("GetDoSmoothUVBoundaries", &RSTessDispInfo::GetDoSmoothUVBoundaries)
		.def("SetDoSmoothUVBoundaries", &RSTessDispInfo::SetDoSmoothUVBoundaries)
		.def("GetHashForExporter", &RSTessDispInfo::GetHashForExporter)
		.def("CopySettingsFrom", &RSTessDispInfo::CopySettingsFrom);

	py::class_<RSMesh, std::unique_ptr<RSMesh, py::nodelete>, RSMeshBase>(m, "RSMesh")
		.def("GetTessDispInfo", &RSMesh::GetTessDispInfo)
		.def("SetTessDispInfo", &RSMesh::SetTessDispInfo)
		.def("AddTri", py::overload_cast<void *, void *, void *, unsigned short>(&RSMesh::AddTri))
		.def("AddTri", py::overload_cast<void *, void *, void *, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned short>(&RSMesh::AddTri))
		.def("AddTri", py::overload_cast<void *, void *, void *, float, float, float, float, float, float, unsigned short>(&RSMesh::AddTri))
		.def("AddQuad", py::overload_cast<void *, void *, void *, void *, unsigned short>(&RSMesh::AddQuad))
		.def("AddQuad", py::overload_cast<void *, void *, void *, void *, float, float, float, float, float, float, float, float, unsigned short>(&RSMesh::AddQuad))
		.def("AddQuad", py::overload_cast<void *, void *, void *, void *, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short>(&RSMesh::AddQuad));

	py::class_<RSMeshHair, std::unique_ptr<RSMeshHair, py::nodelete>, RSMeshBase>(m, "RSMeshHair")
		.def("AddStrand", &RSMeshHair::AddStrand);
	
	py::class_<RSPointCloud, std::unique_ptr<RSPointCloud, py::nodelete>, RSMeshBase>(m, "RSPointCloud")
		.def("SetPrimitiveType", &RSPointCloud::SetPrimitiveType)
		.def("GetPrimitiveType", &RSPointCloud::GetPrimitiveType)
		.def("SetInstanceTemplate", py::overload_cast<RSMeshBase*>(&RSPointCloud::SetInstanceTemplate))
		.def("SetInstanceTemplate", py::overload_cast<RSProxy*>(&RSPointCloud::SetInstanceTemplate))
		.def("GetMaterials", &RSPointCloud::GetMaterials)
		.def("AddPoint", py::overload_cast<const RSVector4&, const void*>(&RSPointCloud::AddPoint))
		.def("AddPoint", py::overload_cast<const RSVector4*, const void*>(&RSPointCloud::AddPoint))
		.def("AddInstance", py::overload_cast<const RSMatrix4x4&, const void*>(&RSPointCloud::AddInstance))
		.def("AddInstance", py::overload_cast<const RSArray<RSMatrix4x4>&, const void*>(&RSPointCloud::AddInstance))
		.def("GetNumPrimitives", &RSPointCloud::GetNumPrimitives);

	py::class_<RSInstanceMaterialOverrides, std::unique_ptr<RSInstanceMaterialOverrides, py::nodelete>>(m, "RSInstanceMaterialOverrides")
		.def("SetTemplate", &RSInstanceMaterialOverrides::SetTemplate)
		.def("GetTemplate", &RSInstanceMaterialOverrides::GetTemplate, py::return_value_policy::reference)
		.def("SetNumMaterials", &RSInstanceMaterialOverrides::SetNumMaterials)
		.def("GetNumMaterials", &RSInstanceMaterialOverrides::GetNumMaterials)
		.def("SetMaterial", &RSInstanceMaterialOverrides::SetMaterial)
		.def("GetMaterial", &RSInstanceMaterialOverrides::GetMaterial, py::return_value_policy::reference);

	py::class_<RSMeshInstance, std::unique_ptr<RSMeshInstance, py::nodelete>>(m, "RSMeshInstance")
		.def("SetTemplate", &RSMeshInstance::SetTemplate)
		.def("SetIsTransformationBlurred", &RSMeshInstance::SetIsTransformationBlurred)
		.def("IsTransformationBlurred", &RSMeshInstance::IsTransformationBlurred)
		.def("SetFlag", &RSMeshInstance::SetFlag)
		.def("GetCachedMeshFlags", &RSMeshInstance::GetCachedMeshFlags)
		.def("SetCachedMeshFlags", &RSMeshInstance::SetCachedMeshFlags)
		.def("GetNumTransformationSteps", &RSMeshInstance::GetNumTransformationSteps)
		.def("SetMatrix", &RSMeshInstance::SetMatrix)
		.def("GetMatrix", py::overload_cast<>(&RSMeshInstance::GetMatrix, py::const_))
		.def("GetMatrix", py::overload_cast<unsigned int>(&RSMeshInstance::GetMatrix, py::const_))
		.def("GetMatteInfo", &RSMeshInstance::GetMatteInfo, py::return_value_policy::reference)
		.def("SetMatteInfo", &RSMeshInstance::SetMatteInfo)
		.def("SetUserData", &RSMeshInstance::SetUserData)
		.def("GetUserData", &RSMeshInstance::GetUserData, py::return_value_policy::reference);


	m.def("RS_Mesh_New", &RS_Mesh_New, py::return_value_policy::reference);
	m.def("RS_Mesh_Delete", &RS_Mesh_Delete);
	m.def("RS_MeshHair_New", &RS_MeshHair_New, py::return_value_policy::reference);
	m.def("RS_MeshHair_Delete", &RS_MeshHair_Delete, py::return_value_policy::reference);
	m.def("RS_MeshBase_Delete", &RS_MeshBase_Delete);
	m.def("RS_MeshInstance_New", &RS_MeshInstance_New, py::return_value_policy::reference);
	m.def("RS_MeshInstance_Delete", &RS_MeshInstance_Delete);
	m.def("RS_InstanceMaterialOverrides_New", &RS_InstanceMaterialOverrides_New, py::return_value_policy::reference);
	m.def("RS_InstanceMaterialOverrides_Delete", &RS_InstanceMaterialOverrides_Delete);
	m.def("RS_PointCloud_New", &RS_PointCloud_New, py::return_value_policy::reference);
	m.def("RS_PointCloud_Delete", &RS_PointCloud_Delete);
	m.def("RS_TessDispInfo_New", &RS_TessDispInfo_New, py::return_value_policy::reference);
	m.def("RS_TessDispInfo_Delete", &RS_TessDispInfo_Delete);
	m.def("RS_MatteInfo_New", &RS_MatteInfo_New, py::return_value_policy::reference);
	m.def("RS_MatteInfo_Delete", &RS_MatteInfo_Delete);

	m.def("RS_TessDispInfo_GetDefaults", &RS_TessDispInfo_GetDefaults);
	m.def("RS_MatteInfo_GetDefaults", &RS_MatteInfo_GetDefaults);

	py::enum_<RSStrandShapeType>(m, "RSStrandShapeType")
		.value("RS_STRAND_SHAPE_BOX", RS_STRAND_SHAPE_BOX)
		.value("RS_STRAND_SHAPE_CYLINDER", RS_STRAND_SHAPE_CYLINDER)
		.value("RS_STRAND_SHAPE_CAPSULE", RS_STRAND_SHAPE_CAPSULE)
		.value("RS_STRAND_SHAPE_CONE", RS_STRAND_SHAPE_CONE)
		.value("RS_STRAND_SHAPE_STRIP", RS_STRAND_SHAPE_STRIP)
		.export_values();


	py::class_<RSMeshGeneratorStrand>(m, "RSMeshGeneratorStrand")
		.def_readwrite("m_positionsA", &RSMeshGeneratorStrand::m_positionsA)
		.def_readwrite("m_positionsB", &RSMeshGeneratorStrand::m_positionsB)
		.def_readwrite("m_normalsA", &RSMeshGeneratorStrand::m_normalsA)
		.def_readwrite("m_normalsB", &RSMeshGeneratorStrand::m_normalsB)
		.def_readwrite("m_rotationsA", &RSMeshGeneratorStrand::m_rotationsA)
		.def_readwrite("m_rotationsB", &RSMeshGeneratorStrand::m_rotationsB)
		.def_readwrite("m_scalesA", &RSMeshGeneratorStrand::m_scalesA)
		.def_readwrite("m_scalesB", &RSMeshGeneratorStrand::m_scalesB)
		.def_readwrite("m_rawVtxData", &RSMeshGeneratorStrand::m_rawVtxData);


	m.def("RS_MeshGenerator_CreatePlaneMesh", &RS_MeshGenerator_CreatePlaneMesh, py::return_value_policy::reference);
	m.def("RS_MeshGenerator_CreateDiscMesh", &RS_MeshGenerator_CreateDiscMesh, py::return_value_policy::reference);
	m.def("RS_MeshGenerator_CreateBoxMesh", &RS_MeshGenerator_CreateBoxMesh, py::return_value_policy::reference);
	m.def("RS_MeshGenerator_CreateSphereMesh", &RS_MeshGenerator_CreateSphereMesh, py::return_value_policy::reference);
	m.def("RS_MeshGenerator_CreateCylinderMesh", &RS_MeshGenerator_CreateCylinderMesh, py::return_value_policy::reference);
	m.def("RS_MeshGenerator_CreateConeMesh", &RS_MeshGenerator_CreateConeMesh, py::return_value_policy::reference);
	m.def("RS_MeshGenerator_CreateCapsuleMesh", &RS_MeshGenerator_CreateCapsuleMesh, py::return_value_policy::reference);
	m.def("RS_MeshGenerator_FillStrandMesh", &RS_MeshGenerator_FillStrandMesh);



}
