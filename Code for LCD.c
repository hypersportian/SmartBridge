/*
 * Code for LCD.c
 *
 * Created: 5/10/2019 2:19:07 PM
 * Author : Razeen Ahamed
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define RS 7
#define E 5
void send_command(unsigned char command);
void send_character(unsigned char character);

int main(void)
{
    DDRC = 0xFF;
	DDRD = 0xFF;
	_delay_ms(50);
	send_command(0x01); // sending all clear command
	send_command(0x38); // 16*2 line LCD
	send_command(0x0E); // screen and cursor ON
	// Data to print
	send_character(0x72);
	send_character(0x61);
	send_character(0x7a);
	send_character(0x65);
	send_character(0x65);
	send_character(0x6e);
	
	
}
	void send_command(unsigned char command)
	{
		PORTC= command;
		PORTD&=~(1<<RS);
		PORTD|=(1<<E);
		_delay_ms(50);
		
		PORTD&=~(1<<E);
		PORTC=0;
	}
	void send_character(unsigned char character)
	{
		PORTC = character;
		PORTD |= (1<<RS);
		PORTD |= (1<<E);
		_delay_ms(50);
		
		PORTD &=~(1<<E);
		PORTC=0;
	}

