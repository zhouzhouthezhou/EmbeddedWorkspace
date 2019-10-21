#include "msp.h"
#include "i2c.h"
#include "gpio.h"

#define DRV2605L    0x5A
#define STATUS      0x00
#define MODE        0x01
#define GO          0x0C
#define CONTROL3    0X1D
#define MODE_PWM    0x03
#define MODE_STBY   (1 << 6)
#define GO_GO       0x01
#define LIBRARY     0x03

void config_drv2605L(void (*toggle_routine)()) {
    config_drv_gpio();
    toggle_routine();

    int i;
    uint8_t mode_reg, control_three_reg;
    for (i = 0; i < 100000; i++);

    write_register(DRV2605L, MODE, 0);// come out of STBY
    write_register(DRV2605L, MODE, MODE_PWM);   // set MODE to 3
    write_register(DRV2605L, CONTROL3, MODE_PWM);   // set CONTROL3 to PWM
    // select LRA library

    mode_reg = read_register(DRV2605L, MODE);
    if(mode_reg != (MODE_PWM)) {
        P1DIR |= BIT0;
        P1OUT |= BIT0;
    }

    control_three_reg = read_register(DRV2605L, CONTROL3);
    if(control_three_reg != 0x00) {
        P1DIR |= BIT0;
        P1OUT |= BIT0;
    }
}
