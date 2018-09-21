# Kyle McKeown Simple Blink
For the Simple_Blink part of the lab, I made sure that the LED was on for the same amount of time that it was off thus meeting the 50 percent duty cylce requirements. This was the simplest of the programs to create as it only involves a single LED. I was able to play around with the MSP430G2553 and light each individual LED by changing the ports but the final version of the code incorporates a single LED the blinks using a delay.

## THE FOLLOWING FOLDERS WERE CREATED FOR THIS LAB
* MSP430G2553_Simple_Blink
* EXP430F5529LP_Simple_Blink

## PROCEDURE
Since the LED was not overloading this simple circuit I figured that it would be OK to leave it out since my program did not function as well with the resistor.
Because of the way that I wrote the code initially for the MSP430G2553 the circuit used no resistors, nor buttons or unique ports. the only port that was used was the same in both the MSP430G253 and the EXP430F5529 was P1.0 which was the at the same location for both microprocessors and no changes were needed between the two modules. As before the LED bit was toggled an followed by a delay so that the blink was visible. the empty for loop [for(;;)] indicates that the light will continue to blink at the same rate as long as there is power being supplied. Since there is only one delay and the bit is only toggled before each delay, this guarantees that the LED will be on for the same amount of time that it is off.


