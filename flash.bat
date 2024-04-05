:: Batch file to flash firmware under Windows

:: Erase flash on microcontroller
avrdude -p m168 -P COM6 -c avrispv2 -e

:: Flash new firmware image
avrdude -p m168 -P COM6 -c avrispv2 -U flash:w:Build/Avr/Bin/app.hex
