#include "RSHead.h"

using std::cout;
using std::endl;
namespace py = pybind11;

void bindRSStream(py::module&m)
{
	py::class_<RSStream>(m, "RSStream")
		.def("Read", &RSStream::Read)
		.def("Write", &RSStream::Write)
		.def("Flush", &RSStream::Flush)
		.def("Seek", &RSStream::Seek)
		.def("Tell", &RSStream::Tell);

	py::enum_<RSStream::SeekOrigin>(m, "SeekOrigin")
		.value("begin", RSStream::begin)
		.value("current", RSStream::current)
		.value("end", RSStream::end)
		.export_values();
}

void bindRSLockFile(py::module&m)
{
	py::class_<RSLockFile>(m, "RSLockFile")
		.def("Open", &RSLockFile::Open)
		.def("IsOpen", &RSLockFile::IsOpen)
		.def("Close", &RSLockFile::Close);

	m.def("RS_LockFile_New", &RS_LockFile_New, py::return_value_policy::reference);
	m.def("RS_LockFile_Delete", &RS_LockFile_Delete);
}

void bindRSRSTool(py::module&m)
{
	m.def("RS_Tool_Init", &RS_Tool_Init);
	m.def("RS_Tool_Shutdown", &RS_Tool_Shutdown);
	m.def("RS_Tool_GenerateShaderBinaries", &RS_Tool_GenerateShaderBinaries);
	m.def("RS_Tool_GenerateGUIFiles", &RS_Tool_GenerateGUIFiles);
}

void bindRSLog(py::module&m);//<--
void bindRSArray(py::module&m);//<--
void bindRSDatatypes(py::module&m);
void bindRSString(py::module&m);
void bindRSMatrix(py::module&m);
void bindRSTexture(py::module&m);
void bindRSLight(py::module&m);
void bindRSCurve(py::module&m);
void bindRSShaderNode(py::module&m);//<--
void bindRSMaterial(py::module&m);
void bindRSAttributes(py::module&m);
void bindRSCamera(py::module&m);
void bindRSTraceSet(py::module&m);
void bindRSVolumeGrid(py::module&m);
void bindRSProcedural(py::module&m);
void bindRSTextRenderer(py::module&m);
void bindRSUtilityFunctions(py::module&m);//<--
void bindRSColorCorrection(py::module&m);
void bindRSPostFx(py::module&m);
void bindRSRenderChannels(py::module&m);
void bindRSRSMesh(py::module&m);
void bindRSScene(py::module&m);
void bindRSProxy(py::module&m);//<--
void bindRSRenderer(py::module&m);

PYBIND11_MODULE(pyRedshift, m) {
	m.doc() = "redshift for python";
	py::module m1 = m.def_submodule("RS_Stream", "RS_Stream.h");
	py::module m2 = m.def_submodule("RS_Log", "RS_Log.h");
	py::module m3 = m.def_submodule("RS_Array", "RS_Array.h");
	py::module m4 = m.def_submodule("RS_Datatypes", "RS_Datatypes.h");
	py::module m5 = m.def_submodule("RS_String", "RS_String.h");
	py::module m6 = m.def_submodule("RS_Matrix", "RS_Matrix.h");
	py::module m7 = m.def_submodule("RS_Texture", "RS_Texture.h");
	py::module m8 = m.def_submodule("RS_Light", "RS_Light.h");
	py::module m9 = m.def_submodule("RS_Curve", "RS_Curve.h");
	py::module m10 = m.def_submodule("RS_ShaderNode", "RS_ShaderNode.h");
	py::module m11 = m.def_submodule("RS_Material", "RS_Material.h");
	py::module m12 = m.def_submodule("RS_Attributes", "RS_Attributes.h");
	py::module m13 = m.def_submodule("RS_Camera", "RS_Camera.h");
	py::module m14 = m.def_submodule("RS_TraceSet", "RS_TraceSet.h");
	py::module m15 = m.def_submodule("RS_VolumeGrid", "RS_VolumeGrid.h");
	py::module m16 = m.def_submodule("RS_Procedural", "RS_Procedural.h");
	py::module m17 = m.def_submodule("RS_TextRenderer", "RS_TextRenderer.h");
	py::module m18 = m.def_submodule("RS_UtilityFunctions", "RS_UtilityFunctions.h");
	py::module m19 = m.def_submodule("RS_ColorCorrection", "RS_ColorCorrection.h");
	py::module m20 = m.def_submodule("RS_PostFx", "RS_PostFx.h");
	py::module m21 = m.def_submodule("RS_RenderChannels", "RS_RenderChannels.h");
	py::module m22 = m.def_submodule("RS_Mesh", "RS_Mesh.h");
	py::module m23 = m.def_submodule("RS_Scene", "RS_Scene.h");
	py::module m24 = m.def_submodule("RS_Proxy", "RS_Proxy.h");
	py::module m25 = m.def_submodule("RS_Renderer", "RS_Renderer.h");
	py::module m26 = m.def_submodule("RS_LockFile", "RS_LockFile.h");
	py::module m27 = m.def_submodule("RS_Tool", "RS_Tool.h");
	

	bindRSStream(m1);
	bindRSLog(m2);
	bindRSArray(m3);
	bindRSDatatypes(m4);
	bindRSString(m5);
	bindRSMatrix(m6);
	bindRSTexture(m7);
	bindRSLight(m8);
	bindRSCurve(m9);
	bindRSShaderNode(m10);
	bindRSMaterial(m11);
	bindRSAttributes(m12);
	bindRSCamera(m13);
	bindRSTraceSet(m14);
	bindRSVolumeGrid(m15);
	bindRSProcedural(m16);
	bindRSTextRenderer(m17);
	bindRSUtilityFunctions(m18);
	bindRSColorCorrection(m19);
	bindRSPostFx(m20);
	bindRSRenderChannels(m21);
	bindRSRSMesh(m22);
	bindRSScene(m23);
	bindRSProxy(m24);
	bindRSRenderer(m25);
	bindRSLockFile(m26);
	bindRSRSTool(m27);
}