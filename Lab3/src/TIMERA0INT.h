#define TIMERA0INT


#ifdef TIMERA0INT

void config_pwm_timer(void);
void start_pwm(uint8_t duty_cycle);
void stop_pwm(void);
void timerA0_config(unsigned short period);
void timerA0_IRQHandler(void);
volatile static int flag;

void __NVIC_EnableIRQ(IRQn_Type IRQn);

#endif
