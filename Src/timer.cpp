#include "timer.hpp"

#ifndef TEST

#include "avr/io.h"
#include "avr/interrupt.h"

#else

#define cli() (void)(0);
#define sei() (void)(0);

#endif

namespace
{
constexpr uint8_t TIMER_FULL_VAL{UINT8_C(255U)};
constexpr uint8_t TIMER_TICKS_VAL{UINT8_C(156U)};
constexpr uint8_t TIMER_RELOAD_VAL{TIMER_FULL_VAL - TIMER_TICKS_VAL};

} // namespace

// initialize static member variable
volatile uint16_t Timer::time_stamp{UINT16_C(0)};

/**
 * @brief Initializes the timer peripheral.
 */
void Timer::init() const
{
    // disable global interrupts
    cli();

    // enable Timer/Counter0 overflow interrupt
    TIMSK0 |= (1 << TOIE0);

    // enable global interrupts
    sei();

    // load Timer/Counter0 register
    TCNT0 = TIMER_RELOAD_VAL;

    // set clock to clk/64, this starts the timer
    TCCR0B |= ((1 << CS01) | (1 << CS00));
}

/**
 * @brief Sets the time_stamp to a specific value.
 */
void Timer::set_stamp(uint16_t stamp)
{
    // disable Timer/Counter0 overflow interrupt
    TIMSK0 &= ~(1 << TOIE0);

    time_stamp = stamp;

    // enable Timer/Counter0 overflow interrupt
    TIMSK0 |= (1 << TOIE0);
}

/**
 * @brief Returns the current time_stamp value.
 */
uint16_t Timer::get_stamp() const
{
    // disable Timer/Counter0 overflow interrupt
    TIMSK0 &= ~(1 << TOIE0);

    // store current time stamp
    auto curr_time = uint16_t{time_stamp};

    // enable Timer/Counter0 overflow interrupt
    TIMSK0 |= (1 << TOIE0);

    return curr_time;
}

/**
 * @brief Returns TRUE if the deadline has been reached or passed.
 */
bool Timer::deadline_reached(uint16_t deadline) const
{
    return (static_cast<int16_t>(time_stamp - deadline) >= 0);
}

/**
 * @brief Timer/Counter0 Overflow Interrupt Implementation
 */
void timer_interrupt()
{
    Timer::time_stamp += 10;

    // reload Timer/Counter0 register
    TCNT0 = TIMER_RELOAD_VAL;
}

/**
 * @brief Timer/Counter0 Overflow Interrupt Wrapper
 */
#ifndef TEST
ISR(TIMER0_OVF_vect)
#else
void Timer::testable_isr_timer0_ovf_vect()
#endif
{
    timer_interrupt();
}
