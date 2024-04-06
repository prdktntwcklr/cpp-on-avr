#include "low_power.hpp"

#ifndef TEST

#include "avr/interrupt.h"
#include "avr/sleep.h"

#else

#define cli()               (void)(0);
#define sei()               (void)(0);
#define set_sleep_mode(...) (void)(0);
#define sleep_enable()      (void)(0);
#define sleep_cpu()         (void)(0);
#define sleep_disable()     (void)(0);

#endif

/**
 * @brief Initializes the low power mode.
 */
void LowPower::init() const
{
    set_sleep_mode(SLEEP_MODE_IDLE);
}

/**
 * @brief Enters the low power mode.
 *
 * @note  Sequence recommended in avr/sleep.h.
 */
void LowPower::enter() const
{
    cli();

    sleep_enable();
    sei();
    sleep_cpu();
    sleep_disable();

    sei();
}
