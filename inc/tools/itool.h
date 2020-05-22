#pragma once

#include "primitives/iprimitive.h"

namespace svg {

class ITool
{
public:  
  virtual std::shared_ptr<IPrimitive> Create() = 0;
  virtual ~ITool() = default;
};

} /* end svg::*/