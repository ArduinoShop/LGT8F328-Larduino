# LGT8F328-Larduino
Getting the extra features out of the LGT8F328 MCU in the Arduino IDE.

The LGT8F328 MCU is a very close copy of the microChip/Atmel ATmega328 with just enough extra features to make it interesting...

Some of these features (in order of importance to "ArduinoShop" are:

1) 32MHz operation - internal frequency base of 32, 16, 8, 4, 2 or 1 MHz can be selected via software without burning a new bootloader.
    Read https://github.com/ArduinoShop/LGT8F328-Larduino/blob/main/Selecting%20Frequencies
2) 4 timers, as opposed to 3 timers in the ATmega328 - Timer3 is a 16 bit timer.
    More details in this subdirectory https://github.com/ArduinoShop/LGT8F328-Larduino/tree/main/Interrupts
3) DAC - digital to analog convertor
    Best to visit dbuezas github for this.
4) Higher current drive on certain GPIOs
5) additional IRQ pins
6) Adding printf to the Arduino IDE 2.0

I will get more in depth into the extra features as I have time.

I had to modify (kludge/mung) some Arduino IDE files to be able to get most of these features availble from the Arduino IDE quite a few months ago but just now I needed to use it but could not get it working again immediately....  So I decided to write my changes up in this repository for my own reference and in the hope that someone else may find it useful.

All of my work starts with David Buezas' excellent [board package](https://github.com/dbuezas/lgt8fx).

my haphazard munging of the IDE was also inspired by the microCore [board package](https://github.com/MCUdude/MicroCore) from MCUdude.

**What the LGT8F328P cannot do:**  there are at least 2 thing you need to be aware of when using this MCU:

1) it is not programmable via the SPI bus like the Atmel chips - It uses a SWD interface to accomplish this...
    I have creatd a [module](https://arduinoshop.ca/lgt8f328/lgtasp) that functions as a USBasp/USBisp compatibe with the ArduinoIDE. There is also a workaround using a separate arduino board as programmer, at times referred to as the LarduinoISP - David has adapted a version that he includes in his above mentioned boards package..
    
2) off the shelf LGT boards have the programability of the WatchDog interrupt basically disabled (in the bootloader) with the end result that freeRTOS will not run on these boards.
    One workaround is to use timer3 which involves small mods to some freeRTOS files and the somewhat complex mods I did to IDE files to enable timer3 interrupt...
     or use the LarduinoISP solution discussed in the above paragraph, thereby eliminating the bootloader, and freeRTOS runs with no mods...

6) Adding the "printf" function to the Arduino IDE is discussed <a href=" https://github.com/ArduinoShop/LGT8F328-Larduino/tree/main/printf">here</a>.

...... **cheap plug for my store:** Canadians can get LGT8F328 arduino boards at: [ArduinoShop.ca](https://arduinoshop.ca/lgt8f328). I call them the [Nano32](https://arduinoshop.ca/lgt8f328/nano32) and the [proMINI32](https://arduinoshop.ca/lgt8f328/promini32).

