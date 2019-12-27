#include "RSHead.h"
namespace py = pybind11;

void bindRSLog(py::module&m)
{
	py::enum_<RSLogLevel>(m, "RSLogLevel")
		.value("Off", Off)
		.value("Error", Error)
		.value("Warning", Warning)
		.value("Info", Info)
		.value("Detailed", Detailed)
		.value("Debug", Debug)
		.value("DebugVerbose", DebugVerbose)
		.value("InternalOnly", InternalOnly)
		.value("MaxLevel", MaxLevel)
		.export_values();

	py::enum_<RSLogLevelFilter>(m, "RSLogLevelFilter")
		.value("LogFilter_Error", LogFilter_Error)
		.value("LogFilter_Warning", LogFilter_Warning)
		.value("LogFilter_Info", LogFilter_Info)
		.value("LogFilter_Detailed", LogFilter_Detailed)
		.value("LogFilter_Debug", LogFilter_Debug)
		.value("LogFilter_DebugVerbose", LogFilter_DebugVerbose)
		.value("LogFilter_InternalOnly", LogFilter_InternalOnly)
		.export_values();

	//m.def("RS_Log", &RS_Log);

	//py::class_<RSLogSink>(m, "RSLogSink")
	//	.def(py::init<RSLogLevel, const char* , size_t>());
	//

	m.def("RS_Log_Init", &RS_Log_Init);
	m.def("RS_Log_Shutdown", &RS_Log_Shutdown);
	m.def("RS_Log_AddSink", &RS_Log_AddSink);
	m.def("RS_Log_SetTimeLogging", &RS_Log_SetTimeLogging);
	m.def("RS_Log_SetLevelLogging", &RS_Log_SetLevelLogging);
	m.def("RS_Log_IsMuted", &RS_Log_IsMuted);
	m.def("RS_Log_Mute", &RS_Log_Mute);
	m.def("RS_Log_Unmute", &RS_Log_Unmute);
	m.def("RS_Log_SetReportingLevel", &RS_Log_SetReportingLevel);
	m.def("RS_Log_CurrentReportingLevel", &RS_Log_CurrentReportingLevel);
	m.def("RS_Log_DefaultReportingLevel", &RS_Log_DefaultReportingLevel);
	m.def("RS_Log_LevelToString", &RS_Log_LevelToString);
	m.def("RS_Log_HtmlLogPath", &RS_Log_HtmlLogPath);
}
