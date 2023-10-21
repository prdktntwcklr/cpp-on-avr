#pragma once

#include "stdint.h"

class Superloop
{
  public:
    Superloop() = default; // default constructor

    Superloop(const Superloop&) = delete; // no copies
    Superloop& operator=(const Superloop&) = delete; // no self-assignments
    void init() const;
    bool run();
  
  private:
    uint16_t deadline {0};
};
