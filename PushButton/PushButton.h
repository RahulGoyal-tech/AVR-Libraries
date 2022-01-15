/*
 * PushButton.c
 *
 * Created: 20-11-2021 01:54:43 PM
 * Author : Rahul Goyal
 */ 

#ifndef Pushbutton
#endif Pushbutton

#include <avr/io.h>

int press(unsigned char port, int buttonNumber, int debounceLevel);

int pressCounter = 0;

int press(unsigned char port, int buttonNumber, int debounceLevel){
	if (bit_is_clear(port, buttonNumber))
	{
		while(bit_is_clear(port, buttonNumber)){
			pressCounter++;
			if (pressCounter>debounceLevel)
			{
				pressCounter = 0;
				return 1;
			}
		}
	}
	else if (bit_is_set(port, buttonNumber))
	{
		return 0;
	}

}