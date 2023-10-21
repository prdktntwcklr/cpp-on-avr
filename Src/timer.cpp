/* timer.c */

#include "timer.h"

#ifndef TEST
#include "avr/io.h"
#include "avr/interrupt.h"
#else
#include "testable_mcu_registers.h"
#define cli() (void)(0);
#define sei() (void)(0);
#endif

#define TIMER_FULL_VAL   (255U)
#define TIMER_TICKS_VAL  (156U)
#define TIMER_RELOAD_VAL ((TIMER_FULL_VAL) - (TIMER_TICKS_VAL))

static volatile uint16_t time_stamp = 0U;

/**
 * @brief Initializes the timer peripheral.
 */
extern void timer_init()
{
    cli();                    /* disable global interrupts */
    TIMSK0 |= (1 << TOIE0);   /* enable Timer/Counter0 overflow interrupt */
    sei();                    /* enable global interrupts */
    TCNT0 = TIMER_RELOAD_VAL; /* load Timer/Counter0 register */
    TCCR0B |= ((1 << CS01) |
               (1 << CS00)); /* set clock to clk/64, this starts the timer */
}

/**
 * @brief Sets the time_stamp to a specific value.
 */
extern void timer_set_stamp(uint16_t stamp)
{
    TIMSK0 &= ~(1 << TOIE0); /* disable Timer/Counter0 overflow interrupt */
    time_stamp = stamp;
    TIMSK0 |= (1 << TOIE0); /* enable Timer/Counter0 overflow interrupt */
}

/**
 * @brief Returns the current time_stamp value.
 */
extern uint16_t timer_get_stamp()
{
    TIMSK0 &= ~(1 << TOIE0); /* disable Timer/Counter0 overflow interrupt */
    uint16_t ret_val = time_stamp;
    TIMSK0 |= (1 << TOIE0); /* enable Timer/Counter0 overflow interrupt */
    return ret_val;
}

/**
 * @brief Returns TRUE if the deadline has been reached or passed.
 */
extern bool timer_deadline_reached(uint16_t deadline)
{
    return ((int16_t)(time_stamp - deadline) >= 0);
}

/**
 * @brief Timer/Counter0 Overflow Interrupt
 */
#ifndef TEST
ISR(TIMER0_OVF_vect)
#else
void testable_isr_timer0_ovf_vect()
#endif
{
    time_stamp += 10;

    TCNT0 = TIMER_RELOAD_VAL; /* reload Timer/Counter0 register */
}
