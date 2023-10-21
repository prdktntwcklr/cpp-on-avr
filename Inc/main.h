/* main.h */

#ifndef MAIN_H
#define MAIN_H

#ifndef F_CPU
#define F_CPU 1000000UL /* 1 MHz clock speed factory default */
#endif

#ifdef TEST
int testable_main();
#endif

#endif
