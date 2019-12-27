#include "RSHead.h"
namespace py = pybind11;

void bindRSCamera(py::module&m)
{
	py::class_<RSDOFParams>(m, "RSDOFParams")
		.def("SetIsEnabled", &RSDOFParams::SetIsEnabled)
		.def("GetIsEnabled", &RSDOFParams::GetIsEnabled)
		.def("SetFocusDistance", &RSDOFParams::SetFocusDistance)
		.def("GetFocusDistance", &RSDOFParams::GetFocusDistance)
		.def("SetRadius", &RSDOFParams::SetRadius)
		.def("GetRadius", &RSDOFParams::GetRadius)
		.def("SetPower", &RSDOFParams::SetPower)
		.def("GetPower", &RSDOFParams::GetPower)
		.def("SetAspect", &RSDOFParams::SetAspect)
		.def("GetAspect", &RSDOFParams::GetAspect)
		.def("SetNumSides", &RSDOFParams::SetNumSides)
		.def("GetNumSides", &RSDOFParams::GetNumSides)
		.def("SetAngle", &RSDOFParams::SetAngle)
		.def("GetAngle", &RSDOFParams::GetAngle)
		.def("SetBokehImageFilename", &RSDOFParams::SetBokehImageFilename)
		.def("GetBokehImageFilename", &RSDOFParams::GetBokehImageFilename)
		.def("SetBokehNormalizationMode", &RSDOFParams::SetBokehNormalizationMode)
		.def("GetBokehNormalizationMode", &RSDOFParams::GetBokehNormalizationMode)
		.def("CopySettingsFrom", &RSDOFParams::CopySettingsFrom);

	py::class_<RSPhysicalCameraParams>(m, "RSPhysicalCameraParams")
		.def("SetIsEnabled", &RSPhysicalCameraParams::SetIsEnabled)
		.def("GetIsEnabled", &RSPhysicalCameraParams::GetIsEnabled)
		.def("SetIsAppliedAtRenderTime", &RSPhysicalCameraParams::SetIsAppliedAtRenderTime)
		.def("GetIsAppliedAtRenderTime", &RSPhysicalCameraParams::GetIsAppliedAtRenderTime)
		.def("SetISO", &RSPhysicalCameraParams::SetISO)
		.def("GetISO", &RSPhysicalCameraParams::GetISO)
		.def("SetShutterRatio", &RSPhysicalCameraParams::SetShutterRatio)
		.def("GetShutterRatio", &RSPhysicalCameraParams::GetShutterRatio)
		.def("SetFStop", &RSPhysicalCameraParams::SetFStop)
		.def("GetFStop", &RSPhysicalCameraParams::GetFStop)
		.def("SetWhitePoint", &RSPhysicalCameraParams::SetWhitePoint)
		.def("GetWhitePoint", &RSPhysicalCameraParams::GetWhitePoint)
		.def("SetVignetting", &RSPhysicalCameraParams::SetVignetting)
		.def("GetVignetting", &RSPhysicalCameraParams::GetVignetting)
		.def("SetReinhardFactor", &RSPhysicalCameraParams::SetReinhardFactor)
		.def("GetReinhardFactor", &RSPhysicalCameraParams::GetReinhardFactor)
		.def("SetReinhardAllowDesaturation", &RSPhysicalCameraParams::SetReinhardAllowDesaturation)
		.def("GetReinhardAllowDesaturation", &RSPhysicalCameraParams::GetReinhardAllowDesaturation)
		.def("SetBlackCrushThresh", &RSPhysicalCameraParams::SetBlackCrushThresh)
		.def("GetBlackCrushThresh", &RSPhysicalCameraParams::GetBlackCrushThresh)
		.def("SetBlackCrushAmount", &RSPhysicalCameraParams::SetBlackCrushAmount)
		.def("GetBlackCrushAmount", &RSPhysicalCameraParams::GetBlackCrushAmount)
		.def("SetSaturation", &RSPhysicalCameraParams::SetSaturation)
		.def("GetSaturation", &RSPhysicalCameraParams::GetSaturation)
		.def("CopySettingsFrom", &RSPhysicalCameraParams::CopySettingsFrom);

	py::class_<RSLensDistortionParams>(m, "RSLensDistortionParams")
		.def("SetIsEnabled", &RSLensDistortionParams::SetIsEnabled)
		.def("GetIsEnabled", &RSLensDistortionParams::GetIsEnabled)
		.def("SetDistortionImageFilename", &RSLensDistortionParams::SetDistortionImageFilename)
		.def("GetDistortionImageFilename", &RSLensDistortionParams::GetDistortionImageFilename)
		.def("CopySettingsFrom", &RSLensDistortionParams::CopySettingsFrom);


	py::class_<RSBloomParams>(m, "RSBloomParams")
		.def("SetIsEnabled", &RSBloomParams::SetIsEnabled)
		.def("GetIsEnabled", &RSBloomParams::GetIsEnabled)
		.def("SetThreshold", &RSBloomParams::SetThreshold)
		.def("GetThreshold", &RSBloomParams::GetThreshold)
		.def("SetSoftness", &RSBloomParams::SetSoftness)
		.def("GetSoftness", &RSBloomParams::GetSoftness)
		.def("SetTint", &RSBloomParams::SetTint)
		.def("GetTint", &RSBloomParams::GetTint)
		.def("SetIntensity", &RSBloomParams::SetIntensity)
		.def("GetIntensity", &RSBloomParams::GetIntensity)
		.def("CopySettingsFrom", &RSBloomParams::CopySettingsFrom);

	py::class_<RSStreakParams>(m, "RSStreakParams")
		.def("SetIsEnabled", &RSStreakParams::SetIsEnabled)
		.def("GetIsEnabled", &RSStreakParams::GetIsEnabled)
		.def("SetThreshold", &RSStreakParams::SetThreshold)
		.def("GetThreshold", &RSStreakParams::GetThreshold)
		.def("SetSoftness", &RSStreakParams::SetSoftness)
		.def("GetSoftness", &RSStreakParams::GetSoftness)
		.def("SetTail", &RSStreakParams::SetTail)
		.def("GetTail", &RSStreakParams::GetTail)
		.def("SetIntensity", &RSStreakParams::SetIntensity)
		.def("GetIntensity", &RSStreakParams::GetIntensity)
		.def("SetNumber", &RSStreakParams::SetNumber)
		.def("GetNumber", &RSStreakParams::GetNumber)
		.def("SetAngle", &RSStreakParams::SetAngle)
		.def("GetAngle", &RSStreakParams::GetAngle)
		.def("CopySettingsFrom", &RSStreakParams::CopySettingsFrom);


	py::class_<RSFlareParams>(m, "RSFlareParams")
		.def("SetIsEnabled", &RSFlareParams::SetIsEnabled)
		.def("GetIsEnabled", &RSFlareParams::GetIsEnabled)
		.def("SetThreshold", &RSFlareParams::SetThreshold)
		.def("GetThreshold", &RSFlareParams::GetThreshold)
		.def("SetSoftness", &RSFlareParams::SetSoftness)
		.def("GetSoftness", &RSFlareParams::GetSoftness)
		.def("SetChromatic", &RSFlareParams::SetChromatic)
		.def("GetChromatic", &RSFlareParams::GetChromatic)
		.def("SetIntensity", &RSFlareParams::SetIntensity)
		.def("GetIntensity", &RSFlareParams::GetIntensity)
		.def("SetSize", &RSFlareParams::SetSize)
		.def("GetSize", &RSFlareParams::GetSize)
		.def("SetHalo", &RSFlareParams::SetHalo)
		.def("GetHalo", &RSFlareParams::GetHalo)
		.def("SetTint", &RSFlareParams::SetTint)
		.def("GetTint", &RSFlareParams::GetTint)
		.def("CopySettingsFrom", &RSFlareParams::CopySettingsFrom);

	py::class_<RSLUTParams>(m, "RSLUTParams")
		.def("SetIsEnabled", &RSLUTParams::SetIsEnabled)
		.def("GetIsEnabled", &RSLUTParams::GetIsEnabled)
		.def("SetFilename", &RSLUTParams::SetFilename)
		.def("GetFilename", &RSLUTParams::GetFilename)
		.def("SetApplyBeforeColorManagement", &RSLUTParams::SetApplyBeforeColorManagement)
		.def("GetApplyBeforeColorManagement", &RSLUTParams::GetApplyBeforeColorManagement)
		.def("SetIsLogInput", &RSLUTParams::SetIsLogInput)
		.def("GetIsLogInput", &RSLUTParams::GetIsLogInput)
		.def("SetStrength", &RSLUTParams::SetStrength)
		.def("CopySettingsFrom", &RSLUTParams::CopySettingsFrom);

	py::class_<RSColorControlParams>(m, "RSColorControlParams")
		.def("SetIsEnabled", &RSColorControlParams::SetIsEnabled)
		.def("GetIsEnabled", &RSColorControlParams::GetIsEnabled)
		.def("SetExposure", &RSColorControlParams::SetExposure)
		.def("GetExposure", &RSColorControlParams::GetExposure)
		.def("SetContrast", &RSColorControlParams::SetContrast)
		.def("GetContrast", &RSColorControlParams::GetContrast)
		.def("SetCurveR", &RSColorControlParams::SetCurveR)
		.def("GetCurveR", &RSColorControlParams::GetCurveR)
		.def("SetCurveG", &RSColorControlParams::SetCurveG)
		.def("GetCurveG", &RSColorControlParams::GetCurveG)
		.def("SetCurveB", &RSColorControlParams::SetCurveB)
		.def("GetCurveB", &RSColorControlParams::GetCurveB)
		.def("SetCurveRGB", &RSColorControlParams::SetCurveRGB)
		.def("GetCurveRGB", &RSColorControlParams::GetCurveRGB)
		.def("CopySettingsFrom", &RSColorControlParams::CopySettingsFrom);

	py::class_<RSColorManagementParams>(m, "RSColorManagementParams")
		.def("SetIsEnabled", &RSColorManagementParams::SetIsEnabled)
		.def("GetIsEnabled", &RSColorManagementParams::GetIsEnabled)
		.def("SetDisplayMode", &RSColorManagementParams::SetDisplayMode)
		.def("GetDisplayMode", &RSColorManagementParams::GetDisplayMode)
		.def("SetCustomGamma", &RSColorManagementParams::SetCustomGamma)
		.def("GetCustomGamma", &RSColorManagementParams::GetCustomGamma)
		.def("SetOCIOFilename", &RSColorManagementParams::SetOCIOFilename)
		.def("GetOCIOFilename", &RSColorManagementParams::GetOCIOFilename)
		.def("SetOCIOView", &RSColorManagementParams::SetOCIOView)
		.def("GetOCIOView", &RSColorManagementParams::GetOCIOView)
		.def("SetOCIODisplay", &RSColorManagementParams::SetOCIODisplay)
		.def("GetOCIODisplay", &RSColorManagementParams::GetOCIODisplay)
		.def("CopySettingsFrom", &RSColorManagementParams::CopySettingsFrom);

	py::class_<RSCamera>(m, "RSCamera")
		.def("SetNumStepsFromRendererOptions", &RSCamera::SetNumStepsFromRendererOptions)
		.def("IsTransformationBlurred", &RSCamera::IsTransformationBlurred)
		.def("SetName", &RSCamera::SetName)
		.def("GetName", &RSCamera::GetName)
		.def("SetType", &RSCamera::SetType)
		.def("GetTypeString", &RSCamera::GetTypeString)
		.def("DOFParams", &RSCamera::DOFParams)
		.def("PhysicalParams", &RSCamera::PhysicalParams)
		.def("LensDistortionParams", &RSCamera::LensDistortionParams)
		.def("BloomParams", &RSCamera::BloomParams)
		.def("StreakParams", &RSCamera::StreakParams)
		.def("FlareParams", &RSCamera::FlareParams)
		.def("ColorManagementParams", &RSCamera::ColorManagementParams)
		.def("LutParams", &RSCamera::LutParams)
		.def("ColorControlParams", &RSCamera::ColorControlParams)
		.def("GetNumTransformationSteps", &RSCamera::GetNumTransformationSteps)
		.def("SetMatrix", &RSCamera::SetMatrix)
		.def("GetMatrix", &RSCamera::GetMatrix)
		.def("SetFOVOrOrthogonalHeight", &RSCamera::SetFOVOrOrthogonalHeight)
		.def("GetFOVOrOrthogonalHeight", &RSCamera::GetFOVOrOrthogonalHeight)
		.def("SetAspect", &RSCamera::SetAspect)
		.def("GetAspect", &RSCamera::GetAspect)
		.def("SetPixelAspect", &RSCamera::SetPixelAspect)
		.def("GetPixelAspect", &RSCamera::GetPixelAspect)
		.def("SetNear", &RSCamera::SetNear)
		.def("GetNear", &RSCamera::GetNear)
		.def("SetFar", &RSCamera::SetFar)
		.def("GetFar", &RSCamera::GetFar)
		.def("SetShift", &RSCamera::SetShift)
		.def("GetShift", &RSCamera::GetShift)
		.def("SetApertureSize", &RSCamera::SetApertureSize)
		.def("GetApertureSize", &RSCamera::GetApertureSize)
		.def("SetCylindricalFOV", &RSCamera::SetCylindricalFOV)
		.def("GetCylindricalVerticalIsOrthogonal", &RSCamera::GetCylindricalVerticalIsOrthogonal)
		.def("GetCylindricalHorizontalFOV", &RSCamera::GetCylindricalHorizontalFOV)
		.def("GetCylindricalVerticalFOVOrOthogonalHeight", &RSCamera::GetCylindricalVerticalFOVOrOthogonalHeight)
		.def("SetFisheyeScale", &RSCamera::SetFisheyeScale)
		.def("GetFisheyeScaleX", &RSCamera::GetFisheyeScaleX)
		.def("GetFisheyeScaleY", &RSCamera::GetFisheyeScaleY)
		.def("SetStereoSeparation", &RSCamera::SetStereoSeparation)
		.def("GetStereoSeparation", &RSCamera::GetStereoSeparation)
		.def("SetStereoFocusEnable", &RSCamera::SetStereoFocusEnable)
		.def("GetStereoFocusEnable", &RSCamera::GetStereoFocusEnable)
		.def("SetStereoFocusDistance", &RSCamera::SetStereoFocusDistance)
		.def("GetStereoFocusDistance", &RSCamera::GetStereoFocusDistance)
		.def("SetStereoFOV", &RSCamera::SetStereoFOV)
		.def("GetStereoHorizontalFOV", &RSCamera::GetStereoHorizontalFOV)
		.def("GetStereoVerticalFOV", &RSCamera::GetStereoVerticalFOV)
		.def("SetStereoSphericalMode", &RSCamera::SetStereoSphericalMode)
		.def("GetStereoSphericalModeString", &RSCamera::GetStereoSphericalModeString)
		.def("GetViewMatrix", &RSCamera::GetViewMatrix)
		.def("GetProjectionMatrix", &RSCamera::GetProjectionMatrix)
		.def("SetFramebufferParams", &RSCamera::SetFramebufferParams)
		.def("GetFramebufferParams", &RSCamera::GetFramebufferParams);

	m.def("RS_Camera_GetDefaults", &RS_Camera_GetDefaults);
	m.def("RS_DOFParams_GetDefaults", &RS_DOFParams_GetDefaults);
	m.def("RS_PhysicalCameraParams_GetDefaults", &RS_PhysicalCameraParams_GetDefaults);
	m.def("RS_LensDistortionParams_GetDefaults", &RS_LensDistortionParams_GetDefaults);
	m.def("RS_BloomParams_GetDefaults", &RS_BloomParams_GetDefaults);
	m.def("RS_StreakParams_GetDefaults", &RS_StreakParams_GetDefaults);
	m.def("RS_FlareParams_GetDefaults", &RS_FlareParams_GetDefaults);
	m.def("RS_ColorManagementParams_GetDefaults", &RS_ColorManagementParams_GetDefaults);
	m.def("RS_LUTParams_GetDefaults", &RS_LUTParams_GetDefaults);
	m.def("RS_ColorControlParams_GetDefaults", &RS_ColorControlParams_GetDefaults);

	m.def("RS_Camera_New", &RS_Camera_New, py::return_value_policy::reference);
	m.def("RS_Camera_Delete", &RS_Camera_Delete);
	m.def("RS_DOFParams_New", &RS_DOFParams_New, py::return_value_policy::reference);
	m.def("RS_DOFParams_Delete", &RS_DOFParams_Delete);
	m.def("RS_ColorManagementParams_New", &RS_ColorManagementParams_New, py::return_value_policy::reference);
	m.def("RS_ColorManagementParams_Delete", &RS_ColorManagementParams_Delete);
	m.def("RS_LUTParams_New", &RS_LUTParams_New, py::return_value_policy::reference);
	m.def("RS_LUTParams_Delete", &RS_LUTParams_Delete);
	m.def("RS_ColorControlParams_New", &RS_ColorControlParams_New, py::return_value_policy::reference);
	m.def("RS_ColorControlParams_Delete", &RS_ColorControlParams_Delete);
	m.def("RS_PhysicalCameraParams_New", &RS_PhysicalCameraParams_New, py::return_value_policy::reference);
	m.def("RS_PhysicalCameraParams_Delete", &RS_PhysicalCameraParams_Delete);
	m.def("RS_LensDistortionParams_New", &RS_LensDistortionParams_New, py::return_value_policy::reference);
	m.def("RS_LensDistortionParams_Delete", &RS_LensDistortionParams_Delete);
	m.def("RS_BloomParams_New", &RS_BloomParams_New, py::return_value_policy::reference);
	m.def("RS_BloomParams_Delete", &RS_BloomParams_Delete);
	m.def("RS_StreakParams_New", &RS_StreakParams_New, py::return_value_policy::reference);
	m.def("RS_StreakParams_Delete", &RS_StreakParams_Delete);
	m.def("RS_FlareParams_New", &RS_FlareParams_New, py::return_value_policy::reference);
	m.def("RS_FlareParams_Delete", &RS_FlareParams_Delete);
}
