/*
 * part2.c
 *
 *  Created on: Oct 14, 2019
 *      Author: kylez
 */
#include "gpio.h"

#include "msp.h"

void config_drv_gpio(){
    P5DIR |= 0x5;
    P5SEL0 = 0;
    P5SEL1 = 0;
    P5OUT |= BIT0 + BIT2;
}
