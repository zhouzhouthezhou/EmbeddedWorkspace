#include "msp.h"
#include "TIMERA0INT.h"

//#ifdef TIMERA0INT
//#define TIMERA0INT
//#endif

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
////////////////////////////////////////////////////////////////////////////////
void timerA0_config(float period){
    TA0R = 0x0;
    TA0CTL = TASSEL_2 + MC_1 + ID__4;
    TA0CCTL0 = OUTMOD_3 + CCIE; //set compare mode, output mode, interrupt flag
    TA0CCR0 = ((3000000/4)*(0.05));
    __NVIC_SetPriority(TA0_0_IRQn, 2);
    __NVIC_EnableIRQ(TA0_0_IRQn);
    __enable_irq();
}

void TA0_0_IRQHandler(void){
    flag = 1;
    printf("help");
}

