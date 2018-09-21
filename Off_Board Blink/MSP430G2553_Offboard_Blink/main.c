#include <msp430.h> 
/**
 * Kyle McKeown
 * main.c
 * MSP430G2553 Offboard_Blink
 */
#define LED1 BIT0 // LED1 gets bit0
#define LED2 BIT6// LED2 gets bit6
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1DIR |= (LED1|LED2);// the LED outputs are on the same port
    volatile int i,j;// variables declared for delay loops
    j = 0;// set j to zero

    for(;;)// endless for loop
    {
        P1OUT ^= LED1;// toggle the value of LED1
        for (i =0; i < 0x8000;i++);// added here for some delay
        j++;//increment j
        if (j % 3)// if j modulous 3 then execute
        {
           P1OUT ^= LED2;// toggle the second LED
	   //j is not incremented again so it is stuck
	   //in this double nested loop
        }

    }
}
