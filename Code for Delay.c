/*
 * Code for Delay.c
 *
 * Created: 5/15/2019 10:32:44 AM
 * Author : Razeen Ahamed
 */ 

#include <avr/io.h>
#define LED PB0


int main(void)
{
    uint8_t timeroverflowcount=0;
	DDRB=0xFF; // configure PORTD at o/p
	TCNT0=0x00;
	TCCR0=(1<<CS00)|(1<<CS02);
    while (1) 
    {
		
		while((TIFR&0x01)==0);
			TCNT0=0x00;
			TIFR=0x01; // clear timer1 overflow flag
			timeroverflowcount++;
			if (timeroverflowcount>=6)
			{
				PORTB^=(0x01<<LED);
				timeroverflowcount=0;
			}
		}
	}