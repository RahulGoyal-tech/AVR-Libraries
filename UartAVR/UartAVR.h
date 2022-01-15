/*
 * UartAVR.h
 *
 * Created: 22-12-2021
 * Author : Rahul Goyal
 */ 

#ifndef UartAVR
#define UartAVR

#include <avr/io.h>

void uartInit(uint16_t baudNumber, int stopBit, char async){
	//Baud rate setting
	UBRRH = (baudNumber>>8);
	UBRRL = baudNumber;
	
	//Transmit, Receive Enable
	UCSRB |= (1<<TXEN) | (1<<RXEN);
	UCSRC |= (3<<UCSZ0);

	if(async == 0){
		UCSRA &= ~(1<<U2X);
	}
	else if(async == 1){
		UCSRA |= (1<<U2X);
	}
	
	// Stop bit = true means 2 stop bit
	// Stop bit = false means 1 stop bit
	if (stopBit)
	{
		UCSRC |= (1<<USBS); 
	}
	else if(!stopBit){
		UCSRC &= ~(1<<USBS);
	}
}

void uartSpecialInit(uint16_t baudNumber, char stopBit, char async, char dataLen, char parity){
	//Baud rate setting
	UBRRH = (baudNumber>>8);
	UBRRL = baudNumber;

	if(async == 0){
		UCSRA &= ~(1<<U2X);
	}
	else if(async == 1){
		UCSRA |= (1<<U2X);
	}

	if(parity == 0){
		UCSRC |= (1<<UPM1);
	}
	else if(parity == 1){
		UCSRC |= (3<<UPM0);
	}
	
	//Transmit, Receive Enable
	UCSRB |= (1<<TXEN) | (1<<RXEN);
	UCSRC |= (3<<UCSZ0);
	
	// Stop bit = true means 2 stop bit
	// Stop bit = false means 1 stop bit
	if (stopBit == 1)
	{
		UCSRC |= (1<<USBS); 
	}
	else if(stopBit == 0){
		UCSRC &= ~(1<<USBS);
	}

	if(dataLen == 5){
		UCSRB &= ~(1<<UCSZ2);
		UCSRC &= ~(1<<UCSZ0);
		UCSRC &= ~(1<<UCSZ1);
	}
	else if(dataLen == 6){
		UCSRB &= ~(1<<UCSZ2);
		UCSRC |= (1<<UCSZ0);
		UCSRC &= ~(1<<UCSZ1);
	}
	else if(dataLen == 7){
		UCSRB &= ~(1<<UCSZ2);
		UCSRC |= (1<<UCSZ1);
		UCSRC &= ~(1<<UCSZ0);
	}
	else if(dataLen == 8){
		UCSRB &= ~(1<<UCSZ2);
		UCSRC |= (1<<UCSZ0);
		UCSRC |= (1<<UCSZ1);
	}
	else if(dataLen == 9){
		UCSRB |= (1<<UCSZ2);
		UCSRC |= (1<<UCSZ0);
		UCSRC |= (1<<UCSZ1);
	}

}

void uartTransmit(unsigned char data){
	while (!(UCSRA & (1<<UDRE)));
	UDR = data;
}

unsigned char uartReceive(){
	unsigned char data;
	while (!(UCSRA & (1<<RXC)));
	data = UDR;
	return data;
}

#endif