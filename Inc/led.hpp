#pragma once

#include "utils.hpp"

#include "stdint.h"

class Led : private Noncopyable
{
  public:
    using pin_type = uint8_t;
    using ddr_type = volatile uint8_t;
    using port_type = volatile uint8_t;

    explicit Led(pin_type pin, ddr_type *ddr,
                 port_type *port); // constructor

    void init();
    void turn_on();
    void turn_off();
    void toggle();
    bool is_on() const;
    bool is_off() const;

  private:
    const pin_type pin;    // led pin
    ddr_type *const ddr;   // led data direction register
    port_type *const port; // led port
    bool led_on{false};    // led on/off state
};
