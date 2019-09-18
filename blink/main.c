#include "msp.h"


/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	P1DIR |= 0x01;  // ok
	P1OUT &= 0x00;
	int i;
	while(1){
	    P1OUT |= 0x01;
	    for(i = 0; i < 100000; i++);
	    P1OUT &= 0x00;
	    for(i = 0; i < 100000; i++);
	}
}
