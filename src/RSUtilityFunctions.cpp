#include "RSHead.h"

namespace py = pybind11;

void bindRSUtilityFunctions(py::module&m)
{
	m.def("RS_Utility_ImageLoad", py::overload_cast<const char* , unsigned int& , unsigned int&>(&RS_Utility_ImageLoad), py::return_value_policy::reference);
	m.def("RS_Utility_ImageLoad", py::overload_cast<const char*, unsigned int&, unsigned int&, RSArray<RSBlockSinkMetadataEntry>&>(&RS_Utility_ImageLoad), py::return_value_policy::reference);
	m.def("RS_Utility_ImageLoad_MultiPart", &RS_Utility_ImageLoad_MultiPart, py::return_value_policy::reference);
	m.def("RS_Utility_ImageDelete", &RS_Utility_ImageDelete);
	m.def("RS_Utility_ImageSave", py::overload_cast<const char* , RSVector4* , unsigned int , unsigned int>(&RS_Utility_ImageSave));
	m.def("RS_Utility_ImageSave", py::overload_cast<const char*, RSVector4*, unsigned int, unsigned int, const RSArray<RSBlockSinkMetadataEntry>&>(&RS_Utility_ImageSave));
	m.def("RS_Utility_ImageSave_MultiPart", &RS_Utility_ImageSave_MultiPart);
	m.def("RS_Utility_StripPath", &RS_Utility_StripPath);
	m.def("RS_Utility_RemoveAndReturnExtension", &RS_Utility_RemoveAndReturnExtension);
	m.def("RS_Utility_ReplacePath", &RS_Utility_ReplacePath);
	m.def("RS_Utility_Canonicalize", &RS_Utility_Canonicalize);
	m.def("RS_Utility_MakeAbsolutePath", &RS_Utility_MakeAbsolutePath);
	m.def("RS_Utility_FileExists", &RS_Utility_FileExists);
	m.def("RS_Utility_StripHTMLTags", &RS_Utility_StripHTMLTags);
	m.def("RS_Utility_ConditionStringForHTMLOutput", &RS_Utility_ConditionStringForHTMLOutput);

	m.def("RS_Denoise_Altus_IsLicenseValid", &RS_Denoise_Altus_IsLicenseValid);
	m.def("RS_Denoise_Altus_IsOpenCLInstalled", &RS_Denoise_Altus_IsOpenCLInstalled);
	m.def("RS_Denoise_Altus_SinglePass",py::overload_cast<unsigned int , unsigned int ,RSVector4* ,RSVector4* , RSVector4* , RSVector4* ,RSVector4*, RSVector4* , RSVector4*,RSVector4* , RSVector4*  , RSVector4* ,RSVector4*, RSVector4*  , RSVector4* ,float, float , float, float,bool>(&RS_Denoise_Altus_SinglePass));
	m.def("RS_Denoise_Altus_SinglePass", py::overload_cast<unsigned int, unsigned int, int, float*, int, float*, float*, float*, int, float*, float*, float*, int, float*, float*, float*, int, float*, float*, float*, float, float, float, float, bool>(&RS_Denoise_Altus_SinglePass));
	m.def("RS_Denoise_Altus_DualPass", py::overload_cast<unsigned int, unsigned int, RSVector4*, RSVector4*, RSVector4*, RSVector4*, RSVector4*, RSVector4*, RSVector4*, RSVector4*, RSVector4*, float, float, float, float, bool>(&RS_Denoise_Altus_DualPass));
	m.def("RS_Denoise_Altus_DualPass", py::overload_cast<unsigned int, unsigned int, int, float*, int, float*, float*,  int, float*, float*, int, float*, float*, int, float*, float*, float, float, float, float, bool>(&RS_Denoise_Altus_DualPass));
	m.def("RS_Denoise_OptiXAllocateBuffers", &RS_Denoise_OptiXAllocateBuffers);
	m.def("RS_Denoise_OptiXDeallocateBuffers", &RS_Denoise_OptiXDeallocateBuffers);
	m.def("RS_Denoise_OptiXNeedsARenderRestart", &RS_Denoise_OptiXNeedsARenderRestart);
	
	m.def("RS_Denoise_OptiX", py::overload_cast<unsigned int, unsigned int, RSVector4*, RSVector4*, RSVector4*, RSVector4*>(&RS_Denoise_OptiX));
	m.def("RS_Denoise_OptiX", py::overload_cast<unsigned int, unsigned int, int, float*, int, float*, int, float*, int, float*>(&RS_Denoise_OptiX));

	//py::class_<RSCriticalSectionObject>(m, "RSCriticalSectionObject")
	//	.def("Enter", &RSCriticalSectionObject::Enter)
	//	.def("Leave", &RSCriticalSectionObject::Leave)
	//	.def("TryEnter", &RSCriticalSectionObject::TryEnter);

	//m.def("RS_CriticalSectionObject_New", &RS_CriticalSectionObject_New, py::return_value_policy::reference);
	//m.def("RS_CriticalSectionObject_Delete", &RS_CriticalSectionObject_Delete);
}