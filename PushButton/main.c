/*
 * PushButton.c
 *
 * Created: 20-11-2021 01:54:43 PM
 * Author : Rahul Goyal
 */ 

// #ifndef Pushbutton
// #endif Pushbutton
// 
// #include <avr/io.h>
// 
// int press(unsigned char port, int buttonNumber, int debounceLevel);
// 
// int pressCounter = 0;
// int releaseCounter = 0;
// 
// int press(unsigned char port, int buttonNumber, int debounceLevel){
// 	if (bit_is_clear(port, buttonNumber))
// 	{
// 		pressCounter++;
// 		releaseCounter = 0;
// 		if (pressCounter>debounceLevel)
// 		{
// 			pressCounter = 0;
// 			return 1;
// 		}
// 	}
// 	else
// 	{
// 		releaseCounter++;
// 		pressCounter = 0;
// 		if (releaseCounter>debounceLevel)
// 		{
// 			releaseCounter = 0;
// 			return 0;
// 		}
// 		
// 	}
// }


//Main Pushbutton COde for button Toggling
// int main(void)
// {
// 	DDRB |= (1<<PINB0); //Pin b0 as o/p
// 	PORTB |= 1<<PINB0; // Pin b0 is on
// 	DDRB &= ~(1<<PINB1); // Pin b1 is input
// 	PORTB |= 1<<PINB1; //Pin b1 is high
// 	
// 	int pressed = 0; //Cuurent Status Of Button
// 	int pressedCounter = 0; //No. of 0 detected when button pressed
// 	int releaseCounter = 0; //No. of 1 detected when button released 
// 	
//     /* Replace with your application code */
//     while (1) 
//     {
// 		if (bit_is_clear(PINB, 1)) //Function to check if B1 is grounded i.e. bit is clear 
// 		{
// 			pressedCounter++; // Debounce Counter -> if threshold crosses then use button
// 			if (pressedCounter>200)
// 			{
// 				if (pressed==0) //Enter this loop if button is released and then pressed -> prevent from multiple switching while keeping button pressed
// 				{
// 					PORTB ^= 1<<PINB0; // Toggle LED
// 					pressed = 1; // Set pressed as 1 to tell that button is currently pressed
// 				}
// 				pressedCounter = 0; // Making counter 0 for next readings
// 			}
// 		}
// 		else{
// 			releaseCounter++; // Released counter to see if button is released properly
// 			if (releaseCounter>200)
// 			{
// 				pressed = 0; // Setting pressed 0 to tell that button is released
// 				releaseCounter = 0; // Maiking release counter 0 for next check.
// 			}
// 		}
//     }
// }


#include <avr/io.h>
#include "util/delay.h"
#include <PushButton.h>

int main(){
	DDRB |= 1<<PINB0;
	PORTB |= 1<<PINB0;
	DDRB &= ~(1<<PINB2);
	PORTB |= 1<<PINB2;
	
	while (1)
	{
		if (press(PINB, 2, 100))
		{
			PORTB ^= (1<<PINB0);
		}
		_delay_ms(100);
	}
}