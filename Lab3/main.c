#include "msp.h"
#include "src/part1.h"
#include "src/part2.h"


#ifndef PWM_H_
#define PWM_H_
#endif

/**
 * main.c
 */
void part1(){
    config_pwm_gpio();
	config_pwm_timer();
	start_pwm(100);
	while(1);
}

void part2(){
	timerA0_config(0.05);


	P2DIR |= 0x1;
	P2SEL0 = 0;
	P2SEL1 = 0;

	__enable_irq();

	while(1){
	    if(flag == 1){
	        P2OUT ^= BIT0;
	        flag = 0;
	    }
	}

}

void main(void){
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
//	part1();
	part2();
}
