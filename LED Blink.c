/*
 * LED Blink.c
 *
 * Created: 5/9/2019 2:17:23 PM
 * Author : Razeen Ahamed
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB= 0xFF;
    while (1)	
    {
		PORTB = 0xFF;
		_delay_ms(1000);
		PORTB = 0x00;
		_delay_ms(100);
				
    }
}

