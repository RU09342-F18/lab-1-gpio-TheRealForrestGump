#include <msp430.h> 
/**
 * Kyle McKeown
 * main.c
 * MSP430G2553 Button_Blink
 */
#define LED1 BIT0 // LED1 assigned the value of 0000 0000
#define LED2 BIT6 // LED2 assigned the value of 0000 0110
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= (LED1|LED2); // Port 1 direction declared an output
	volatile int j,i; // used for the loops
	j = 0; // delare j to be 0 used for LED progression with time
	for(;;) // Loop Forever
	{
	    if ((BIT3 & P1IN)) // If the button is not pressed(inverse logic)
	    {
	        P1OUT &= LED1;// Reset LED1 to zero state
	        P1OUT &= LED2;// Reset LED2 to zero state
	        j = 0; // j gets set to zero when the button is released
	    }
	    else // the button is being pressed
	    {
	            P1OUT ^= LED2; // toggle LED2
	            for (i =0; i < 0x8000;i++); // create a delay for
	            j++;

	    if (j > 10)//when j reaches 10 the second loop kicks in
	    {
	        P1OUT ^= LED1;// toggle LED1 (LED2 still being toggled)
	        for (i =0; i < 0x8000;i++);// delay again
	        j++;//increment j

	    }
	    if (j > 20)// when J reaches this point
	    {
	        P1OUT ^= LED1;// flip the state of both LEDs and hold
	        P1OUT ^= LED2;
	        break;// exits the loop and holds the current state until reset
	    }
	    }
	}
	return 0;
}
