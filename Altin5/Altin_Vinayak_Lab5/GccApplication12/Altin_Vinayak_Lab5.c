/*
 * GccApplication12.c
 *
 * Created: 19/09/2023 14:11:47
 * Author : Labs
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define HIGH 0xFFFF
#define LOW 0xFFFF
#define  F_CPU 16000000UL
#include <util/delay.h>

void initTimer1() {
	TCCR1A =  (1<<COM1A0) ;
	TCCR1B = (1 << WGM12) | (0 << CS11) | (1 << CS10);
	
	DDRB |= (1 << PB1);
	
}


int main()
{
	initTimer1();
	OCR1A = 0xFFFF;
	//TIMSK1 |= (1 << TOIE1);
	TIMSK1 |= (1 << OCIE1A);
	sei();
	DDRD = 0xFF;
	PORTD = 0x00;
	PORTB = 0xFF;
    while (1) 
    {
    }
	return 0;
}
ISR(TIMER1_COMPA_vect){
	if(OCR1A == HIGH){
		OCR1A = LOW;
	}else if(OCR1A == LOW){
		OCR1A = HIGH;
	}
	PORTD ^= 0xFF;
}

