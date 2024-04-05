:: Batch file to flash firmware under Windows (COM6 is assumed)

set port=COM6

:: Erase flash on microcontroller
avrdude -p m168 -P %port% -c avrispv2 -e

:: Flash new firmware image
avrdude -p m168 -P %port% -c avrispv2 -U flash:w:Build/Avr/Bin/app.hex
