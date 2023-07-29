# AVRDebugConsole

##  This library allows you to use SPI and/or Serial to print messages from your AVR device using a single debug console
### (For SPI communication an external Mega 2560 board is required running SPITranslator software)

## Repository consists of the two folders:

Folder **debugConsole** contains a library that implements a debug console which allows users to choose which interface they want to use for printing messages. You should use this library on the AVR device that you want to print the messages from. \
\
Folder **SPISTranslator** contains code that should be uploaded to an external Arduino Mega 2560 that will be used as a translator for the SPI messages received from the device using the debugConsole and print them to its own Serial port. Simply connect the SPI pins of your main device to the SPI pins of the Arduino Mega 2560 and connect the Serial port of the Arduino Mega 2560 to your PC and you will be able to see the messages printed on the Serial monitor at baud rate 115200.
