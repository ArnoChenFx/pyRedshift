#include "RSHead.h"
namespace py = pybind11;

void bindRSString(py::module&m)
{
	py::class_<RSString>(m, "RSString")
		.def(py::init<>())
		.def(py::init<const RSString>())
		.def(py::init<const char*>())
		.def(py::init<const wchar_t*>())
		.def("Length", &RSString::Length)
		.def("IsEmpty", &RSString::IsEmpty)
		.def("c_str", &RSString::c_str)
		.def("__str__", [](const RSString& m) { return m.c_str(); })
		.def("__repr__", &RSString::c_str)
		.def(py::self == py::self)
		.def(py::self != py::self)
		.def(py::self >= py::self)
		.def(py::self > py::self)
		.def(py::self <= py::self)
		.def(py::self < py::self)
		.def(py::self += py::self)
		.def("__getitem__", [](const RSString& cls, size_t i) { return cls[i]; });;
}