#include "RSHead.h"
namespace py = pybind11;

void bindRSCurve(py::module&m)
{
	py::class_<RSCurve, std::unique_ptr<RSCurve, py::nodelete>>(m, "RSCurve")
		.def("SetCurveType", &RSCurve::SetCurveType)
		.def("SetNumKnots", &RSCurve::SetNumKnots)
		.def("SetKnotValue", py::overload_cast<unsigned int, float, float, const char*>(&RSCurve::SetKnotValue))
		.def("SetKnotValue", py::overload_cast<unsigned int, float, const RSColor&, const char*>(&RSCurve::SetKnotValue));

	m.def("RS_Curve_Get", &RS_Curve_Get, py::return_value_policy::reference);
	m.def("RS_Curve_Release", &RS_Curve_Release);
}