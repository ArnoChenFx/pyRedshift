#include "RSHead.h"
namespace py = pybind11;

void bindRSTexture(py::module&m)
{
	py::enum_<RSTextureTileMode>(m, "RSTextureTileMode")
		.value("RS_TEXTURETILEMODE_NONE", RS_TEXTURETILEMODE_NONE)
		.value("RS_TEXTURETILEMODE_UDIM", RS_TEXTURETILEMODE_UDIM)
		.value("RS_TEXTURETILEMODE_UVTILE_ZERO_BASED", RS_TEXTURETILEMODE_UVTILE_ZERO_BASED)
		.value("RS_TEXTURETILEMODE_UVTILE_ONE_BASED", RS_TEXTURETILEMODE_UVTILE_ONE_BASED)
		.export_values();

	py::class_<RSTexture, std::unique_ptr<RSTexture, py::nodelete>>(m, "RSTexture")
		.def("SetAlphaMode", &RSTexture::SetAlphaMode);
	py::class_<RSUDIMTexture, std::unique_ptr<RSUDIMTexture, py::nodelete>>(m, "RSUDIMTexture")
		.def("SetAlphaMode", &RSUDIMTexture::SetAlphaMode);
	py::class_<RSUVTILETexture, std::unique_ptr<RSUVTILETexture, py::nodelete>>(m, "RSUVTILETexture")
		.def("SetAlphaMode", &RSUVTILETexture::SetAlphaMode);
	py::class_<RSIndexedTexture,std::unique_ptr<RSIndexedTexture, py::nodelete>>(m, "RSIndexedTexture")
		.def("SetAlphaMode", &RSIndexedTexture::SetAlphaMode)
		.def("BeginSetTextures", &RSIndexedTexture::BeginSetTextures)
		.def("SetTexture", &RSIndexedTexture::SetTexture)
		.def("EndSetTextures", &RSIndexedTexture::EndSetTextures);

	py::class_<RSTextureMetaData>(m, "RSTextureMetaData")
		.def_readwrite("m_width", &RSTextureMetaData::m_width)
		.def_readwrite("m_height", &RSTextureMetaData::m_height)
		.def_readwrite("m_bitsPerChannel", &RSTextureMetaData::m_bitsPerChannel)
		.def_readwrite("m_numChannels", &RSTextureMetaData::m_numChannels)
		.def_readwrite("m_isFloatingPoint", &RSTextureMetaData::m_isFloatingPoint)
		.def_readwrite("m_recommendedGammaIsSRGB", &RSTextureMetaData::m_recommendedGammaIsSRGB)
		.def_readwrite("m_recommendedGammaValue", &RSTextureMetaData::m_recommendedGammaValue);

	m.def("RS_Texture_Get", &RS_Texture_Get, py::return_value_policy::reference);
	m.def("RS_Texture_Release", &RS_Texture_Release);
	m.def("RS_UDIMTexture_Get", &RS_UDIMTexture_Get, py::return_value_policy::reference);
	m.def("RS_UDIMTexture_Release", &RS_UDIMTexture_Release);
	m.def("RS_UVTILETexture_Get", &RS_UVTILETexture_Get, py::return_value_policy::reference);
	m.def("RS_UVTILETexture_Release", &RS_UVTILETexture_Release);
	m.def("RS_IndexedTexture_Get", &RS_IndexedTexture_Get, py::return_value_policy::reference);
	m.def("RS_IndexedTexture_Release", &RS_IndexedTexture_Release);

	m.def("RS_Texture_ComputeGamma", &RS_Texture_ComputeGamma);
	m.def("RS_Texture_GetMetaData", py::overload_cast<const char*, RSTextureMetaData&>(&RS_Texture_GetMetaData));
	m.def("RS_Texture_GetMetaData", py::overload_cast<RSTexture *, RSTextureMetaData&>(&RS_Texture_GetMetaData));
	m.def("RS_Texture_GetMetaData", py::overload_cast<RSUDIMTexture *, RSTextureMetaData&>(&RS_Texture_GetMetaData));
	m.def("RS_Texture_GetMetaData", py::overload_cast<RSUVTILETexture *, RSTextureMetaData&>(&RS_Texture_GetMetaData));

	m.def("RS_Texture_GetLayerNames", py::overload_cast<const char*, RSArray< RSString >&>(&RS_Texture_GetLayerNames));
	m.def("RS_Texture_GetLayerNames", py::overload_cast<RSTexture *, RSArray< RSString >&>(&RS_Texture_GetLayerNames));
	m.def("RS_Texture_GetLayerNames", py::overload_cast<RSUDIMTexture *, RSArray< RSString >&>(&RS_Texture_GetLayerNames));
	m.def("RS_Texture_GetLayerNames", py::overload_cast<RSUVTILETexture *, RSArray< RSString >&>(&RS_Texture_GetLayerNames));

	m.def("RS_Texture_ComputeUDIMFileNameWithTag", &RS_Texture_ComputeUDIMFileNameWithTag);
	m.def("RS_Texture_ComputeUVTILEFileNameWithTag", &RS_Texture_ComputeUVTILEFileNameWithTag);
	m.def("RS_Texture_GetTextureFileListFromFileNameWithTileTag", &RS_Texture_GetTextureFileListFromFileNameWithTileTag);

	py::enum_<RSEnvMapType>(m, "RSEnvMapType")
		.value("RSEnvMapType_Sphere", RSEnvMapType_Sphere)
		.value("RSEnvMapType_Hemisphere", RSEnvMapType_Hemisphere)
		.value("RSEnvMapType_Mirrorball", RSEnvMapType_Mirrorball)
		.value("RSEnvMapType_Angular", RSEnvMapType_Angular)
		.export_values();

	m.def("RS_SaveDomePreviewImage", &RS_SaveDomePreviewImage);
	m.def("RS_ConvertMirrorBallImageToLatLongImage", &RS_ConvertMirrorBallImageToLatLongImage);
	m.def("RS_ConvertAngularMapImageToLatLongImage", &RS_ConvertAngularMapImageToLatLongImage);
	m.def("RS_ConvertHalfLatLongImageToFullLatLongImage", &RS_ConvertHalfLatLongImageToFullLatLongImage);


}