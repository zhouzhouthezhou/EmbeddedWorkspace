/*
 * part1.c
 *
 *  Created on: Oct 14, 2019
 *      Author: kylez
 */
#include "pwm.h"
#include "msp.h"

void timerA0_config(float period){
    TA0R = 0x0;
    TA0CTL = TASSEL_2 + MC_1 + ID__8 + TAIE;
    TA0CCTL0 = OUTMOD_7 + CCIE; //set compare mode, output mode, interrupt flag
    TA0CCR0 = ((3000000/8)*(period));
    __NVIC_SetPriority(TA0_N_IRQn, 2);
    __NVIC_EnableIRQ(TA0_N_IRQn);
    __enable_irq();
}

void TA0_N_IRQHandler(void){
    flag = 1;
    TA0CTL &= ~TIMER_A_CTL_IFG;
}

