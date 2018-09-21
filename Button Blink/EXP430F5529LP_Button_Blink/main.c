#include <msp430.h> 
/**
 * Kyle McKeown
 * main.c
 * EXP430F5529LP Button_Blink
 */

int main(void)
{
  volatile int i;
  WDTCTL = WDTPW+WDTHOLD;                   // Stop Watchdog Timer
  P1DIR &= ~BIT1;                           // P1.1 set as input
  P1REN |= BIT1;                            // P1.1 set internal pull up
  P4DIR |= BIT7;                            // P4.7 set as output

  while (1) {
        if (P1IN & BIT1) {
            P4OUT &= BIT7;
            for(i =0; i < 8000;i++);
        } else {
            P4OUT ^= BIT7;
            for(i =0; i < 8000;i++);
        }
    }
}
