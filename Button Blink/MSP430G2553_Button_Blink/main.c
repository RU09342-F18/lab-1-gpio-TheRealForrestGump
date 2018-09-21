#include <msp430.h> 
/**
 * Kyle McKeown
 * main.c
 * MSP430G2553 Button_Blink
 */
#define LED1 BIT0
#define LED2 BIT6
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= (LED1|LED2);
	volatile int j,i;
	j = 0;

	for(;;)
	{
	    if ((BIT3 & P1IN)) // active low switch
	    {
	        P1OUT &= LED1;// if P1.3 is not pressed, reset P1.0
	        P1OUT &= LED2;
	        j = 0;
	    }
	    else
	    {
	            P1OUT ^= LED2;
	            for (i =0; i < 0x8000;i++);
	            j++;

	    if (j > 10
	            )
	    {
	        P1OUT ^= LED1;
	        for (i =0; i < 0x8000;i++);
	        j++
	        ;

	    }
	    if (j > 20)
	    {
	        P1OUT ^= LED1;
	        P1OUT ^= LED2;
	        break;
	    }
	    }
	}
	return 0;
}
