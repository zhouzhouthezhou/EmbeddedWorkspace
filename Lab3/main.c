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

	timerA0_config(150000);

	while(1){
	    if(flag == 1){

	    }
	}
}
