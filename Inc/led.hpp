#pragma once

#include "stdint.h"

class Led
{
  private:
    uint8_t pin;
    volatile uint8_t *ddr;
    volatile uint8_t *port;

  public:
    Led(uint8_t led_pin, volatile uint8_t *led_ddr,
        volatile uint8_t *led_port);      // constructor
    Led(const Led &) = delete;            // no copies
    Led &operator=(const Led &) = delete; // no self-assignments

    void init() const;
    void turn_on() const;
    void turn_off() const;
    void toggle() const;
    bool is_on() const;
    bool is_off() const;
};
