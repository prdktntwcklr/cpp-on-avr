#pragma once

#include "stdint.h"

class Timer
{
  public:
    Timer() = default;                        // default constructor
    Timer(const Timer &) = delete;            // no copies
    Timer &operator=(const Timer &) = delete; // no self-assignments

    void init() const;
    void set_stamp(uint16_t stamp);
    uint16_t get_stamp() const;
    bool deadline_reached(uint16_t deadline) const;

  private:
    static volatile uint16_t time_stamp;

    friend void timer_interrupt();
};
