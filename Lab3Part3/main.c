#include "msp.h"
#include "src/drv2605l.h"
#include "src/pwm.h"
#include "src/i2c.h"
#include "src/gpio.h"


/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	config_i2c();

	config_drv2605L();

    P2DIR |= 0x1;
    P2SEL0 = 0;
    P2SEL1 = 0;

	timerA0_config(0.05);

	while(1){
	    if(flag == 1){
	        P5OUT ^= BIT2;
	        P2OUT ^= BIT0;
	        flag = 0;
	    }
	}


//    while(1){
//        if(flag == 1){
//            P2OUT ^= BIT0;
//            flag = 0;
//        }
//    }

}
