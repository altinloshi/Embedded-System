/*
 * AltinVinayakLab7.c
 *
 * Created: 26/09/2023 14:51:59
 * Author : Labs
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

int temp;
int main(void)
{
	DDRD = 0xFF;
	PORTD = 0xFF;
	//DDRC = 0x00;
	sei();
	PORTC = (0<<PC0);
    ADMUX |= (1<<REFS1) | (1<<REFS0) | (1<<ADLAR);
	ADCSRA |= (1<<ADSC) | (1<<ADEN) | (1<<ADATE) | (1 <<ADPS2) | (1 <<ADPS1) | (1 <<ADPS0) | (1<<ADIE);
	
	
    while (1) 
    {
    }
}

ISR(ADC_vect){
	temp= ADCL;
	PORTD = ADCH;

}