#include "msp.h"
#include "drv2605l.h"
#include "pwm.h"
#include "i2c.h"
#include "gpio.h"


/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
}
