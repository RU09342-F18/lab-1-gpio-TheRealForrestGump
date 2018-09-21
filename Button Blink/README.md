# Kyle McKeown Button Blink
The Goal in this part of the lab is to implement button Functionality for two
sperate Microprocessors

# The Folders That were Created for this Portion
* MSP430G2553_Button_Blink
* EXP430F5529LP_Button_Blink

## README
For The button press the main difference that is taken into account is the need to enable pull-up/pull-down resistors for the EXP430F5529LP Vs. not having to do so for the MSP430G2553. My code ended up being significantly different between the two processors because of the need to reconfigure this.  I can acknowledge that this may have been a mistake on my part because I had first programmed the MSP430G2553 in the early stages of the lab when I was just becoming more comfortable with programming these micro-controllers. What I have learned from this is to implement all of the code in such a way as to be compatible with different types of microcontrollers while making as few changes as possible between platforms. One way that this is being practiced is defining commonly used variables in the beginning of the program. This not only makes the code simpler to change in the future but it also makes the programs much more readable.

For example I found that the easiest way to implement the LED's in the code was to describe them as their port and pin only one time and each time that I call upon them to call them by LED1 or LED2.  This is very useful because as the code is re-used on a different processor, the only thing that needs to be changed is the initial port and pin declarations.

//#define LED1 BIT0
//#define LED2 BIT6
 
I initially kept this implementation but it became unnecessary once I changed the second program almost entirely, But I learned from the first program that I wrote, which was the button blink on the MSP430G2553 that it is best to define variables in this way.

## Extra Work

For the MSP430G2553 I got a little creative and put some extra work into the program since I was trying to gain some familiararity with the hardware itself for the other programs that I would be writing. I created two volatile ints i and j and used these to control two different LED's to create three seperate states of LED's. 
First if the button is not pressed, nothing happens and the LED's are kept in their reset phase of 0. the variable j is also reset to zero so that when the button is released the entire cycle will begin from the start.
Once the button is pressed the sequence of lights begins. The second LED will blink, then hit a delay and increment j. once j reaches a certain value, the other LED will toggle on and off in the same was as LED2 until J reaches another value and the state of the LED's will hold.
It was coded this way as a means to create three different blinking states that could represent 3 different states to represent some kind of special power on finction for an electronic device. while working on these extra segments of code I was able to get a much stronger grasp on how these LED's toggle on and off and how those I/O pins can be useful in many applications.
