#include "RSHead.h"
namespace py = pybind11;

void bindRSShaderNode(py::module&m)
{
	py::class_<RSShaderNode, std::unique_ptr<RSShaderNode, py::nodelete>>(m, "RSShaderNode")
		.def("GetParameterCount", &RSShaderNode::GetParameterCount)
		.def("GetParameterName", &RSShaderNode::GetParameterName)
		.def("GetParameterIndex", &RSShaderNode::GetParameterIndex)
		.def("GetParameterNumVectorComponents", &RSShaderNode::GetParameterNumVectorComponents)
		.def("GetOutputCount", &RSShaderNode::GetOutputCount)
		.def("GetOutputName", &RSShaderNode::GetOutputName)
		.def("GetOutputIndex", &RSShaderNode::GetOutputIndex)
		.def("GetOutputNumVectorComponents", &RSShaderNode::GetOutputNumVectorComponents)
		.def("GetOutputIsAColor", &RSShaderNode::GetOutputIsAColor)
		.def("BeginUpdate", &RSShaderNode::BeginUpdate)
		.def("EndUpdate", &RSShaderNode::EndUpdate)
		.def("SetParameterData", py::overload_cast<unsigned int, const RSCurve*>(&RSShaderNode::SetParameterData))//===========
		.def("SetParameterData", py::overload_cast<unsigned int, const RSTexture*>(&RSShaderNode::SetParameterData))
		.def("SetParameterData", py::overload_cast<unsigned int, const RSUDIMTexture*>(&RSShaderNode::SetParameterData))
		.def("SetParameterData", py::overload_cast<unsigned int, const RSUVTILETexture*>(&RSShaderNode::SetParameterData))
		.def("SetParameterData", py::overload_cast<unsigned int, const RSIndexedTexture*>(&RSShaderNode::SetParameterData))
		.def("SetParameterData", py::overload_cast<unsigned int, const RSLight*>(&RSShaderNode::SetParameterData))
		.def("SetParameterData", py::overload_cast<unsigned int, const char*>(&RSShaderNode::SetParameterData))
		.def("SetParameterData", py::overload_cast<unsigned int, const int>(&RSShaderNode::SetParameterData))
		.def("SetParameterData", py::overload_cast<unsigned int, const float>(&RSShaderNode::SetParameterData))
		.def("SetParameterData", py::overload_cast<unsigned int, const bool>(&RSShaderNode::SetParameterData))
		.def("SetParameterData", py::overload_cast<unsigned int, const RSVector2&>(&RSShaderNode::SetParameterData))
		.def("SetParameterData", py::overload_cast<unsigned int, const RSVector3&>(&RSShaderNode::SetParameterData))
		.def("SetParameterData", py::overload_cast<unsigned int, const RSVector4&>(&RSShaderNode::SetParameterData))
		.def("SetParameterData", py::overload_cast<unsigned int, const RSUInt4&>(&RSShaderNode::SetParameterData))
		.def("SetParameterData", py::overload_cast<unsigned int, const RSMatrix4x4&>(&RSShaderNode::SetParameterData))
		.def("SetParameterData", py::overload_cast<unsigned int, const RSString&>(&RSShaderNode::SetParameterData))
		.def("SetParameterNode", py::overload_cast<unsigned int, RSShaderNode*, unsigned int>(&RSShaderNode::SetParameterNode))
		.def("SetParameterNode", py::overload_cast<const char*, RSShaderNode*, const char*>(&RSShaderNode::SetParameterNode))
		.def("SetParameterNode", py::overload_cast<unsigned int, RSShaderNode*, const char*>(&RSShaderNode::SetParameterNode))
		.def("SetMixedParameterData", py::overload_cast<unsigned int, float, const float, RSShaderNode*, unsigned int>(&RSShaderNode::SetMixedParameterData))
		.def("SetMixedParameterData", py::overload_cast<unsigned int, float, const RSVector4&, RSShaderNode*, unsigned int>(&RSShaderNode::SetMixedParameterData))
		.def("SetAltMonoParameterNode", &RSShaderNode::SetAltMonoParameterNode)
		.def("AddVertexAttributeMeshAssociation", py::overload_cast<unsigned int, const char*, const char*>(&RSShaderNode::AddVertexAttributeMeshAssociation))
		.def("AddVertexAttributeMeshAssociation", py::overload_cast<const char*, const char*, const char*>(&RSShaderNode::AddVertexAttributeMeshAssociation))
		.def("AddAttributeAssociation", py::overload_cast<unsigned int, const char*>(&RSShaderNode::AddAttributeAssociation))
		.def("AddAttributeAssociation", py::overload_cast<const char*, const char*>(&RSShaderNode::AddAttributeAssociation))
		.def("GetAttributeSpaceUsedCount", &RSShaderNode::GetAttributeSpaceUsedCount)
		.def("GetAttributeSpaceInfo", &RSShaderNode::GetAttributeSpaceInfo)
		.def("CopyParameters", &RSShaderNode::CopyParameters)
		.def("GetScalar", &RSShaderNode::GetScalar)
		.def("GetVector", &RSShaderNode::GetVector)
		.def("GetBool", &RSShaderNode::GetBool)
		.def("GetInteger", &RSShaderNode::GetInteger)
		.def("GetNode", &RSShaderNode::GetNode, py::return_value_policy::reference)
		.def("GetConnectedOutputName", &RSShaderNode::GetConnectedOutputName)
		.def("GetDefault", &RSShaderNode::GetDefault)
		.def("IsParameterPrivate", &RSShaderNode::IsParameterPrivate)
		.def("IsParameterDCCConvertable", &RSShaderNode::IsParameterDCCConvertable)
		.def("IsParameterTexturable", &RSShaderNode::IsParameterTexturable)
		.def("IsParameterAColor", &RSShaderNode::IsParameterAColor)
		.def("IsParameterAttributeSpaceID", &RSShaderNode::IsParameterAttributeSpaceID)
		.def("IsParameterAttributeUVSpaceID", &RSShaderNode::IsParameterAttributeUVSpaceID)
		.def("IsParameterAttributeNonUVSpaceID", &RSShaderNode::IsParameterAttributeNonUVSpaceID)
		.def("IsParameterATexture", &RSShaderNode::IsParameterATexture)
		.def("IsParameterACurve", &RSShaderNode::IsParameterACurve)
		.def("IsParameterAMonoCurve", &RSShaderNode::IsParameterAMonoCurve)
		.def("IsParameterAColorCurve", &RSShaderNode::IsParameterAColorCurve)
		.def("IsParameterAnIESProfile", &RSShaderNode::IsParameterAnIESProfile)
		.def("IsParameterBumpInput", &RSShaderNode::IsParameterBumpInput)
		.def("IsParameterMixedInput", &RSShaderNode::IsParameterMixedInput)
		.def("GetTextureSlotOrdinal", &RSShaderNode::GetTextureSlotOrdinal)
		.def("RequiresBumpNodeForBumpMapping", &RSShaderNode::RequiresBumpNodeForBumpMapping)
		.def("RequiresDisplacementNodeForDisplacementMapping", &RSShaderNode::RequiresDisplacementNodeForDisplacementMapping)
		.def("IsParameterRequiringConversionNodeForScalarToColorConnection", &RSShaderNode::IsParameterRequiringConversionNodeForScalarToColorConnection)
		.def("DisconnectFromParentResources", &RSShaderNode::DisconnectFromParentResources)
		.def("SupportsTiledTextures", &RSShaderNode::SupportsTiledTextures)
		.def("RequiresMeshHierarchyUpdateOnRelease", &RSShaderNode::RequiresMeshHierarchyUpdateOnRelease)
		.def("GetResourceName", &RSShaderNode::GetResourceName)
		.def("GetClassName", &RSShaderNode::GetClassName)
		.def("GetClassName3dsMax", &RSShaderNode::GetClassName3dsMax)
		.def("IncrementRefCounter", &RSShaderNode::IncrementRefCounter)
		.def("DecrementRefCounter", &RSShaderNode::DecrementRefCounter)
		//.def("ParameterDataToString", &RSShaderNode::ParameterDataToString)
		.def("ParameterDataToString", [](RSShaderNode &self, unsigned int paramIndex)
			{   char data[256];
				return self.ParameterDataToString(paramIndex, data); });


	m.def("RS_ShaderNode_Get", &RS_ShaderNode_Get, py::return_value_policy::reference);
	m.def("RS_ShaderNode_Release", &RS_ShaderNode_Release);
	m.def("RS_ShaderNode_Find", &RS_ShaderNode_Find, py::return_value_policy::reference);
	m.def("RS_ShaderNode_VertexAttributeMeshAssociationsChanged", &RS_ShaderNode_VertexAttributeMeshAssociationsChanged);
	m.def("RS_ShaderNode_GetAllShaderClassNames", &RS_ShaderNode_GetAllShaderClassNames);

	py::enum_<EGUIShaderType>(m, "EGUIShaderType")
		.value("RS_GUISHADERTYPE_MATERIAL", RS_GUISHADERTYPE_MATERIAL)
		.value("RS_GUISHADERTYPE_TEXTURE", RS_GUISHADERTYPE_TEXTURE)
		.value("RS_GUISHADERTYPE_UTILITY", RS_GUISHADERTYPE_UTILITY)
		.value("RS_GUISHADERTYPE_ENVIRONMENT", RS_GUISHADERTYPE_ENVIRONMENT)
		.value("RS_GUISHADERTYPE_LIGHT", RS_GUISHADERTYPE_LIGHT)
		.value("RS_GUISHADERTYPE_VOLUME", RS_GUISHADERTYPE_VOLUME)
		.value("RS_GUISHADERTYPE_MATH", RS_GUISHADERTYPE_MATH)
		.value("RS_GUISHADERTYPE_COLOR", RS_GUISHADERTYPE_COLOR)
		.export_values();

	py::enum_<EGUIShaderParamSceneScaleType>(m, "EGUIShaderParamSceneScaleType")
		.value("RS_GUISHADERPARAMSCENESCALETYPE_NONE", RS_GUISHADERPARAMSCENESCALETYPE_NONE)
		.value("RS_GUISHADERPARAMSCENESCALETYPE_MULTIPLY", RS_GUISHADERPARAMSCENESCALETYPE_MULTIPLY)
		.value("RS_GUISHADERPARAMSCENESCALETYPE_DIVIDE", RS_GUISHADERPARAMSCENESCALETYPE_DIVIDE)
		.export_values();

	py::enum_<EGUIShaderParamType>(m, "EGUIShaderParamType")
		.value("RS_GUISHADERPARAMTYPE_COLOR_RGB", RS_GUISHADERPARAMTYPE_COLOR_RGB)
		.value("RS_GUISHADERPARAMTYPE_COLOR_RGBA", RS_GUISHADERPARAMTYPE_COLOR_RGBA)
		.value("RS_GUISHADERPARAMTYPE_FLOAT4", RS_GUISHADERPARAMTYPE_FLOAT4)
		.value("RS_GUISHADERPARAMTYPE_FLOAT3", RS_GUISHADERPARAMTYPE_FLOAT3)
		.value("RS_GUISHADERPARAMTYPE_FLOAT2", RS_GUISHADERPARAMTYPE_FLOAT2)
		.value("RS_GUISHADERPARAMTYPE_FLOAT", RS_GUISHADERPARAMTYPE_FLOAT)
		.value("RS_GUISHADERPARAMTYPE_BOOL", RS_GUISHADERPARAMTYPE_BOOL)
		.value("RS_GUISHADERPARAMTYPE_INT", RS_GUISHADERPARAMTYPE_INT)
		.value("RS_GUISHADERPARAMTYPE_UINT4", RS_GUISHADERPARAMTYPE_UINT4)
		.value("RS_GUISHADERPARAMTYPE_MATRIX4X4", RS_GUISHADERPARAMTYPE_MATRIX4X4)
		.value("RS_GUISHADERPARAMTYPE_CURVE", RS_GUISHADERPARAMTYPE_CURVE)
		.value("RS_GUISHADERPARAMTYPE_TEXTURE", RS_GUISHADERPARAMTYPE_TEXTURE)
		.value("RS_GUISHADERPARAMTYPE_LIGHT", RS_GUISHADERPARAMTYPE_LIGHT)
		.value("RS_GUISHADERPARAMTYPE_TSPACE", RS_GUISHADERPARAMTYPE_TSPACE)
		.value("RS_GUISHADERPARAMTYPE_CSPACE", RS_GUISHADERPARAMTYPE_CSPACE)
		.value("RS_GUISHADERPARAMTYPE_UV", RS_GUISHADERPARAMTYPE_UV)
		.value("RS_GUISHADERPARAMTYPE_UVW", RS_GUISHADERPARAMTYPE_UVW)
		.value("RS_GUISHADERPARAMTYPE_COLORRAMP", RS_GUISHADERPARAMTYPE_COLORRAMP)
		.value("RS_GUISHADERPARAMTYPE_STRING", RS_GUISHADERPARAMTYPE_STRING)
		.value("RS_GUISHADERPARAMTYPE_CAMERAPICKER", RS_GUISHADERPARAMTYPE_CAMERAPICKER)
		.value("RS_GUISHADERPARAMTYPE_AOVNAME", RS_GUISHADERPARAMTYPE_AOVNAME)
		.value("RS_GUISHADERPARAMTYPE_LAYERNAME", RS_GUISHADERPARAMTYPE_LAYERNAME)
		.export_values();


	py::class_<RSShaderRemappedParamInfo, std::unique_ptr<RSShaderRemappedParamInfo, py::nodelete>>(m, "RSShaderRemappedParamInfo")
		.def("GetName", &RSShaderRemappedParamInfo::GetName)
		.def("GetRemappedName", &RSShaderRemappedParamInfo::GetRemappedName);

	py::class_<RSShaderInputParamInfo, std::unique_ptr<RSShaderInputParamInfo, py::nodelete>>(m, "RSShaderInputParamInfo")
		.def("GetPrettyName", &RSShaderInputParamInfo::GetPrettyName)
		.def("GetInternalName", &RSShaderInputParamInfo::GetInternalName)
		.def("GetGUIType", &RSShaderInputParamInfo::GetGUIType)
		.def("GetInternalType", &RSShaderInputParamInfo::GetInternalType)
		.def("GetDescription", &RSShaderInputParamInfo::GetDescription)
		.def("GetInternalUID", &RSShaderInputParamInfo::GetInternalUID)
		.def("GetSoftMinMaxValue", py::overload_cast<float&, float&>(&RSShaderInputParamInfo::GetSoftMinMaxValue, py::const_))
		.def("GetSoftMinMaxValue", py::overload_cast<int&, int&>(&RSShaderInputParamInfo::GetSoftMinMaxValue, py::const_))
		.def("GetHardMinMaxValue", py::overload_cast<float&, float&>(&RSShaderInputParamInfo::GetHardMinMaxValue, py::const_))
		.def("GetHardMinMaxValue", py::overload_cast<int&, int&>(&RSShaderInputParamInfo::GetHardMinMaxValue, py::const_))
		.def("IsTexturable", &RSShaderInputParamInfo::IsTexturable)
		.def("IsLogarithmicSlider", &RSShaderInputParamInfo::IsLogarithmicSlider)
		.def("IsVisibleInGUI", &RSShaderInputParamInfo::IsVisibleInGUI)
		.def("IsNoVisibleValuesInGUI", &RSShaderInputParamInfo::IsNoVisibleValuesInGUI)
		.def("GetNumEnums", &RSShaderInputParamInfo::GetNumEnums)
		.def("GetEnumEntry", &RSShaderInputParamInfo::GetEnumEntry)
		.def("GetNumDefaultValues", &RSShaderInputParamInfo::GetNumDefaultValues)
		.def("GetDefaultValue", py::overload_cast<int, float&>(&RSShaderInputParamInfo::GetDefaultValue, py::const_))
		.def("GetDefaultValue", py::overload_cast<int, int&>(&RSShaderInputParamInfo::GetDefaultValue, py::const_));

	py::class_<RSShaderOutputParamInfo, std::unique_ptr<RSShaderOutputParamInfo, py::nodelete>>(m, "RSShaderOutputParamInfo")
		.def("GetPrettyName", &RSShaderOutputParamInfo::GetPrettyName)
		.def("GetInternalName", &RSShaderOutputParamInfo::GetInternalName)
		.def("GetGUIType", &RSShaderOutputParamInfo::GetGUIType)
		.def("GetInternalType", &RSShaderOutputParamInfo::GetInternalType)
		.def("GetDescription", &RSShaderOutputParamInfo::GetDescription)
		.def("GetInternalUID", &RSShaderOutputParamInfo::GetInternalUID);

	py::enum_<EGUIPropertyType>(m, "EGUIPropertyType")
		.value("RS_GUIPROPERTYTYPE_TAB", RS_GUIPROPERTYTYPE_TAB)
		.value("RS_GUIPROPERTYTYPE_SUBTAB_BEGIN", RS_GUIPROPERTYTYPE_SUBTAB_BEGIN)
		.value("RS_GUIPROPERTYTYPE_SUBTAB_END", RS_GUIPROPERTYTYPE_SUBTAB_END)
		.value("RS_GUIPROPERTYTYPE_PARAMBLOCK", RS_GUIPROPERTYTYPE_PARAMBLOCK)
		.export_values();

	py::class_<RSGUILayoutProperty, std::unique_ptr<RSGUILayoutProperty, py::nodelete>>(m, "RSGUILayoutProperty")
		.def("GetPropertyType", &RSGUILayoutProperty::GetPropertyType)
		.def("GetPropertyName", &RSGUILayoutProperty::GetPropertyName)
		.def("GetNumParamBlockEntries", &RSGUILayoutProperty::GetNumParamBlockEntries)
		.def("GetInternalType", &RSGUILayoutProperty::GetParamBlockEntry, py::return_value_policy::reference);

	py::class_<RSPresetParamInfo, std::unique_ptr<RSPresetParamInfo, py::nodelete>>(m, "RSPresetParamInfo")
		.def("GetInternalName", &RSPresetParamInfo::GetInternalName)
		.def("GetInternalUID", &RSPresetParamInfo::GetInternalUID)
		.def("GetInternalType", &RSPresetParamInfo::GetInternalType)
		.def("GetSceneScaleType", &RSPresetParamInfo::GetSceneScaleType)
		.def("GetNumValues", &RSPresetParamInfo::GetNumValues)
		.def("GetValue", py::overload_cast<int, float&>(&RSPresetParamInfo::GetValue, py::const_))
		.def("GetValue", py::overload_cast<int, int&>(&RSPresetParamInfo::GetValue, py::const_));

	py::class_<RSPresetInfo, std::unique_ptr<RSPresetInfo, py::nodelete>>(m, "RSPresetInfo")
		.def("GetNumParameters", &RSPresetInfo::GetNumParameters)
		.def("GetParameterPresetInfo", &RSPresetInfo::GetParameterPresetInfo, py::return_value_policy::reference);

	py::class_<RSParamEnableState, std::unique_ptr<RSParamEnableState, py::nodelete>>(m, "RSParamEnableState")
		.def_readwrite("m_internalName", &RSParamEnableState::m_internalName)
		.def_readwrite("m_bEnabled", &RSParamEnableState::m_bEnabled);

	py::class_<RSShaderGUIInfo, std::unique_ptr<RSShaderGUIInfo, py::nodelete>>(m, "RSShaderGUIInfo")
		.def("GetType", &RSShaderGUIInfo::GetType)
		.def("GetPrettyName", &RSShaderGUIInfo::GetPrettyName)
		.def("GetName", &RSShaderGUIInfo::GetName)
		.def("GetShaderClassName", &RSShaderGUIInfo::GetShaderClassName)
		.def("GetDescription", &RSShaderGUIInfo::GetDescription)
		.def("CanHaveShaderBall", &RSShaderGUIInfo::CanHaveShaderBall)
		.def("IsLegacy", &RSShaderGUIInfo::IsLegacy)
		.def("GetNumInputParameters", &RSShaderGUIInfo::GetNumInputParameters)
		.def("GetInputParameterInfo", &RSShaderGUIInfo::GetInputParameterInfo, py::return_value_policy::reference)
		.def("GetNumOutputParameters", &RSShaderGUIInfo::GetNumOutputParameters)
		.def("GetOutputParameterInfo", &RSShaderGUIInfo::GetOutputParameterInfo, py::return_value_policy::reference)
		.def("GetNumGUILayoutProperties", &RSShaderGUIInfo::GetNumGUILayoutProperties)
		.def("GetGUILayoutProperty", &RSShaderGUIInfo::GetGUILayoutProperty, py::return_value_policy::reference)
		.def("GetParametersThatAffectGhosting", &RSShaderGUIInfo::GetParametersThatAffectGhosting)
		.def("GetParametersGhostedState", &RSShaderGUIInfo::GetParametersGhostedState)
		.def("GetParametersThatAffectHiding", &RSShaderGUIInfo::GetParametersThatAffectHiding)
		.def("GetParametersHiddenState", &RSShaderGUIInfo::GetParametersHiddenState)
		.def("GetPresetEnumParameterNames", &RSShaderGUIInfo::GetPresetEnumParameterNames)
		.def("GetPresetParameterInfo", &RSShaderGUIInfo::GetPresetParameterInfo, py::return_value_policy::reference)
		.def("GetPresetParameterAffectingNames", &RSShaderGUIInfo::GetPresetParameterAffectingNames)
		.def("SetPresetParameterAffectingUIDs", &RSShaderGUIInfo::SetPresetParameterAffectingUIDs);

	py::class_<RSShaderPackageGUIInfo, std::unique_ptr<RSShaderPackageGUIInfo, py::nodelete>>(m, "RSShaderPackageGUIInfo")
		.def("GetNumShaders", &RSShaderPackageGUIInfo::GetNumShaders)
		.def("GetShaderInfo", py::overload_cast<int>(&RSShaderPackageGUIInfo::GetShaderInfo, py::const_), py::return_value_policy::reference)
		.def("GetShaderInfo", py::overload_cast<const char*>(&RSShaderPackageGUIInfo::GetShaderInfo, py::const_), py::return_value_policy::reference);

	m.def("RS_ShaderPackageInfo_New", &RS_ShaderPackageInfo_New, py::return_value_policy::reference);
	m.def("RS_ShaderPackageInfo_Delete", &RS_ShaderPackageInfo_Delete);

	py::class_<RSShaderTranslationInfo, std::unique_ptr<RSShaderTranslationInfo, py::nodelete>>(m, "RSShaderTranslationInfo")
		.def("GetShaderClassName", &RSShaderTranslationInfo::GetShaderClassName)
		.def("IsDCCNode", &RSShaderTranslationInfo::IsDCCNode)
		.def("GetNumRemappedInputParams", &RSShaderTranslationInfo::GetNumRemappedInputParams)
		.def("GetNumRemappedOutputParams", &RSShaderTranslationInfo::GetNumRemappedOutputParams)
		.def("GetRemappedInputInfo", &RSShaderTranslationInfo::GetRemappedInputInfo, py::return_value_policy::reference)
		.def("FindRemappedInputInfo", &RSShaderTranslationInfo::FindRemappedInputInfo, py::return_value_policy::reference)
		.def("GetRemappedOutputInfo", &RSShaderTranslationInfo::GetRemappedOutputInfo, py::return_value_policy::reference)
		.def("FindRemappedOutputInfo", &RSShaderTranslationInfo::FindRemappedOutputInfo, py::return_value_policy::reference);

	py::class_<RSShaderPackageTranslationInfo, std::unique_ptr<RSShaderPackageTranslationInfo, py::nodelete>>(m, "RSShaderPackageTranslationInfo")
		.def("FindShader", &RSShaderPackageTranslationInfo::FindShader, py::return_value_policy::reference);

	m.def("RS_ShaderTranslationInfo_New", &RS_ShaderTranslationInfo_New, py::return_value_policy::reference);
	m.def("RS_ShaderTranslationInfo_Delete", &RS_ShaderTranslationInfo_Delete);

	m.def("RS_ComputeColorAdjustMatrix", &RS_ComputeColorAdjustMatrix);
	m.def("RS_GetIdentityColorMatrix", &RS_GetIdentityColorMatrix);

}