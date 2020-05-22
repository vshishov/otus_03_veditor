#include "core/editorview.h"
#include "tools/pointtool.h"
#include "tools/linetool.h"

namespace svg {

CEditorView::CEditorView(std::shared_ptr<CEditorModel> a_pModel, std::shared_ptr<CEditorController> a_pController)
  : m_pModel(a_pModel)
  , m_pController(a_pController)
{
  assert(m_pModel);
  assert(m_pModel);
  m_pModel->AddObserver(this);
  m_pCanvas = std::make_shared<CConsoleCanvas>();

  m_pBtnOpen->OnClick = std::bind(&CEditorView::OnClickBtnOpen, this);
  m_pBtnSave->OnClick = std::bind(&CEditorView::OnClickBtnSave, this);
  m_pBtnClear->OnClick = std::bind(&CEditorView::OnClickBtnClear, this);

  m_pBtnColor->OnClick = std::bind(&CEditorView::OnClickBtnColor, this);

  m_pBtnToolPoint->OnClick = std::bind(&CEditorView::OnClickBtnToolPoint, this);
  m_pBtnToolLine->OnClick = std::bind(&CEditorView::OnClickBtnToolPoint, this);
  m_pBtnToolDelete->OnClick = std::bind(&CEditorView::OnClickBtnToolDelete, this);
}

void CEditorView::Update()
{
  m_pModel->Draw(m_pCanvas);
}

void CEditorView::OnClickBtnOpen()
{
  m_pController->Open("test");
}

void CEditorView::OnClickBtnSave()
{
  m_pController->Save();
}

void CEditorView::OnClickBtnClear()
{
  m_pController->Clear();
}

void CEditorView::OnClickBtnColor()
{
  m_pController->SetColor(CColor::COLLOR_RED);
}

void CEditorView::OnClickBtnToolPoint()
{
  m_pController->SetTool(std::make_unique<CPointTool>());
}

void CEditorView::OnClickBtnToolLine()
{
  m_pController->SetTool(std::make_unique<CLineTool>());
}

void CEditorView::OnClickBtnToolDelete()
{
  m_pController->DeletePrimitive();
}


} /*end svg::*/