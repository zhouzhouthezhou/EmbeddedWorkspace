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
	config_pwm_gpio();
	config_pwm_timer();
	start_pwm(100);
}
