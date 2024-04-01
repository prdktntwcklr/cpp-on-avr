#pragma once

#include "stdint.h"

class Led
{
  public:
    using pin_type = uint8_t;
    using ddr_type = volatile uint8_t;
    using port_type = volatile uint8_t;

    Led(pin_type pin, ddr_type *ddr,
        port_type *port);                 // constructor
    Led(const Led &) = delete;            // no copies
    Led &operator=(const Led &) = delete; // no self-assignments

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
    bool led_on;           // led on/off state
};
