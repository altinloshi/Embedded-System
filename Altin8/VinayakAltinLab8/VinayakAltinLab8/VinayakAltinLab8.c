/*
 * VinayakAltinLab8.c
 *
 * Created: 09/10/2023 14:25:36
 * Author : Labs
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>



int main(void)
{
	ADMUX |= (1<<REFS1) | (1<<REFS0) | (1<<ADLAR); //ADLAR left adjust all the bits such that the most significant bits are read
	ADCSRA |= (1<<ADEN) | (1<<ADSC) | (1<<ADPS2) | (0<<ADPS1) | (1<<ADPS0); //enables and sets relevant ADC bits to allow conversion to occurs
	
	DDRB |= (1<<PB1) | (1<<PB2); //Enables the Pins OC1A and OC1B
	TIMSK1 |= (1<<OCIE1A);
	TCCR1A |= (1<<COM1A1) | (0<<COM1A0) |(1<<COM1B1) | (0<<COM1B0) | (1<<WGM11) | (0<<WGM10);
	/*for TCCR1A/B the WGWM pins set the mode to PWN mode and in this instance the top val is OCR1A*/
	TCCR1B |= (1<<WGM12) | (1<<CS10) | (0<<WGM13);
	
	sei();
	int temp;
	temp = ADCL;
    while (1)
    {
		OCR1A = ADCH ; //Changes the top resert on compare match value based on the ADC conversion changing the power delivered for OC1A 
		OCR1B =ADCH; ////Changes the top resert on compare match value based on the ADC conversion changing the power delivered OC1B
		_delay_ms(10);
		
    } 
}

