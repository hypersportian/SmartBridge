/*
 * LED Scroll.c
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
	DDRB= 0x01;
	int i;
		
	while (1)
	{
		for(i=0;i<8;i++)
		{
			PORTB=1<<PORTB;
		}
		_delay_ms(100);
		for(i=8;i>0;i--)
		{
			PORTB=1>>PORTB;
		}
		_delay_ms(100);
	}
}
