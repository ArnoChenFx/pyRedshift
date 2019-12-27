#include "RSHead.h"
namespace py = pybind11;

void bindRSDatatypes(py::module&m)
{
	py::class_<RSUInt2>(m, "RSUInt2")
		.def(py::init<>())
		.def(py::init<unsigned int, unsigned int>())
		.def_readwrite("x", &RSUInt2::x)
		.def_readwrite("y", &RSUInt2::y);

	py::class_<RSInt2>(m, "RSInt2")
		.def(py::init<>())
		.def(py::init<int,int>())
		.def_readwrite("x", &RSInt2::x)
		.def_readwrite("y", &RSInt2::y);

	py::class_<RSUInt3>(m, "RSUInt3")
		.def(py::init<>())
		.def(py::init<unsigned int, unsigned int, unsigned int>())
		.def_readwrite("x", &RSUInt3::x)
		.def_readwrite("y", &RSUInt3::y)
		.def_readwrite("z", &RSUInt3::z);

	py::class_<RSInt3>(m, "RSInt3")
		.def(py::init<>())
		.def(py::init< int, int,int>())
		.def_readwrite("x", &RSInt3::x)
		.def_readwrite("y", &RSInt3::y)
		.def_readwrite("z", &RSInt3::z);

	py::class_<RSUInt4>(m, "RSUInt4")
		.def(py::init<>())
		.def(py::init<unsigned int, unsigned int, unsigned int, unsigned int>())
		.def_readwrite("x", &RSUInt4::x)
		.def_readwrite("y", &RSUInt4::y)
		.def_readwrite("z", &RSUInt4::z)
		.def_readwrite("w", &RSUInt4::w);

	py::class_<RSInt4>(m, "RSInt4")
		.def(py::init<>())
		.def(py::init< int, int, int, int>())
		.def_readwrite("x", &RSInt4::x)
		.def_readwrite("y", &RSInt4::y)
		.def_readwrite("z", &RSInt4::z)
		.def_readwrite("w", &RSInt4::w);

	py::class_<RSVector2>(m, "RSVector2")
		.def(py::init<>())
		.def(py::init< float, float>())
		.def("LengthSqrd", &RSVector2::LengthSqrd)
		.def("Length", &RSVector2::Length)
		.def("Normalize", py::overload_cast<RSVector2&>(&RSVector2::Normalize,py::const_))//============
		.def("Normalize", py::overload_cast<>(&RSVector2::Normalize))//===============
		.def("Length", &RSVector2::Length)
		.def(py::self == py::self)
		.def(py::self != py::self)
		.def_readwrite("x", &RSVector2::x)
		.def_readwrite("y", &RSVector2::y);

	py::class_<RSVector3>(m, "RSVector3")
		.def(py::init<>())
		.def(py::init< float, float, float>())
		.def("Set", &RSVector3::Set)
		.def("Dot", &RSVector3::Dot)
		.def("Cross", &RSVector3::Cross)
		.def("LengthSqrd", &RSVector3::LengthSqrd)
		.def("Length", &RSVector3::Length)
		.def("Normalize", py::overload_cast<RSVector3&>(&RSVector3::Normalize, py::const_))//============
		.def("Normalize", py::overload_cast<>(&RSVector3::Normalize))//===============
		.def(py::self == py::self)
		.def(py::self != py::self)
		.def(py::self - py::self)
		.def(py::self + py::self)
		.def(py::self * py::self)
		.def(py::self *= py::self)
		.def(py::self += py::self)
		.def(py::self * float())
		.def(py::self *= float())
		.def(py::self / float())
		.def_readwrite("x", &RSVector3::x)
		.def_readwrite("y", &RSVector3::y)
		.def_readwrite("z", &RSVector3::z);

	py::class_<RSVector4>(m, "RSVector4")
		.def(py::init<>())
		.def(py::init< float, float, float, float>())
		.def("Set", &RSVector4::Set)
		.def("Zero", &RSVector4::Zero)
		.def("Plus", &RSVector4::Plus)
		.def("Minus", &RSVector4::Minus)
		.def("Mult", &RSVector4::Mult)
		.def("Div", &RSVector4::Div)
		.def("Recp", &RSVector4::Recp)
		.def("Scale", &RSVector4::Scale)
		.def("Negate", &RSVector4::Negate)
		.def("LengthXYZ", &RSVector4::LengthXYZ)
		.def("LengthSqrd", &RSVector4::LengthSqrd)
		.def("Length", &RSVector4::Length)
		.def("Normalize", (void (RSVector4::*)()) &RSVector4::Normalize)
		.def(py::self == py::self)
		.def(py::self != py::self)
		.def(py::self - py::self)
		.def(py::self -= py::self)
		.def(py::self + py::self)
		.def(py::self += py::self)
		.def(py::self * py::self)
		.def(py::self *= py::self)
		.def(py::self / py::self)
		.def(py::self /= py::self)
		.def(py::self * float())
		.def(py::self *= float())
		.def(py::self / float())
		.def(py::self /= float())
		.def_readwrite("x", &RSVector4::x)
		.def_readwrite("y", &RSVector4::y)
		.def_readwrite("z", &RSVector4::z)
		.def_readwrite("w", &RSVector4::w);

	py::class_<RSColor, RSVector4>(m, "RSColor")
		.def(py::init<>())
		.def(py::init< float, float, float, float>());

	py::class_<RSNormal>(m, "RSNormal")
		.def(py::init<>())
		.def(py::init< float, float, float>())
		.def(py::init< const RSVector3&>())
		.def("Set", &RSNormal::Set)
		.def("Get", &RSNormal::Get);

	py::class_<RSTangent>(m, "RSTangent")
		.def(py::init<>())
		.def(py::init< float, float, float, float>())
		.def(py::init< const RSVector3&,float>())
		.def(py::init< const RSVector4&>())
		.def("Set", &RSTangent::Set)
		.def("Get", &RSTangent::Get);

	m.def("RS_PackColor", &RS_PackColor);
}