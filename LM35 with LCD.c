/*
 * LM35 with LCD.c
 *
 * Created: 5/13/2019 2:24:08 PM
 * Author : Razeen Ahamed
 */ 

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>
#include <stdlib.h>
#define enable 5
#define register_selection 7
void send_a_command(unsigned char command);
void send_a_character(unsigned char character);
void send_a_string(char *string_of_characters);


int main(void)
{
	DDRC = 0xFF;
	DDRA = 0x00;
	DDRD = 0xFF;
	_delay_ms(50);
	ADMUX |= (1<<REFS0)|(1<<REFS1);
	ADCSRA |= (1<<ADEN)|(1<<ADATE)|(1<<ADSP0)|(1<<ADSP1)|(1<<ADSP2);
	int16_t COUNTA = 0;
	char SHOWA[3];
	send_a_command(0x01);
	_delay_ms(50);
	send_a_command(0x38);
	_delay_ms(50);
	send_a_command(0b00001111);
	_delay_ms(50);
	ADCSRA |= (1<<ADSC);
	
	
    while (1) 
    {
		COUNTA = ADC/4;
		send_a_string("SMARTBRIDGE");
		send_a_command(0x80 + 0x40 + 0); 
		send_a_string("temp(c)=");
		send_a_command(0x80 + 0x40 + 0);
		itoa(COUNTA,SHOWA,10);
		send_a_string("");
		send_a_command(0x80 + 0);
    }
}

void send_a_command(unsigned char command)
{
	PORTC = command;
	PORTD&=~(1<<register_selection);
	PORTD |= (1<<enable);
	_delay_ms(20);
	PORTD&=~(1<<enable);
	PORTC = 0;
}

void send_a_character(unsigned char character)
{
	PORTC = character;
	PORTD|=(1<register_selection);
	PORTD|=(1<<enable);
	_delay_ms(20);
	PORTD&=~(1<<enable);
	PORTC = 0;
}

void send_a_string(char *string_of_characters);
{
	while (*string_of_characters>0)
	{
		send_a_character(*string_of_characters++);
	}
}