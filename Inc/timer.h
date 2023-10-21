/* timer.h */

#ifndef TIMER_H
#define TIMER_H

#include "stdint.h"

void timer_init();
void timer_set_stamp(uint16_t stamp);
uint16_t timer_get_stamp();
bool timer_deadline_reached(uint16_t deadline);

#ifdef TEST
void testable_isr_timer0_ovf_vect();
#endif

#endif // TIMER_H
