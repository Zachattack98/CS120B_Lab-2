/*	Partner(s) Name & E-mail: none
 *	Lab Section: 23
 *	Assignment: Lab #2 Exercise #4
 *	Exercise Description: Amusement ride cart capacity by weight limit.
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#include <stdlib.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpD = 0x00;
	unsigned char tlWt;
	while(1) {
		tmpA = PINA & 0xFF;
		tmpB = PINB & 0xFF;
		tmpC = PINC & 0xFF;
		tlWt = tmpA + tmpB + tmpC;
		if (tlWt > 140) {
			if (tmpA == tmpC) {	//both ends same, cart is balanced
				tmpD = tmpD | 0x01;
			}
		}
		if ((abs(tmpA - tmpC)) > 80) {
			tmpD = tmpD | 0x02;
		}
		PORTD = tlWt & 0xFC;
		PORTD = PORTD | tmpD;
	}
	return 1;
}
		
