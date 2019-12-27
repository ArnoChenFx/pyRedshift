#include "RSHead.h"

using std::cout;
using std::endl;
namespace py = pybind11;


template<class T>
void declare_RSArray(py::module &m, const char* name)
{
	using Class = RSArray<T>;
	using PyClass = py::class_<Class, std::shared_ptr<Class>>;

	std::string pyclass_name = std::string("RSArray") + std::string(name);
	PyClass cls(m, (pyclass_name.c_str()));
	//py::class_<Class>(m, pyclass_name.c_str(), py::buffer_protocol(), py::dynamic_attr())
	cls.def(py::init<>());
	cls.def(py::init<const Class&>());
	cls.def(py::init<size_t, const T&>());
	cls.def("SetLength", &Class::SetLength);
	cls.def("ReserveLength", &Class::ReserveLength);
	cls.def("Length", &Class::Length);
	cls.def("Add", &Class::Add);
	cls.def("Contains", &Class::Contains, py::arg("entry"), py::arg("pIndex") = NULL);
	cls.def("ClearEverything", &Class::ClearEverything);
	cls.def("__iadd__", &Class::operator+=);
	cls.def("__getitem__", [](const Class& cls, size_t i) { return cls[i]; });

};

void bindRSArray(py::module&m)
{

	declare_RSArray<RSMaterial*>(m, "Material");
	declare_RSArray<RSString>(m, "String");
	declare_RSArray<RSVector3>(m, "Vector3");
	declare_RSArray<RSVector2>(m, "Vector2");
	declare_RSArray<RSUInt2>(m, "UInt2");//<---modify
	//bool operator==(const RSUInt2& p) const { return ((p.x == x) && (p.y == y)); }
	////declare_RSArray<RSProxy::MaterialReplacement>(m, "MaterialReplacement");
	declare_RSArray<unsigned int>(m, "Size_t");
	declare_RSArray<float>(m, "Float");
	declare_RSArray<int>(m, "Int");
	declare_RSArray<RSProxy*>(m, "Proxy");
	declare_RSArray<RSMeshGeneratorStrand*>(m, "MeshGeneratorStrand");
}