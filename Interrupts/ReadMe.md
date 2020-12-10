A basic overview of my kludges to get the non-ATmega328 interrupts to work in the Arduino IDE framework.  The LGT8F328 supports several interrupt sources above and beyond those of the ATmega328.  These include Timer3 and 2 additional Pin Change Interrupts, PCI3 and PCI4 among others.  The gcc-avr compiler seems to have the number of interrupt vectors hard coded into it's concept of different MCUs..  If anyone can set me straight on this idea it would be greatly appreciated.

Ny solution was to modify the configuration of a different MCU which has even more interrupts, the ATmega328PB to be specific.  A copy of this modified file, iom328pb.h, is included here. It needs to be placed in the arduino-1.8.13/hardware/tools/avr/avr/include/avr directory under wherever you have the Arduino IDE installed.

I then had to modify David's boards.txt file to fool the compiler into thinking that the LGT is an ATmega328PB by changing the 328.build.mcu parameter line to 328.build.mcu=atmega328pb.  Note that if you needed to use a "real" ATmega328pb it would not work correctly in certain circumstances...  Be sure to make a back-up copy of this file before adding mine...  This file allows you to use:
    ISR(TC3_INT_vect) { ...... } as I have in TMR3.ino, for example... You could implement PCI3 and PCI4 in a similar manner...


