#include <stdint.h>
 #include "stm32f10x.h"

  void led_IO_init (void);
	void GPIOA_Write_Zero(int x);
	int GPIOB_Read(int x);
	int GPIOC_Read(int x);
	int GPIOA_Read(int x);
	void GPIOA_Write_One(int x);
	void Motor_init (void);
void GPIOB_Write_One(int);
	void	GPIOB_Write_Zero(int);
	void GPIO_Ports_Init();
	void GPIO_Buzzer_Enable();
	void GPIO_AFIO_Init();
	void GPIOC_Write_Zero(int x);
	void GPIOC_Write_One(int x);