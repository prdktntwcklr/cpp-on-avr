# C++ on AVR

## Getting started

To build the project for the target hardware, you have to supply the toolchain
file as follows:

```bash
cmake -DCMAKE_TOOLCHAIN_FILE="avr.cmake" -B Build/Avr
```

Then, build the project:

```bash
cmake --build Build/Avr --target app size hex
```

## Flashing firmware

First, erase the chip:

```bash
avrdude -p m168 -P COM6 -c avrispv2 -e
```

Then, flash the firmware:

```bash
avrdude -p m168 -P COM6 -c avrispv2 -U flash:w:app.hex
```

## Further reading

- Kormanyos, C. (2021): *Real-Time C++: Efficient Object-Oriented and Template
Microcontroller Programming.* Springer Berlin Heidelberg.