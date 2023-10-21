#include "main.h"
#include "low_power.h"
#include "superloop.h"

static Superloop superloop {};
static LowPower lowpower {};

#ifndef TEST
int main()
#else
int testable_main()
#endif
{
    superloop.init();
    lowpower.init();

    while(superloop.run())
    {
        lowpower.enter();
    }

    /* this line is never reached */
    return 0;
}
