#include <msp430.h> 
/**
 * Kyle McKeown
 * main.c
 * MSP430G2553 Multiple_Blink
 */
#define LED1 BIT0
#define LED2 BIT6
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1DIR |= (LED1|LED2);
    volatile int i,j;
    j = 0;

    for(;;)
    {
        P1OUT ^= LED1;
        for (i =0; i < 0x8000;i++);
        j++;
        if (j % 3)
        {
           P1OUT ^= LED2;
        }

    }
}
