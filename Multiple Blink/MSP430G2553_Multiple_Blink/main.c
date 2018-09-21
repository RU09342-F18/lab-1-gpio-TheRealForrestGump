#include <msp430.h> 
/**
 * Kyle McKeown
 * main.c
 * MSP430G2553 Multiple_Blink
 */
#define LED1 BIT0// LED1 gets bit 0
#define LED2 BIT6// LED2 gets bit 6
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1DIR |= (LED1|LED2); // both LED's share the same port
    volatile int i,j;// variables to be declared for the delays
    j = 0; // set j to zero

    for(;;)// loop that runs forever
    {
        P1OUT ^= LED1;// toggle LED1 on
        for (i =0; i < 0x8000;i++);// delay
        j++;// increment j
        if (j % 3)// a j modulous 3 here made a very nice alternating 
	          // and then simultaneous blink like the xmas light 
		  // blink that I was going for
        {
           P1OUT ^= LED2; // toggle LED2 only on certain cycles
        }

    }
}
