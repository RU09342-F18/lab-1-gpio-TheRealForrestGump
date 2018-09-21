#include <msp430.h>
/**
 * Kyle McKeown
 * main.c
 * EXP430F5529LP Simple_Blink
 */
int main(void)
{
  volatile int i;

  // stop watchdog timer
  // this is an important step that must be done at the start of each program
  WDTCTL = WDTPW | WDTHOLD;
  // set up bit 0 of P1 as output
  // IN, OUT, REN, SEL, and DIR, all all memory mapped ports
  P1DIR = 0x01;
  // intialize bit 0 of P1 to 0
  P1OUT = 0x00;
  // for loop with no conditions will run endlessly
  for (;;)
  {
    // toggle bit 0 of P1 using an Exclusive OR logic gate.
    P1OUT ^= 0x01;
    // delay for a while
    // the lower the number the faster the LED will blink
    for (i = 0; i < 0x8000; i++);
  }
}
