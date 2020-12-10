A basic overview of my kludges to get the non-ATmega328 interrupts to work in the Arduino IDE framework.  The LGT8F328 support several interrupt sources above and beyond those of the ATmega328.  These include Timer3 and 2 additional Pin Interrupts PCI3 and PCI4 among others.  The gcc-avr compiler seems to have interrupt vectors hard coded into it's concept of different MCUs..  If anyone can set me straight on this idea it would be greatly appreciated.

Ny solution was to copy the configuration of a different MCU which has even more interrupts, the ATmega328B to be specific.  I copied it's config file to one I named iom328pb.h which is included here. It needs to be placed in the arduino-1.8.13/hardware/tools/avr/avr/include/avr directory under wherever you have the Arduino IDE installed.

I then had to modify David's boards.txt file to treat the LGT as an ATmega328B


