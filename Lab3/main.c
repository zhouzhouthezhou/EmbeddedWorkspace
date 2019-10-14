#include "msp.h"
#include "src/TIMERA0INT.h"

#ifndef PWM_H_
#define PWM_H_
#endif

#define SYSTEM_CLOCK    3000000;
#define PWM_FREQUENCY   100000;
#define CALC_PERIOD(X)  (SYSTEM_CLOCK / X)


/**
 * main.c
 */
void part1(){
    config_pwm_gpio();
	config_pwm_timer();
	start_pwm(100);
}

void main(void){
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	timerA0_config(0.05);


	P2DIR |= 0x1;
	P2SEL0 = 0;
	P2SEL1 = 0;
	int isUp = 0;

	__enable_irq();

	while(1){
	    if(flag == 1){
	        P2OUT ^= BIT0;
	        flag = 0;
	    }
	}
}
