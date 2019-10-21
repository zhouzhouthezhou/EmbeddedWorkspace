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
	timerA0_config(0.00001);
	config_i2c();
	config_drv2605L();



    while(1){
        if(flag == 1){
            P5OUT ^= BIT0;
            flag = 0;
        }
    }

}
