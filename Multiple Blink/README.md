# Kyle McKeown Multiple Blink
For this part of the lab I used a portion of my code that I had generated in the Buttton_Blink module and implemented it here.  I had first created two blinking LED's with a button press but simplified the code here to be much more effecient and run forever without a reset or any button presses. 

# THE FOLLOWING FOLDERS WERE CREATED FOR THIS SECTION
* MSP430G2553_Multiple_Blink
* EXP430F5529LP_Multiple_Blink

## README
There were no major code changes between the two processors in this part of the code other then changing the names of ports. Since by now I have learned to define them at the start of my program it was an easy fix to reuse this same code between platforms. The idea to use the modulous operator in this code was so that I had a uniform blinking of the lights that were syncronized to a certain extent but flashed at different intervals. My idea of a good lighting design is one simular to patterned blinks that are seen in Christmas lighting. On a small scale this shows the pattern that can be used to blink many lights connected together in an alternating fashion and then blinking together. I played with different combinations of numbers but in the end I decided that I liked this patten the best where the inital blink was set and then the code remains executing in the second if statement. I also tried more random combinations of numbers to produce a simular output but I was most happy with the repeating pattern from the result of the current code.

## Extra Work
For the MSP430G2553 I used this same code to produce the Offboard_Blink section of the lab.

