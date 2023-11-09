/*
 * GccApplication13.c
 *
 * Created: 25/09/2023 14:38:07
 * Author : Labs
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>



int main(void)
{
	DDRB |= (1<<PB1);
	TIMSK1 |= (1<<OCIE1A);
	TCCR1A |= (1<<COM1A1) | (0<<WGM10) | (1<<WGM11);
	TCCR1B |= (1<<WGM12) | (1<<CS10); 
	
	ICR1 = 0x03FF;
	OCR1A = 0xF;
    while (1) 
    {
		OCR1A = OCR1A + 15;
		_delay_ms(10);
		if(OCR1A == 0x03FF){
			OCR1A = 0xF;
		}
    }
}

