#include "RSHead.h"

namespace py = pybind11;
using namespace RenderViewPostEffect;
using namespace pybind11::literals;

void bindRSPostFx(py::module&m)
{
	m.def("CPURender", &CPURender);
	m.def("ApplySRGBConversion", &ApplySRGBConversion);
	m.def("ApplyRec709Conversion", &ApplyRec709Conversion);
	m.def("ApplyGammaConversion", &ApplyGammaConversion);
	m.def("ApplyContrast", &ApplyContrast);
	m.def("RGBtoxyY", &RGBtoxyY);
	m.def("xyYtoRGB", &xyYtoRGB);
	m.def("FindSigmaAndRadiusFromSoftness", &FindSigmaAndRadiusFromSoftness);
	m.def("ApplyCurveTexture", &ApplyCurveTexture);
	m.def("GetOCIO", &GetOCIO, py::return_value_policy::reference);
	m.def("GetLUT", &GetLUT, py::return_value_policy::reference);
	m.def("RS_OCIO_ApplyConversionUsingLUT", &RS_OCIO_ApplyConversionUsingLUT);

	py::class_<OCIOViewTransform>(m, "OCIOViewTransform")
		.def_readwrite("prettyName", &OCIOViewTransform::prettyName)
		.def_readwrite("colorSpace", &OCIOViewTransform::colorSpace)
		.def_readwrite("view", &OCIOViewTransform::view)
		.def_readwrite("display", &OCIOViewTransform::display);

	py::class_<OCIOViewTransformInfo>(m, "OCIOViewTransformInfo")
		.def(py::init<>())
		.def_readwrite("defaultIndex", &OCIOViewTransformInfo::defaultIndex)
		.def_readwrite("viewTransforms", &OCIOViewTransformInfo::viewTransforms);


	m.def("GetOCIOViewTransformInfo", py::overload_cast<RSOCIOConfig , bool>(&GetOCIOViewTransformInfo),"ocioConfig"_a,"activeOnly"_a=false);
	m.def("GetOCIOViewTransformInfo", py::overload_cast<const RSString&, bool>(&GetOCIOViewTransformInfo), "filename"_a, "activeOnly"_a = false);

	py::class_<curveFunc>(m, "curveFunc")
		.def(py::init<>())
		.def(py::init<double, double, double, double, double, double>())
		.def_readwrite("a", &curveFunc::a)
		.def_readwrite("b", &curveFunc::b)
		.def_readwrite("c", &curveFunc::c)
		.def_readwrite("d", &curveFunc::d)
		.def_readwrite("xmin", &curveFunc::xmin)
		.def_readwrite("xmax", &curveFunc::xmax);


	m.def("BuildSpline", &BuildSpline);
	m.def("BuildCurveFunctions", &BuildCurveFunctions);
	
}