/* main.c */

#include "main.h"
#include "low_power.h"
#include "superloop.h"

Superloop superloop{};

#ifndef TEST
int main()
#else
int testable_main()
#endif
{
    superloop.init();
    low_power_init();

    while(superloop.run())
    {
        low_power_enter();
    }

    /* this line is never reached */
    return 0;
}
