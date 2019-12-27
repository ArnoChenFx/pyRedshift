#include "RSHead.h"
namespace py = pybind11;

void bindRSTraceSet(py::module&m)
{
	py::class_<RSTraceSet, std::unique_ptr<RSTraceSet, py::nodelete>>(m, "RSTraceSet")
		.def("SetObjectNamesList", &RSTraceSet::SetObjectNamesList)
		.def("LoadFromStream", &RSTraceSet::LoadFromStream)
		.def("SaveToStream", &RSTraceSet::SaveToStream);

	m.def("RS_TraceSet_New", &RS_TraceSet_New, py::return_value_policy::reference);
	m.def("RS_TraceSet_Delete", &RS_TraceSet_Delete);
}
