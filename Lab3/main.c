#include "msp.h"
#include "src/TimerA0int.c"

#ifndef PWM_H_
#define PWM_H_
#endif

#define SYSTEM_CLOCK    3000000;
#define PWM_FREQUENCY   100000;
#define CALC_PERIOD(X)  (SYSTEM_CLOCK / X)

/**
 * main.c
 */

/*
 * - TODO: reset R (timer counter) register
 * - TODO: select SMCLK (3MHz) in the CTL register
 * - TODO: select reset/set output mode for T0.1 timer using CCTL[1]
 */
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
    int ccr0 = 30;
    TA0CCR0 = ccr0; //freq = sysclk/ccr0; 3MHZ/30 = 100kHz
    TA0CCR1 = 0.01 * (duty_cycle) * ccr0;
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

void main(void){
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	config_pwm_gpio();
	config_pwm_timer();
	start_pwm(100);

/*
	P2DIR |= 0x10;
	P2SEL0 |= 0x10;
	P2SEL1 &= ~0x10;

	TA0CCR0 = 10; //freq = sysclk/ccr0
    TA0CCTL1 = OUTMOD_7;
	TA0CCR1 = 10;

	TA0CTL = TASSEL_2 + MC_1;
*/
	while(1);
}
