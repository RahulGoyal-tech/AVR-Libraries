/*
 * Rough Codes.c
 *
 * Created: 22-11-2021 06:03:39 PM
 * Author : Rahul Goyal
 */ 
#define F_CPU 1000000UL

#include <avr/io.h>
#include <UartAVR.h>

int main(void)
{
	uartInit(25,1,0);
	while (1)
	{
		uartTransmit('A');
	}
}
