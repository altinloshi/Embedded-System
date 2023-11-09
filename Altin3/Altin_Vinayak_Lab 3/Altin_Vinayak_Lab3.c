/*
 * Altin_Vinayak_Lab 3.c
 *
 * Created: 12/09/2023 14:41:19
 * Author : Labs
 */ 

#include <avr/io.h>
#define F_CPU 4000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
    DDRD = 0x00;
	DDRB = 0xFF;
	sei();
	EIMSK = 0b00000001;
	EICRA = 0b00000011;
	while(1){
		PORTB = 0b00000001;
		_delay_ms(500);
		PORTB = 0b00000010;
		_delay_ms(500);
		PORTB = 0b00000100;
		_delay_ms(500);
	}
}

ISR(INT0_vect){
	PORTB = 0x00;
	_delay_ms(1000);
	PORTB = 0xFF;
	_delay_ms(1000);
	PORTB = 0x00;
	_delay_ms(1000);
	PORTB = 0xFF;
	_delay_ms(1000);
	PORTB = 0x00;
	_delay_ms(1000);
	PORTB = 0xFF;
	_delay_ms(1000);
}
