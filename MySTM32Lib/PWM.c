 #include "stm32f10x.h"
 #include "PWM.h"


void PWM_Init(void){
	
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN | RCC_APB2ENR_TIM1EN;

	TIM1->CR1 |= TIM_CR1_CEN; // Enable Timer1
 TIM1->CR2 |= TIM_CR2_OIS1; // Output Idle State for Channel 1 OC1=1 when MOE=0
	//TIM1->CR2 |= TIM_CR2_OIS2;
	TIM1->CR2 |= TIM_CR2_OIS3;
	//TIM1->CR2 |= TIM_CR2_OIS4;
 TIM1->EGR |= TIM_EGR_UG; // Reinitialize the counter
	
 TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE |
TIM_CCMR1_OC1FE; //PWM mode 1, Preload Enable, Fast Enable
	// TIM1->CCMR1 |= TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2PE |
//TIM_CCMR1_OC2FE; 
	
	
	 TIM1->CCMR2 |= TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3PE |
TIM_CCMR2_OC3FE; 
	// TIM1->CCMR2 |= TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4PE |
//TIM_CCMR2_OC4FE; 
	
 //TIM1->CCMR2 not used for this application
 TIM1->CCER |= TIM_CCER_CC1E; //Enable CH1 output on PA8
  //TIM1->CCER |= TIM_CCER_CC2E; //Enable CH2 output on PA9
 TIM1->CCER |= TIM_CCER_CC3E; //Enable CH3 output on PA10
 //TIM1->CCER |= TIM_CCER_CC4E; //Enable CH4 output on PA11

 TIM1->PSC = 0x095F; //Divide 24 MHz by 2400 , PSC_CLK = 10000 Hz, 1 count = 0.1 ms
 TIM1->ARR = 100; // 100 counts = 10 ms
 TIM1->CCR1 = 10; // 10 counts = 1 ms = 10% duty cycle
  //TIM1->CCR2 = 100; // 10 counts = 1 ms = 10% duty cycle
 TIM1->CCR3 = 10; // 10 counts = 1 ms = 10% duty cycle
 //TIM1->CCR4 = 100; // 10 counts = 1 ms = 10% duty cycle

 TIM1->BDTR |= TIM_BDTR_MOE | TIM_BDTR_OSSI; //Main Output Enable, Force Idle Level First
 TIM1->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN; // Enable Timer1
}
void PWM_CH1_Init(void){
	
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN | RCC_APB2ENR_TIM1EN;

	TIM1->CR1 |= TIM_CR1_CEN; // Enable Timer1

	TIM1->CR2 |= TIM_CR2_OIS1;

 TIM1->EGR |= TIM_EGR_UG; // Reinitialize the counter
	
	 TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE |
TIM_CCMR1_OC1FE; 
	
  TIM1->CCER |= TIM_CCER_CC1E; //Enable CH2 output on PA9

 TIM1->PSC = 0x095F; //Divide 24 MHz by 2400 , PSC_CLK = 10000 Hz, 1 count = 0.1 ms
 TIM1->ARR = 100; // 100 counts = 10 ms
  TIM1->CCR1 = 10; // 10 counts = 1 ms = 10% duty cycle

 TIM1->BDTR |= TIM_BDTR_MOE | TIM_BDTR_OSSI; //Main Output Enable, Force Idle Level First
 TIM1->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN; // Enable Timer1
}

void PWM_CH2_Init(void){
	
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN | RCC_APB2ENR_TIM1EN;

	TIM1->CR1 |= TIM_CR1_CEN; // Enable Timer1

	TIM1->CR2 |= TIM_CR2_OIS2;

 TIM1->EGR |= TIM_EGR_UG; // Reinitialize the counter
	
	 TIM1->CCMR1 |= TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2PE |
TIM_CCMR1_OC2FE; 
	
  TIM1->CCER |= TIM_CCER_CC2E; //Enable CH2 output on PA9

 TIM1->PSC = 0x095F; //Divide 24 MHz by 2400 , PSC_CLK = 10000 Hz, 1 count = 0.1 ms
 TIM1->ARR = 100; // 100 counts = 10 ms
  TIM1->CCR2 = 10; // 10 counts = 1 ms = 10% duty cycle

 TIM1->BDTR |= TIM_BDTR_MOE | TIM_BDTR_OSSI; //Main Output Enable, Force Idle Level First
 TIM1->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN; // Enable Timer1
}

void PWM_CH3_Init(void){
	
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN | RCC_APB2ENR_TIM1EN;

	TIM1->CR1 |= TIM_CR1_CEN; // Enable Timer1

	TIM1->CR2 |= TIM_CR2_OIS3;

 TIM1->EGR |= TIM_EGR_UG; // Reinitialize the counter
	 TIM1->CCMR2 |= TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3PE |
TIM_CCMR2_OC3FE; 
	
  TIM1->CCER |= TIM_CCER_CC3E; //Enable CH2 output on PA9

 TIM1->PSC = 0x095F; //Divide 24 MHz by 2400 , PSC_CLK = 10000 Hz, 1 count = 0.1 ms
 TIM1->ARR = 100; // 100 counts = 10 ms
  TIM1->CCR3 = 10; // 10 counts = 1 ms = 10% duty cycle

 TIM1->BDTR |= TIM_BDTR_MOE | TIM_BDTR_OSSI; //Main Output Enable, Force Idle Level First
 TIM1->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN; // Enable Timer1
}

void PWM_CH4_Init(void){
	
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN | RCC_APB2ENR_TIM1EN;

	TIM1->CR1 |= TIM_CR1_CEN; // Enable Timer1

	TIM1->CR2 |= TIM_CR2_OIS4;

 TIM1->EGR |= TIM_EGR_UG; // Reinitialize the counter
	 TIM1->CCMR2 |= TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4PE |
TIM_CCMR2_OC4FE; 
	
  TIM1->CCER |= TIM_CCER_CC4E; //Enable CH2 output on PA9

 TIM1->PSC = 0x095F; //Divide 24 MHz by 2400 , PSC_CLK = 10000 Hz, 1 count = 0.1 ms
 TIM1->ARR = 100; // 100 counts = 10 ms
  TIM1->CCR4 = 10; // 10 counts = 1 ms = 10% duty cycle

 TIM1->BDTR |= TIM_BDTR_MOE | TIM_BDTR_OSSI; //Main Output Enable, Force Idle Level First
 TIM1->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN; // Enable Timer1
}

void Motor_init (void){
    // Write a 0xB ( 1011b ) into the configuration and mode bits for PA8 (AFIO)
    GPIOA->CRH |= GPIO_CRH_CNF8_1 | GPIO_CRH_MODE8_1 | GPIO_CRH_MODE8_0 ;
    GPIOA->CRH &= ~GPIO_CRH_CNF8_0 ;
	
	GPIOA->CRH |= GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9_1 | GPIO_CRH_MODE9_0 ;
    GPIOA->CRH &= ~GPIO_CRH_CNF9_0 ;

	GPIOA->CRH |= GPIO_CRH_CNF10_1 | GPIO_CRH_MODE10_1 | GPIO_CRH_MODE10_0 ;
    GPIOA->CRH &= ~GPIO_CRH_CNF10_0 ;

	GPIOA->CRH |= GPIO_CRH_CNF11_1 | GPIO_CRH_MODE11_1 | GPIO_CRH_MODE11_0 ;
    GPIOA->CRH &= ~GPIO_CRH_CNF11_0 ;
	
}
void set_DutyCycle(int x){
	
	TIM1->CCR1 = x; // 10 counts = 1 ms = 10% duty cycle
	TIM1->CCR3 = 0;
	TIM1->CCR2 = 0;
	TIM1->CCR4 = x;
	 TIM1->EGR |= TIM_EGR_UG; // Reinitialize the counter
}
void MoveForward(){
	
	TIM1->CCR1 = 70; // 10 counts = 1 ms = 10% duty cycle
	TIM1->CCR3 = 0;
	TIM1->CCR2 = 0;
	TIM1->CCR4 = 70;
	 TIM1->EGR |= TIM_EGR_UG; // Reinitialize the counter
}
void MoveBackward(){
	
	TIM1->CCR1 = 0; // 10 counts = 1 ms = 10% duty cycle
	TIM1->CCR2 = 70;
	TIM1->CCR3 = 70;
	TIM1->CCR4 = 0;
	 TIM1->EGR |= TIM_EGR_UG; // Reinitialize the counter
}
void MoveLeft(){
	
	TIM1->CCR1 = 0; // 10 counts = 1 ms = 10% duty cycle
	TIM1->CCR2 = 70;
TIM1->CCR3 = 0;
	TIM1->CCR4 = 70;
	 TIM1->EGR |= TIM_EGR_UG; // Reinitialize the counter
}
void MoveRight(){
	
	TIM1->CCR1 = 70; // 10 counts = 1 ms = 10% duty cycle
	TIM1->CCR2 = 0;
		TIM1->CCR3 = 70;

	TIM1->CCR4 = 0;
	 TIM1->EGR |= TIM_EGR_UG; // Reinitialize the counter
}
