/*
 * LED with Button.c
 *
 * Created: 5/10/2019 10:52:56 AM
 * Author : Razeen Ahamed
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include<util/delay.h>


int main(void)
{
    DDRC |=(1<<PC0); // MAKES FIRST PIN OF PORTC AS O/P OR DDRC = 0x01
	DDRD &= ~(1<<PD0); // MAKES FIRST PIN OF PORTD AS INPUT OR DDRD =0X00
	// MAKES ALL PINS OF PORTD AS INPUT
    while (1) // INFINITE LOOP
    {
		if ((PIND & (1<<PC0))== 0) // IF SWITCH IS PRESSED
		{
			PORTC |= (1<<PC0); // TURNS ON LED
			_delay_ms(200); // 3 SECOND DELAY
			PORTC &= ~(1<<PC0); // TURNS OFF LED
			_delay_ms(200);
		}
    }
}

