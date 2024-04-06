#ifndef TIMER_HPP
#define TIMER_HPP

#include "utils.hpp"

#include "stdint.h"

class Timer : private Noncopyable
{
  public:
    Timer() = default; // default constructor

    void init() const;
    void set_stamp(uint16_t stamp);
    uint16_t get_stamp() const;
    bool deadline_reached(uint16_t deadline) const;

#ifdef TEST
    void testable_isr_timer0_ovf_vect();
#endif

  private:
    static volatile uint16_t time_stamp;

    friend void timer_interrupt();
};

#endif // TIMER_HPP
