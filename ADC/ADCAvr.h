#ifndef ADCAvr
#define ADCAvr

#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int getAdc10Val(int pin);
int getAdc8Val(int pin);
int temp = 1;
int result = 0;
int mode = 0;

int getAdc8Val(int pin){
    temp = 1;
	ADCSRA |= 1<<ADPS2; //16 prescalar for ADC frequency
	ADMUX |= 1<<ADLAR; //Adlar = 1 -> Preferred for 8 bit values
	ADMUX |= 1<<REFS0; //Ref Voltage -> AVCC with external cap at aref
	ADCSRA |= 1<<ADIE; //Interrupt Enable
	ADCSRA |= 1<<ADEN; //Turns on ADC

	sei(); //Global Interrupt Enable
	
	switch (pin)
	{
		case 0:
			break;
		case 1:
			ADMUX |= 1<<MUX0;
			break;
		case 2:
			ADMUX |= 1<<MUX1;
			break;
		case 3:
			ADMUX |= (1<<MUX0)|(1<<MUX1);
			break;
		case 4:
			ADMUX |= 1<<MUX2;
			break;
		case 5:
			ADMUX |= (1<<MUX2)|(1<<MUX0);
			break;
		case 6:
			ADMUX |= (1<<MUX2)|(1<<MUX1);
			break;
		case 7:
			ADMUX |= (1<<MUX2)|(1<<MUX1)|(1<<MUX0);
			break;
		default:
			break;
	}
	mode = 8;
	ADCSRA |= 1<<ADSC;
	while(temp){}
	return result;
}

int getAdc10Val(int pin){
    temp = 1;
	ADCSRA |= 1<<ADPS2; //16 prescalar for ADC frequency
	ADMUX &= ~(1<<ADLAR); //Adlar = 0 -> Preferred for 16 bit values
	ADMUX |= 1<<REFS0; //Ref Voltage -> AVCC with external cap at aref
	ADCSRA |= 1<<ADIE; //Interrupt Enable
	ADCSRA |= 1<<ADEN; //Turns on ADC

	sei(); //Global Interrupt Enable
	
	switch (pin)
	{
		case 0:
			break;
		case 1:
			ADMUX |= 1<<MUX0;
			break;
		case 2:
			ADMUX |= 1<<MUX1;
			break;
		case 3:
			ADMUX |= (1<<MUX0)|(1<<MUX1);
			break;
		case 4:
			ADMUX |= 1<<MUX2;
			break;
		case 5:
			ADMUX |= (1<<MUX2)|(1<<MUX0);
			break;
		case 6:
			ADMUX |= (1<<MUX2)|(1<<MUX1);
			break;
		case 7:
			ADMUX |= (1<<MUX2)|(1<<MUX1)|(1<<MUX0);
			break;
		default:
			break;
	}
	mode = 10;
	ADCSRA |= 1<<ADSC;
	while(temp){}
	return result;
}

ISR(ADC_vect)
{
	if(mode==10){
        result = 0;
        result = (ADCL) | (ADCH<<8);
	    temp = 0;
    }
    else if(mode==8){
        result = 0;
        result = ADCH;
        temp = 0;
    } 
}

#endif