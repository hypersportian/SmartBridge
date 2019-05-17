/*
 * PIR Sensor.c
 *
 * Created: 5/13/2019 10:44:50 AM
 * Author : Razeen Ahamed
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>

#define LED_OUTPUT PORTB
#define PIR_Input PINC


int main(void)
{
	DDRC = 0x00; // Set the PIR Port as I/P Port 
	DDRB = 0xFF; // Set the LED Port as O/P Port
    while (1) 
    {   
		_delay_ms(1000);
		LED_OUTPUT = PIR_Input; // When Sensor detected LED will be HIGH
		_delay_ms(1000);
    }
}

