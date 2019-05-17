/*
 * DC Motor.c
 *
 * Created: 5/15/2019 2:27:40 PM
 * Author : Razeen Ahamed
 */ 
#ifndef F_CPU
#define F_CPU 8000000UL 
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRC = 0xFF;
    while(1)
    {
        //Rotates Motor in Antilockwise 
		PORTC = 0x01; //00000001
		_delay_ms(2000);
		
		//Stops Motor
		PORTC = 0x00; //00000000
		_delay_ms(500);
		
		//Rotates Motor in Clockwise
		PORTC = 0x02; //00000010
		_delay_ms(2000);
		
		//Stops Motor
		PORTC = 0x03; //00000011
		_delay_ms(500);
    }
}