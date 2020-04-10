#include <stdint.h>
 #include "stm32f10x.h"
void PWM_Init(void);
void set_DutyCycle(int x);
void PWM_TIM2_Init(void);
void Motor_init (void);
void PWM_CH2_Init(void);
void PWM_CH3_Init(void);
void PWM_CH1_Init(void);
void PWM_CH4_Init(void);
void MoveForward();
void MoveBackward();
void MoveLeft();
void MoveRight();
