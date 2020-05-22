#include "core/editormodel.h"
#include "core/editorview.h"
#include "core/editorcontroller.h"

#include <iostream>
#include <memory>

int main(int, const char**) 
{
  std::shared_ptr<svg::CEditorModel> pModel = std::make_shared<svg::CEditorModel>();  
  std::shared_ptr<svg::CEditorController> pController = std::make_shared<svg::CEditorController>(pModel);
  std::shared_ptr<svg::CEditorView> pView = std::make_shared<svg::CEditorView>(pModel, pController);

  pController->Run();

  return 0;
}