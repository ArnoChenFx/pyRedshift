#include "RSHead.h"
namespace py = pybind11;

void bindRSAttributes(py::module&m)
{
	py::class_<RSAttributesFormat, std::unique_ptr<RSAttributesFormat, py::nodelete>>(m, "RSAttributesFormat")
		.def("SetNumAttributes", &RSAttributesFormat::SetNumAttributes)
		.def("GetNumAttributes", &RSAttributesFormat::GetNumAttributes)
		.def("IsAttributeUsed", &RSAttributesFormat::IsAttributeUsed)
		.def("GetAttributeOffsetBytes", &RSAttributesFormat::GetAttributeOffsetBytes)
		.def("GetAttributeStorageType", &RSAttributesFormat::GetAttributeStorageType)
		.def("GetAttributeStorageNumBytes", &RSAttributesFormat::GetAttributeStorageNumBytes)
		.def("GetAttributeUsageType", &RSAttributesFormat::GetAttributeUsageType)
		.def("GetAttributeName", &RSAttributesFormat::GetAttributeName)
		.def("GetRawAttributesSize", &RSAttributesFormat::GetRawAttributesSize)
		.def("IsRoughlyEqual", &RSAttributesFormat::IsRoughlyEqual)
		.def("GetHashForExporter", &RSAttributesFormat::GetHashForExporter);

	py::class_<RSAttributesData, std::unique_ptr<RSAttributesData, py::nodelete>, RSAttributesFormat>(m, "RSAttributesData")
		.def("SetAttributesRaw", &RSAttributesData::SetAttributesRaw)
		.def("GetRawAttributes", &RSAttributesData::GetRawAttributes)
		.def("CopySettingsFrom", &RSAttributesData::CopySettingsFrom)
		.def("SetAttributeValue", py::overload_cast<unsigned int, const float>(&RSAttributesData::SetAttributeValue))
		.def("SetAttributeValue", py::overload_cast<unsigned int, const int>(&RSAttributesData::SetAttributeValue))
		.def("SetAttributeValue", py::overload_cast<unsigned int, const RSColor&>(&RSAttributesData::SetAttributeValue))
		.def("SetAttributeValue", py::overload_cast<unsigned int, const RSVector2&>(&RSAttributesData::SetAttributeValue))
		.def("SetAttributeValue", py::overload_cast<unsigned int, const RSVector3&>(&RSAttributesData::SetAttributeValue))
		.def("SetAttributeValue", py::overload_cast<unsigned int, const RSVector4&>(&RSAttributesData::SetAttributeValue))
		.def("SetAttributeValue", py::overload_cast<unsigned int, const void*>(&RSAttributesData::SetAttributeValue));

	py::class_<RSVertexData, std::unique_ptr<RSVertexData, py::nodelete>, RSAttributesData>(m, "RSVertexData")
		.def("SetAttributeDefinition", &RSVertexData::SetAttributeDefinition)
		.def("FinalizeAttributeFormatAndAllocate", &RSVertexData::FinalizeAttributeFormatAndAllocate)
		.def("SetTexCoordAttributeProjectionProperties", &RSVertexData::SetTexCoordAttributeProjectionProperties)
		.def("GetTexCoordAttributeProjectionVectors", &RSVertexData::GetTexCoordAttributeProjectionVectors, py::return_value_policy::reference);

	py::class_<RSUserData, std::unique_ptr<RSUserData, py::nodelete>, RSAttributesData>(m, "RSUserData")
		.def("SetAttributeDefinition", &RSUserData::SetAttributeDefinition)
		.def("FinalizeAttributeFormatAndAllocate", &RSUserData::FinalizeAttributeFormatAndAllocate)
		.def("SaveToStream", &RSUserData::SaveToStream)
		.def("LoadFromStream", &RSUserData::LoadFromStream);

	py::class_<RSPointData, std::unique_ptr<RSPointData, py::nodelete>, RSAttributesData>(m, "RSPointData")
		.def("SetAttributeDefinition", &RSPointData::SetAttributeDefinition)
		.def("FinalizeAttributeFormatAndAllocate", &RSPointData::FinalizeAttributeFormatAndAllocate);

	m.def("RS_VertexData_New", &RS_VertexData_New, py::return_value_policy::reference);
	m.def("RS_VertexData_Delete", &RS_VertexData_Delete);
	m.def("RS_UserData_New", &RS_UserData_New, py::return_value_policy::reference);
	m.def("RS_UserData_Delete", &RS_UserData_Delete);
	m.def("RS_PointData_New", &RS_PointData_New, py::return_value_policy::reference);
	m.def("RS_PointData_Delete", &RS_PointData_Delete);
	m.def("RS_AttributesData_Delete", &RS_AttributesData_Delete);
}
