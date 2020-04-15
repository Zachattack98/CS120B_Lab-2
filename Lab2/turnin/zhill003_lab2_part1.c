/*	Author: zhill003
 *  Partner(s) Name: none
 *	Lab Section: 23
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
   DDRA = 0x00; PORTA = 0xFF; //Configure inputs
   DDRB = 0xFF; PORTB = 0x00; //Configure outputs
   unsigned char tmpB = 0x00; //Temporary variable to hold the value of B
   unsigned char tmpA = 0x00; //Temporary variable to hold the value of B
    while (1) {
       //Read input
       tmpA = PINA & 0x03;  	//mask is used to make only first two bits unique

	//Computation
	if(tmpA == 0x01) {
		tmpB = (tmpB & 0xFE) | 0x01;
	}
	else {
		tmpB = (tmpB & 0xFE) | 0x00;
	}
	//Write Output
	PORTB = tmpB;
    }
    return 1;
}
