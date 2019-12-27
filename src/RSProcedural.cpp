#include "RSHead.h"
namespace py = pybind11;

void bindRSProcedural(py::module&m)
{
	py::class_<RSProcedural>(m, "RSProcedural")
		.def("GetName", &RSProcedural::GetName)
		.def("GetType", &RSProcedural::GetType)
		.def("GetGUID", &RSProcedural::GetGUID)
		.def("BeginGetData", &RSProcedural::BeginGetData)
		.def("EndGetData", &RSProcedural::EndGetData)
		.def("OverrideFlags", &RSProcedural::OverrideFlags)
		.def("OverrideObjectID", &RSProcedural::OverrideObjectID)
		.def("OverrideMatteInfo", &RSProcedural::OverrideMatteInfo)
		.def("OverrideTraceSets", &RSProcedural::OverrideTraceSets)
		.def("OverrideUserData", &RSProcedural::OverrideUserData)
		.def("ParentTransform", &RSProcedural::ParentTransform)
		.def("Instantiate", &RSProcedural::Instantiate, py::return_value_policy::reference)
		.def("AddContentsToScene", &RSProcedural::AddContentsToScene)
		.def("Needed", &RSProcedural::Needed)
		.def("EndOfFrame", &RSProcedural::EndOfFrame);

	m.def("RS_Procedural_New", py::overload_cast<const char*, unsigned int, unsigned int, unsigned int, unsigned int, size_t, const void*>(&RS_Procedural_New), py::return_value_policy::reference);
	m.def("RS_Procedural_New", py::overload_cast<const char* , const char* , size_t , const void*>(&RS_Procedural_New), py::return_value_policy::reference);
	m.def("RS_Procedural_Delete", &RS_Procedural_Delete);
}
