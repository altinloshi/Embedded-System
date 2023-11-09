/*
 * Altin_Vinayak_Lab4.c
 *
 * Created: 18/09/2023 14:51:14
 * Author : Labs
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{	
	DDRD = 0xFF;
	PORTD = 0x00;
	sei();
    TIMSK1 = 0b00000001;
	TCCR1B = 0b00000011;
	while(1){
		
	}
	
}

ISR(TIMER1_OVF_vect){
	PORTD ^= 0xFF;
}