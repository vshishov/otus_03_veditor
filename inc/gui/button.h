#pragma once

#include "primitives/iprimitive.h"

#include <string>
#include <functional>

namespace svg {

/**
 * @brief Class button
 */ 
class CButton
{
public:
  CButton() = default;
  CButton(const std::string& a_strCaption) 
    : m_strCaption(a_strCaption)
  {

  }
  ~CButton() = default;

  std::function<void(void)> OnClick;

private:
  std::string m_strCaption;
};

} /* end svg::*/