#include "RSHead.h"

namespace py = pybind11;

void bindRSColorCorrection(py::module&m)
{
	py::class_<RSOCIOLUT, std::unique_ptr<RSOCIOLUT, py::nodelete>>(m, "RSOCIOLUT")
		.def("GetLutCubeSize", &RSOCIOLUT::GetLutCubeSize)
		.def("GetInputMinMax", &RSOCIOLUT::GetInputMinMax, py::return_value_policy::reference)
		.def("GetLutRawData", &RSOCIOLUT::GetLutRawData)
		.def("GetOffsetAndNormalizationFactors", &RSOCIOLUT::GetOffsetAndNormalizationFactors);

	m.def("RS_OCIO_CreateConfigFromFile", &RS_OCIO_CreateConfigFromFile);
	m.def("RS_OCIO_DeleteConfig", &RS_OCIO_DeleteConfig);
	m.def("RS_OCIOCOnfig_GetColorSpaces", &RS_OCIOCOnfig_GetColorSpaces);
	m.def("RS_OCIOCOnfig_GetRoles", &RS_OCIOCOnfig_GetRoles);
	m.def("RS_OCIOCOnfig_GetColorSpaceForRole", &RS_OCIOCOnfig_GetColorSpaceForRole);
	m.def("RS_OCIOCOnfig_GetDisplays", &RS_OCIOCOnfig_GetDisplays);
	m.def("RS_OCIOCOnfig_GetDefaultDisplay", &RS_OCIOCOnfig_GetDefaultDisplay);
	m.def("RS_OCIOCOnfig_GetViewsForDisplay", &RS_OCIOCOnfig_GetViewsForDisplay);
	m.def("RS_OCIOCOnfig_GetDefaultViewForDisplay", &RS_OCIOCOnfig_GetDefaultViewForDisplay);

	m.def("RS_OCIO_CreateProcessor", py::overload_cast<RSOCIOConfig , const char* , const char*>(&RS_OCIO_CreateProcessor));
	m.def("RS_OCIO_CreateProcessor", py::overload_cast<RSOCIOConfig, const char*, const char*, const char*>(&RS_OCIO_CreateProcessor));
	m.def("RS_OCIO_DeleteProcessor", &RS_OCIO_DeleteProcessor);
	m.def("RS_OCIO_ApplyConversion", &RS_OCIO_ApplyConversion);
	m.def("RS_OCIO_ComputeLUT", py::overload_cast<RSOCIOConfig , const char* , const char* , unsigned int , float , float>(&RS_OCIO_ComputeLUT));
	m.def("RS_OCIO_ComputeLUT", py::overload_cast<RSOCIOConfig, const char*, const char*, const char*,unsigned int, float, float>(&RS_OCIO_ComputeLUT));
	m.def("RS_OCIO_ComputeLUT", py::overload_cast<RSOCIOProcessor, unsigned int, float, float>(&RS_OCIO_ComputeLUT));
	m.def("RS_OCIO_ComputeLUTFromCubeFile", &RS_OCIO_ComputeLUTFromCubeFile);
	m.def("RS_OCIO_ComputeLUTFrom3DLFile", &RS_OCIO_ComputeLUTFrom3DLFile);
	m.def("RS_OCIO_DeleteLUT", &RS_OCIO_DeleteLUT);
	m.def("RS_OCIO_ApplyConversionUsingLUT", &RS_OCIO_ApplyConversionUsingLUT);
}