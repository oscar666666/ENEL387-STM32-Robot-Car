 #include "stm32f10x.h"
 #include "ADC1.h"
void ADC1_Init(void){
	
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPAEN;
	GPIOA->CRL &= ~GPIO_CRL_CNF1;
	ADC1->CR2 = 0x00000001;
}

uint32_t ADC1_Read(int x){
	if (x==1){
	ADC1->SQR3 = 0x00000001;
	}
	else{
		ADC1->SQR3 = 0x00000002;
	}
	ADC1->CR2 = 0x00000001;
	while((ADC1->SR & ADC_SR_EOC) != ADC_SR_EOC){}
	return ADC1->DR;
	}