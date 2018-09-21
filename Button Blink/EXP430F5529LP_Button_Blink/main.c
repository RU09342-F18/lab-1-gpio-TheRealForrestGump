#include <msp430.h> 
/**
 * Kyle McKeown
 * main.c
 * EXP430F5529LP Button_Blink
 */

int main(void)
{
  volatile int i;
  WDTCTL = WDTPW+WDTHOLD;// Stop Watchdog Timer
  P1DIR &= ~BIT1;// P1.1 set as input
  P1REN |= BIT1;// P1.1 set as pull up resistor
  P4DIR |= BIT7;// P4.7 set as LED output

  while (1) {
        if (P1IN & BIT1)// if the button is not pressed
	{
            P4OUT &= BIT7;// LED is set to a zero state
            for(i =0; i < 8000;i++); // create a delay
        } 
	else // the button is pressed
	{
            P4OUT ^= BIT7;// toggle the bit
            for(i =0; i < 8000;i++);// create a delay
        }
    }
}
