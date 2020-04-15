/* Partner(s) Name & E-mail: none
 * Lab Section: 23
 * Assignment: Lab #2 Exercise #3
 * Exercise Description: Open parking spaces set at zero bits. (extended)
 *
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char cntavail = 0x00;
	while(1) {
		tmpA = PINA & 0x0F;

		if (tmpA == 0x0F) {	//if all four spaces filled
			cntavail = tmpA;
			cntavail = cntavail | 0x80;
		}
		else if (tmpA == 0x07 || tmpA == 0x0B || tmpA == 0x0D || tmpA == 0x0E) {	//if spaces of three filled
			cntavail = tmpA;
		}
		else if (tmpA == 0x03 || tmpA == 0x05 || tmpA == 0x06 || tmpA == 0x09|| tmpA == 0x0A || tmpA == 0x0C) {	//if spaces of two filled
			cntavail = tmpA;
		}
		else if (tmpA == 0x01 || tmpA == 0x02 || tmpA == 0x04 || tmpA == 0x08) {	//if spaces of one filled
			cntavail = tmpA;
		}
		else {
			cntavail = tmpA;
		}
		PORTC = cntavail;
	}
	return 0;
}

