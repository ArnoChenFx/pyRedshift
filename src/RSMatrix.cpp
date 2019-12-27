#include "RSHead.h"

namespace py = pybind11;

void bindRSMatrix(py::module&m)
{
	py::class_<RSMatrix3x3>(m, "RSMatrix3x3")
		.def(py::init<>())
		.def(py::init<const RSMatrix3x3&>())
		.def(py::init<float, float, float, float, float, float, float, float, float>())
		.def_readwrite("rx", &RSMatrix3x3::rx)
		.def_readwrite("ry", &RSMatrix3x3::ry)
		.def_readwrite("rz", &RSMatrix3x3::rz)
		.def("SetIdentity", &RSMatrix3x3::SetIdentity)
		.def("Mul", &RSMatrix3x3::Mul)
		.def("RotateX", &RSMatrix3x3::RotateX)
		.def("RotateY", &RSMatrix3x3::RotateY)
		.def("RotateZ", &RSMatrix3x3::RotateZ)
		.def("GetInverse", &RSMatrix3x3::GetInverse)
		.def(py::self * py::self)
		.def(py::self *= py::self)
		.def(py::self == py::self)
		.def(py::self != py::self);
	
	py::class_<RSMatrix4x4>(m, "RSMatrix4x4")
		.def(py::init<>())
		.def(py::init<const RSMatrix4x4&>())
		.def(py::init<float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float>())
		.def_readwrite("rx", &RSMatrix4x4::rx)
		.def_readwrite("ry", &RSMatrix4x4::ry)
		.def_readwrite("rz", &RSMatrix4x4::rz)
		.def_readwrite("rw", &RSMatrix4x4::rw)
		.def("SetIdentity", &RSMatrix4x4::SetIdentity)
		.def("Mul", &RSMatrix4x4::Mul)
		.def("RotateX", &RSMatrix4x4::RotateX)
		.def("RotateY", &RSMatrix4x4::RotateY)
		.def("RotateZ", &RSMatrix4x4::RotateZ)
		.def("GetTranspose", &RSMatrix4x4::GetTranspose)
		.def("GetAffineInvert", &RSMatrix4x4::GetAffineInvert)
		.def("GetInverseTransposeNoTrans", &RSMatrix4x4::GetInverseTransposeNoTrans)
		.def("SetTranslation", &RSMatrix4x4::SetTranslation)
		.def(py::self * py::self)
		.def(py::self *= py::self)
		.def(py::self == py::self)
		.def(py::self != py::self);
}