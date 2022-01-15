/*
 * PWMDriver(Servo).h
 *
 * Created: 10-10-2021
 * Author : Rahul Goyal
 */ 

#ifndef PWMServo.h
#define PWMServo.h

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define A 0
#define B 1
#define C 2
#define D 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

int gport;
int gpin;

void pwm(int cycle, int positive);
void pwmrev(int cycle, int positive);
void pwmpin(int cycle, int positive, int port, int pin);

void pwm(int cycle, int positive){
    DDRD |= 0xFF; // Set PortD as output
	
	TCCR1A |= 1<<WGM11|1<<COM1A1; //Sets OC1A low on TCNT Match with OCR1A
	TCCR1B |= 1<<WGM12|1<<WGM13|1<<CS10; //Fast PWM Mode with ICR as Top
	ICR1 = cycle; //Width of complete Cycle

    OCR1A = positive;
    _delay_ms(500);    
}

void pwmrev(int cycle, int positive){
    DDRD |= 0xFF; // Set PortD as output
	
	TCCR1A |= 1<<WGM11|1<<COM1A1|1<<COM1A0; //Sets OC1A High on TCNT Match with OCR1A
	TCCR1B |= 1<<WGM12|1<<WGM13|1<<CS10; //Fast PWM Mode with ICR as Top
	ICR1 = cycle; //Width of complete Cycle

    OCR1A = ICR1 - positive; //Value 1 of OCR -> 0
	_delay_ms(1000);    
}

void pwmpin(int cycle, int positive, int port, int pin){
	gport = port;
	gpin = pin;
	int i = 7000;
	while (i--)
{
	if (port == 0){
			switch(pin)
			{
				case PIN0:
				DDRA |= (1<<PINA0);
				break;
				case PIN1:
				DDRA |= (1<<PINA1);
				break;
				case PIN2:
				DDRA |= (1<<PINA2);
				break;
				case PIN3:
				DDRA |= (1<<PINA3);
				break;
				case PIN4:
				DDRA |= (1<<PINA4);
				break;
				case PIN5:
				DDRA |= (1<<PINA5);
				break;
				case PIN6:
				DDRA |= (1<<PINA6);
				break;
				case PIN7:
				DDRA |= (1<<PINA7);
				break;
				
			}
		}
		if (port == 1){
			switch(pin)
			{
				case PIN0:
					DDRB |= (1<<PINB0);
					break;
				case PIN1:
					DDRB |= (1<<PINB1);
					break;
				case PIN2:
					DDRB |= (1<<PINB2);
					break;
				case PIN3:
					DDRB |= (1<<PINB3);
					break;
				case PIN4:
					DDRB |= (1<<PINB4);
					break;
				case PIN5:
					DDRB |= (1<<PINB5);
					break;
				case PIN6:
					DDRB |= (1<<PINB6);
					break;
				case PIN7:
					DDRB |= (1<<PINB7);
					break;
				
			}
		}
		if (port == 2){
			switch(pin)
			{
				case PIN0:
				DDRC |= (1<<PINC0);
				break;
				case PIN1:
				DDRC |= (1<<PINC1);
				break;
				case PIN2:
				DDRC |= (1<<PINC2);
				break;
				case PIN3:
				DDRC |= (1<<PINC3);
				break;
				case PIN4:
				DDRC |= (1<<PINC4);
				break;
				case PIN5:
				DDRC |= (1<<PINC5);
				break;
				case PIN6:
				DDRC |= (1<<PINC6);
				break;
				case PIN7:
				DDRC |= (1<<PINC7);
				break;
				
			}
		}
		if (port == 3){
			switch(pin)
			{
				case PIN0:
				DDRD |= (1<<PIND0);
				break;
				case PIN1:
				DDRD |= (1<<PIND1);
				break;
				case PIN2:
				DDRD |= (1<<PIND2);
				break;
				case PIN3:
				DDRD |= (1<<PIND3);
				break;
				case PIN4:
				DDRD |= (1<<PIND4);
				break;
				case PIN5:
				DDRD |= (1<<PIND5);
				break;
				case PIN6:
				DDRD |= (1<<PIND6);
				break;
				case PIN7:
				DDRD |= (1<<PIND7);
				break;
				
			}
		}
		TIMSK |= (1<<OCIE1A)|(1<<TOIE1);
		OCR1A = positive;
		TCCR1A |= (1<<WGM11);
		TCCR1B |= (1<<WGM12)|(1<<WGM13)|(1<<CS10);
		ICR1 = cycle;
		sei();
}
}

ISR(TIMER1_COMPA_vect){
	if (gport == 0){
		switch(gpin)
		{
			case PIN0:
			PORTA &= ~(1<<PINA0);
			break;
			case PIN1:
			PORTA &= ~(1<<PINA1);
			break;
			case PIN2:
			PORTA &= ~(1<<PINA2);
			break;
			case PIN3:
			PORTA &= ~(1<<PINA3);
			break;
			case PIN4:
			PORTA &= ~(1<<PINA4);
			break;
			case PIN5:
			PORTA &= ~(1<<PINA5);
			break;
			case PIN6:
			PORTA &= ~(1<<PINA6);
			break;
			case PIN7:
			PORTA &= ~(1<<PINA7);
			break;
		}
	}
	if (gport == 1){
		switch(gpin)
		{
			case PIN0:
			PORTB &= ~(1<<PINB0);
			break;
			case PIN1:
			PORTB &= ~(1<<PINB1);
			break;
			case PIN2:
			PORTB &= ~(1<<PINB2);
			break;
			case PIN3:
			PORTB &= ~(1<<PINB3);
			break;
			case PIN4:
			PORTB &= ~(1<<PINB4);
			break;
			case PIN5:
			PORTB &= ~(1<<PINB5);
			break;
			case PIN6:
			PORTB &= ~(1<<PINB6);
			break;
			case PIN7:
			PORTB &= ~(1<<PINB7);
			break;
		}
	}
	if (gport == 2){
		switch(gpin)
		{
			case PIN0:
			PORTC &= ~(1<<PINC0);
			break;
			case PIN1:
			PORTC &= ~(1<<PINC1);
			break;
			case PIN2:
			PORTC &= ~(1<<PINC2);
			break;
			case PIN3:
			PORTC &= ~(1<<PINC3);
			break;
			case PIN4:
			PORTC &= ~(1<<PINC4);
			break;
			case PIN5:
			PORTC &= ~(1<<PINC5);
			break;
			case PIN6:
			PORTC &= ~(1<<PINC6);
			break;
			case PIN7:
			PORTC &= ~(1<<PINC7);
			break;
		}
	}
	if (gport == 3){
		switch(gpin)
		{
			case PIN0:
			PORTD &= ~(1<<PIND0);
			break;
			case PIN1:
			PORTD &= ~(1<<PIND1);
			break;
			case PIN2:
			PORTD &= ~(1<<PIND2);
			break;
			case PIN3:
			PORTD &= ~(1<<PIND3);
			break;
			case PIN4:
			PORTD &= ~(1<<PIND4);
			break;
			case PIN5:
			PORTD &= ~(1<<PIND5);
			break;
			case PIN6:
			PORTD &= ~(1<<PIND6);
			break;
			case PIN7:
			PORTD &= ~(1<<PIND7);
			break;
		}
	}
}

ISR(TIMER1_OVF_vect){
	if (gport == 0){
		switch(gpin)
		{
			case PIN0:
			PORTA |= (1<<PINA0);
			break;
			case PIN1:
			PORTA |= (1<<PINA1);
			break;
			case PIN2:
			PORTA |= (1<<PINA2);
			break;
			case PIN3:
			PORTA |= (1<<PINA3);
			break;
			case PIN4:
			PORTA |= (1<<PINA4);
			break;
			case PIN5:
			PORTA |= (1<<PINA5);
			break;
			case PIN6:
			PORTA |= (1<<PINA6);
			break;
			case PIN7:
			PORTA |= (1<<PINA7);
			break;
			
		}
	}
	if (gport == 1){
		switch(gpin)
		{
			case PIN0:
			PORTB |= (1<<PINB0);
			break;
			case PIN1:
			PORTB |= (1<<PINB1);
			break;
			case PIN2:
			PORTB |= (1<<PINB2);
			break;
			case PIN3:
			PORTB |= (1<<PINB3);
			break;
			case PIN4:
			PORTB |= (1<<PINB4);
			break;
			case PIN5:
			PORTB |= (1<<PINB5);
			break;
			case PIN6:
			PORTB |= (1<<PINB6);
			break;
			case PIN7:
			PORTB |= (1<<PINB7);
			break;
			
		}
	}
	if (gport == 2){
		switch(gpin)
		{
			case PIN0:
			PORTC |= (1<<PINC0);
			break;
			case PIN1:
			PORTC |= (1<<PINC1);
			break;
			case PIN2:
			PORTC |= (1<<PINC2);
			break;
			case PIN3:
			PORTC |= (1<<PINC3);
			break;
			case PIN4:
			PORTC |= (1<<PINC4);
			break;
			case PIN5:
			PORTC |= (1<<PINC5);
			break;
			case PIN6:
			PORTC |= (1<<PINC6);
			break;
			case PIN7:
			PORTC |= (1<<PINC7);
			break;
			
		}
	}
	if (gport == 3){
		switch(gpin)
		{
			case PIN0:
			PORTD |= (1<<PIND0);
			break;
			case PIN1:
			PORTD |= (1<<PIND1);
			break;
			case PIN2:
			PORTD |= (1<<PIND2);
			break;
			case PIN3:
			PORTD |= (1<<PIND3);
			break;
			case PIN4:
			PORTD |= (1<<PIND4);
			break;
			case PIN5:
			PORTD |= (1<<PIND5);
			break;
			case PIN6:
			PORTD |= (1<<PIND6);
			break;
			case PIN7:
			PORTD |= (1<<PIND7);
			break;
			
		}
	}
}

#endif