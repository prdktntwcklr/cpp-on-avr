#pragma once

#include "utils.hpp"

#include "stdint.h"

class Superloop : private Noncopyable
{
  public:
    Superloop();

    void init() const;
    bool run();

  private:
    uint16_t deadline;
};
