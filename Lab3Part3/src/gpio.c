/*
 * part2.c
 *
 *  Created on: Oct 14, 2019
 *      Author: kylez
 */
#include "gpio.h"

#include "msp.h"

void config_drv_gpio(){
    P5DIR |= BIT0 + BIT2;
    P5SEL0 = 0;
    P5SEL1 = 0;
    P5OUT |= BIT0 + BIT2;

    P2DIR |= 0x1;
    P2SEL0 = 0;
    P2SEL1 = 0;
    P2OUT = 0x1;
}
