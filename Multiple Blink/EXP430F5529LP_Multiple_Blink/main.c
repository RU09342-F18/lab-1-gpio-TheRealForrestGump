#include <msp430.h> 
/**
 * Kyle McKeown
 * main.c
 * EXP430F5529LP Multiple_Blink
 */
#define LED1 BIT0//LED1 gets bit0
#define LED2 BIT7//LED2 gets bit7
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1DIR |= LED1;// Port 1.0 is LED 1
    P4DIR |= LED2;// Port 4.7 is LED 2 

    volatile int i,j;// variables o be declared for the delays
    j = 0; // set j to zero

    for(;;)//loops forever
    {
        P1OUT ^= LED1;// Toggle LED1
        for (i =0; i < 0x8000;i++);// delay for some time
        j++;//increment j
        if (j % 3)// j modulous 3 to give a nice patterned intermittent blink
        {
           P4OUT ^= LED2;// toggle LED2 only when j%3 = 0
        }

    }
}
