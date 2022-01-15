/*
 * pinPort.c
 *
 * Created: 14-12-2021 09:47:56 PM
 * Author : Rahul Goyal
 */ 

#include <avr/io.h>

void pinPortDir(int port, int pin, int dir){
	if (dir)
	{
		if (port == 0)
		{
			switch (pin)
			{
			case 0:
				DDRA |= (1<<PINA0);
				break;
			case 1:
				DDRA |= (1<<PINA1);
				break;
			case 2:
				DDRA |= (1<<PINA2);
				break;
			case 3:
				DDRA |= (1<<PINA3);
				break;
			case 4:
				DDRA |= (1<<PINA4);
				break;
			case 5:
				DDRA |= (1<<PINA5);
				break;
			case 6:
				DDRA |= (1<<PINA6);
				break;
			case 7:
				DDRA |= (1<<PINA7);
				break;
			}
		}
		if (port == 1)
		{
			switch (pin)
			{
			case 0:
				DDRB |= (1<<PINB0);
				break;
			case 1:
				DDRB |= (1<<PINB1);
				break;
			case 2:
				DDRB |= (1<<PINB2);
				break;
			case 3:
				DDRB |= (1<<PINB3);
				break;
			case 4:
				DDRB |= (1<<PINB4);
				break;
			case 5:
				DDRB |= (1<<PINB5);
				break;
			case 6:
				DDRB |= (1<<PINB6);
				break;
			case 7:
				DDRB |= (1<<PINB7);
				break;
			}
		}
		if (port == 2)
		{
			switch (pin)
			{
			case 0:
				DDRC |= (1<<PINC0);
				break;
			case 1:
				DDRC |= (1<<PINC1);
				break;
			case 2:
				DDRC |= (1<<PINC2);
				break;
			case 3:
				DDRC |= (1<<PINC3);
				break;
			case 4:
				DDRC |= (1<<PINC4);
				break;
			case 5:
				DDRC |= (1<<PINC5);
				break;
			case 6:
				DDRC |= (1<<PINC6);
				break;
			case 7:
				DDRC |= (1<<PINC7);
				break;
			}
		}
		if (port == 3)
		{
			switch (pin)
			{
			case 0:
				DDRD |= (1<<PIND0);
				break;
			case 1:
				DDRD |= (1<<PIND1);
				break;
			case 2:
				DDRD |= (1<<PIND2);
				break;
			case 3:
				DDRD |= (1<<PIND3);
				break;
			case 4:
				DDRD |= (1<<PIND4);
				break;
			case 5:
				DDRD |= (1<<PIND5);
				break;
			case 6:
				DDRD |= (1<<PIND6);
				break;
			case 7:
				DDRD |= (1<<PIND7);
				break;
			}
		}
	}
	if (!dir)
	{
		if (port == 0)
		{
			switch (pin)
			{
			case 0:
				DDRA &= ~(1<<PINA0);
				break;
			case 1:
				DDRA &= ~(1<<PINA1);
				break;
			case 2:
				DDRA &= ~(1<<PINA2);
				break;
			case 3:
				DDRA &= ~(1<<PINA3);
				break;
			case 4:
				DDRA &= ~(1<<PINA4);
				break;
			case 5:
				DDRA &= ~(1<<PINA5);
				break;
			case 6:
				DDRA &= ~(1<<PINA6);
				break;
			case 7:
				DDRA &= ~(1<<PINA7);
				break;
			}
		}
		if (port == 1)
		{
			switch (pin)
			{
			case 0:
				DDRB &= ~(1<<PINB0);
				break;
			case 1:
				DDRB &= ~(1<<PINB1);
				break;
			case 2:
				DDRB &= ~(1<<PINB2);
				break;
			case 3:
				DDRB &= ~(1<<PINB3);
				break;
			case 4:
				DDRB &= ~(1<<PINB4);
				break;
			case 5:
				DDRB &= ~(1<<PINB5);
				break;
			case 6:
				DDRB &= ~(1<<PINB6);
				break;
			case 7:
				DDRB &= ~(1<<PINB7);
				break;
			}
		}
		if (port == 2)
		{
			switch (pin)
			{
			case 0:
				DDRC &= ~(1<<PINC0);
				break;
			case 1:
				DDRC &= ~(1<<PINC1);
				break;
			case 2:
				DDRC &= ~(1<<PINC2);
				break;
			case 3:
				DDRC &= ~(1<<PINC3);
				break;
			case 4:
				DDRC &= ~(1<<PINC4);
				break;
			case 5:
				DDRC &= ~(1<<PINC5);
				break;
			case 6:
				DDRC &= ~(1<<PINC6);
				break;
			case 7:
				DDRC &= ~(1<<PINC7);
				break;
			}
		}
		if (port == 3)
		{
			switch (pin)
			{
			case 0:
				DDRD &= ~(1<<PIND0);
				break;
			case 1:
				DDRD &= ~(1<<PIND1);
				break;
			case 2:
				DDRD &= ~(1<<PIND2);
				break;
			case 3:
				DDRD &= ~(1<<PIND3);
				break;
			case 4:
				DDRD &= ~(1<<PIND4);
				break;
			case 5:
				DDRD &= ~(1<<PIND5);
				break;
			case 6:
				DDRD &= ~(1<<PIND6);
				break;
			case 7:
				DDRD &= ~(1<<PIND7);
				break;
			}
		}
	}
}

void pinPortVal(int port, int pin, int val){
	if (val)
	{
		if (port == 0)
		{
			switch (pin)
			{
			case 0:
				PORTA |= (1<<PINA0);
				break;
			case 1:
				PORTA |= (1<<PINA1);
				break;
			case 2:
				PORTA |= (1<<PINA2);
				break;
			case 3:
				PORTA |= (1<<PINA3);
				break;
			case 4:
				PORTA |= (1<<PINA4);
				break;
			case 5:
				PORTA |= (1<<PINA5);
				break;
			case 6:
				PORTA |= (1<<PINA6);
				break;
			case 7:
				PORTA |= (1<<PINA7);
				break;
			}
		}
		if (port == 1)
		{
			switch (pin)
			{
			case 0:
				PORTB |= (1<<PINB0);
				break;
			case 1:
				PORTB |= (1<<PINB1);
				break;
			case 2:
				PORTB |= (1<<PINB2);
				break;
			case 3:
				PORTB |= (1<<PINB3);
				break;
			case 4:
				PORTB |= (1<<PINB4);
				break;
			case 5:
				PORTB |= (1<<PINB5);
				break;
			case 6:
				PORTB |= (1<<PINB6);
				break;
			case 7:
				PORTB |= (1<<PINB7);
				break;
			}
		}
		if (port == 2)
		{
			switch (pin)
			{
			case 0:
				PORTC |= (1<<PINC0);
				break;
			case 1:
				PORTC |= (1<<PINC1);
				break;
			case 2:
				PORTC |= (1<<PINC2);
				break;
			case 3:
				PORTC |= (1<<PINC3);
				break;
			case 4:
				PORTC |= (1<<PINC4);
				break;
			case 5:
				PORTC |= (1<<PINC5);
				break;
			case 6:
				PORTC |= (1<<PINC6);
				break;
			case 7:
				PORTC |= (1<<PINC7);
				break;
			}
		}
		if (port == 3)
		{
			switch (pin)
			{
			case 0:
				PORTD |= (1<<PIND0);
				break;
			case 1:
				PORTD |= (1<<PIND1);
				break;
			case 2:
				PORTD |= (1<<PIND2);
				break;
			case 3:
				PORTD |= (1<<PIND3);
				break;
			case 4:
				PORTD |= (1<<PIND4);
				break;
			case 5:
				PORTD |= (1<<PIND5);
				break;
			case 6:
				PORTD |= (1<<PIND6);
				break;
			case 7:
				PORTD |= (1<<PIND7);
				break;
			}
		}
	}
	if (!val)
	{
		if (port == 0)
		{
			switch (pin)
			{
			case 0:
				PORTA &= ~(1<<PINA0);
				break;
			case 1:
				PORTA &= ~(1<<PINA1);
				break;
			case 2:
				PORTA &= ~(1<<PINA2);
				break;
			case 3:
				PORTA &= ~(1<<PINA3);
				break;
			case 4:
				PORTA &= ~(1<<PINA4);
				break;
			case 5:
				PORTA &= ~(1<<PINA5);
				break;
			case 6:
				PORTA &= ~(1<<PINA6);
				break;
			case 7:
				PORTA &= ~(1<<PINA7);
				break;
			}
		}
		if (port == 1)
		{
			switch (pin)
			{
			case 0:
				PORTB &= ~(1<<PINB0);
				break;
			case 1:
				PORTB &= ~(1<<PINB1);
				break;
			case 2:
				PORTB &= ~(1<<PINB2);
				break;
			case 3:
				PORTB &= ~(1<<PINB3);
				break;
			case 4:
				PORTB &= ~(1<<PINB4);
				break;
			case 5:
				PORTB &= ~(1<<PINB5);
				break;
			case 6:
				PORTB &= ~(1<<PINB6);
				break;
			case 7:
				PORTB &= ~(1<<PINB7);
				break;
			}
		}
		if (port == 2)
		{
			switch (pin)
			{
			case 0:
				PORTC &= ~(1<<PINC0);
				break;
			case 1:
				PORTC &= ~(1<<PINC1);
				break;
			case 2:
				PORTC &= ~(1<<PINC2);
				break;
			case 3:
				PORTC &= ~(1<<PINC3);
				break;
			case 4:
				PORTC &= ~(1<<PINC4);
				break;
			case 5:
				PORTC &= ~(1<<PINC5);
				break;
			case 6:
				PORTC &= ~(1<<PINC6);
				break;
			case 7:
				PORTC &= ~(1<<PINC7);
				break;
			}
		}
		if (port == 3)
		{
			switch (pin)
			{
			case 0:
				PORTD &= ~(1<<PIND0);
				break;
			case 1:
				PORTD &= ~(1<<PIND1);
				break;
			case 2:
				PORTD &= ~(1<<PIND2);
				break;
			case 3:
				PORTD &= ~(1<<PIND3);
				break;
			case 4:
				PORTD &= ~(1<<PIND4);
				break;
			case 5:
				PORTD &= ~(1<<PIND5);
				break;
			case 6:
				PORTD &= ~(1<<PIND6);
				break;
			case 7:
				PORTD &= ~(1<<PIND7);
				break;
			}
		}
	}
}