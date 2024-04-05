#pragma once

#include "utils.hpp"

class LowPower : private Noncopyable
{
  public:
    LowPower() = default; // default constructor

    void init() const;
    void enter() const;
};
