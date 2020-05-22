#pragma once

#include "tools/itool.h"
#include "primitives/point.h"

namespace svg {

class CPointTool : public ITool
{
public:
  CPointTool() = default;

  std::shared_ptr<IPrimitive> Create() override
  {
    return std::make_shared<CPoint>();
  }

  virtual ~CPointTool() = default;
};

} /* end svg::*/