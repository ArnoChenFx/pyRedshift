#include "RSHead.h"
namespace py = pybind11;

void bindRSMaterial(py::module&m)
{
	py::class_<RSMaterial, std::unique_ptr<RSMaterial, py::nodelete>>(m, "RSMaterial")
		.def("GetResourceName", &RSMaterial::GetResourceName)
		//.def("SetMaterialId", py::overload_cast<const char*>(&RSMaterial::SetMaterialId))
		.def("SetMaterialId", &RSMaterial::SetMaterialId)
		.def("SetFriendlyName", &RSMaterial::SetFriendlyName)
		.def("GetFriendlyName", &RSMaterial::GetFriendlyName)
		.def("SetSurfaceShaderNodeGraph", &RSMaterial::SetSurfaceShaderNodeGraph)
		.def("GetSurfaceShaderNodeGraph", &RSMaterial::GetSurfaceShaderNodeGraph, py::return_value_policy::reference)
		.def("SetShaderNodeGraph", &RSMaterial::SetShaderNodeGraph)
		.def("GetShaderNodeGraph", &RSMaterial::GetShaderNodeGraph, py::return_value_policy::reference)
		.def("GetResourceIndex", &RSMaterial::GetResourceIndex)
		.def("HasDisplacementShader", &RSMaterial::HasDisplacementShader)
		.def("HasVolumeShader", &RSMaterial::HasVolumeShader)
		.def("GetVolumeSubGridNames", &RSMaterial::GetVolumeSubGridNames)
		.def("IncrementRefCounter", &RSMaterial::IncrementRefCounter)
		.def("DecrementRefCounter", &RSMaterial::DecrementRefCounter)
		.def("GetUsedUserAttributes", &RSMaterial::GetUsedUserAttributes)
		.def("HasWireframeQuadShader", &RSMaterial::HasWireframeQuadShader);

	m.def("RS_Material_Get", &RS_Material_Get, py::return_value_policy::reference);
	m.def("RS_Material_Release", &RS_Material_Release);
	m.def("RS_Material_Find", &RS_Material_Find, py::return_value_policy::reference);
	m.def("RS_Material_GetGlobalInvalid", &RS_Material_GetGlobalInvalid, py::return_value_policy::reference);
	m.def("RS_Material_GetNames", &RS_Material_GetNames);
	m.def("RS_Material_GetFriendlyNames", &RS_Material_GetFriendlyNames);
}
