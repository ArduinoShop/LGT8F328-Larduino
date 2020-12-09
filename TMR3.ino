// #define W_DOG // Comment out this line if using the factory bootloader
              // it will just Reset the board - not trigger the WatchDog interrupt
              
volatile uint8_t Rst = 'u';
volatile uint8_t Wdt = 'u';
volatile uint8_t Tmr = 'u';

ISR(TC3_INT_vect) {
  TIFR3 = 0x0F;
  Tmr = 'T';
                  }

ISR( WDT_vect ) { // if using the factory bootloader we will never get here
//  WDTCSR |= 0x80;
  Wdt = 'W';
                }

void setup() {

#ifdef W_DOG
   __asm__ __volatile__ (
    "wdr\n"
  );
//  WDTCSR = 0;
#endif

  Rst = 'R'; // log Reset
  
Serial.begin( 115200 );
Serial.printf( "WDTCSR = 0x%x -- 0x%x\n", MCUSR, WDTCSR );

#ifdef W_DOG
cli();  //  disable interrupts

WDTCSR =  (1<<WDCE)  | (1<<WDE);
WDTCSR =  (1<<WDIE)  | (0<<WDE) | (1<<WDP2)  | (1<<WDP1) | (1<<WDP0); // WDog Interval 
WDTCSR |= (1<<WDIE); // enable WatchDog Interrupt
#endif

sei();   //  enable interrupts

Serial.printf( "\nBegin Timer 3 / WDog test -- 0x%x\n", WDTCSR );

TCNT3 = 0;
TCCR3A = 0x0;
TCCR3B = 5;

TIMSK3 = 1;

}

void loop() {
/***  This loop prints out the timer3 value and the "log" of
 *    possible Interrupts
**********/
  Serial.printf( "%c, %c, %c\n", Rst, Tmr, Wdt );
  Rst = Tmr = Wdt = 'x';  //  Rest "log value to 'x' for each interrupt source
  Serial.printf( "TCNT3 = 0x%x\n", TCNT3 );
  delay( 1000 );  //  wait 1 second
}
