/*
 * part1.c
 *
 *  Created on: Oct 14, 2019
 *      Author: kylez
 */
#include "pwm.h"
#include "msp.h"


void config_pwm_timer(void){
    TA0R = 0x0;
	TA0CTL = TASSEL_2 + MC_1;
	TA0CCTL1 = OUTMOD_7;
}
/*  - TODO: Start PWM signal on Pin XX at duty_cycle 100kHz,
 *    Note: the DRV2605L PWM input frequency is XXXX
 *  - TODO: calculate and set the amount of ticks needed in CCR
 *  - TODO: enable/start timer (UP mode)
 *  - TODO: Counting and then reset
 * @param uint8_t duty_cycle: 0-100, percentage of time ON */
void start_pwm(uint8_t duty_cycle){
    int ccr0 = 29;
    TA0CCR0 = ccr0; //freq = sysclk/ccr0; 3MHZ/30 = 100kHz
//    TA0CCR1 = 0.01 * (duty_cycle) * ccr0;
    TA0CCR1 = ccr0;
}
/* Stop Mode: clear all Mode Control bits, MC, in TAxCTL register */
void stop_pwm(void){
    TA0CTL = 0x0;
}
/* Config P2.4 to output TA0.1 waveform */
void config_pwm_gpio(void){
	P2DIR |= 0x10;
	P2SEL0 |= 0x10;
	P2SEL1 &= ~0x10;
}

