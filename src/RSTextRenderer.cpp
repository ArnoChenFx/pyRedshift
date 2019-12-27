#include "RSHead.h"
namespace py = pybind11;

void bindRSTextRenderer(py::module&m)
{
	py::class_<RSTextRenderer>(m, "RSTextRenderer")
		.def("SetFont", &RSTextRenderer::SetFont)
		.def("AddString", &RSTextRenderer::AddString)
		.def("AddQuad", &RSTextRenderer::AddQuad)
		.def("GetMaxVerticalIncrement", &RSTextRenderer::GetMaxVerticalIncrement)
		.def("ComputeBBoxSizeForString", &RSTextRenderer::ComputeBBoxSizeForString)
		.def("RenderQueuedEntriesToBlock", &RSTextRenderer::RenderQueuedEntriesToBlock)
		.def("ClearEntries", &RSTextRenderer::ClearEntries);

	m.def("RS_TextRenderer_New", &RS_TextRenderer_New, py::return_value_policy::reference);
	m.def("RS_TextRenderer_Delete", &RS_TextRenderer_Delete);
}
