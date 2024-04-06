#ifndef SUPERLOOP_HPP
#define SUPERLOOP_HPP

#include "utils.hpp"

#include "stdint.h"

class Superloop : private Noncopyable
{
  public:
    Superloop() = default;

    void init() const;
    bool run();

  private:
    uint16_t deadline{0};
};

#endif // SUPERLOOP_HPP
