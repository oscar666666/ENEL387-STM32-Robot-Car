 #include "stm32f10x.h"
 #include "GPIO.h"
// SWITCH AND LED I/O FUNCTIONS

void led_IO_init (void)
{
    //Enable peripheral clocks for various ports and subsystems
    //Bit 4: Port C Bit3: Port B Bit 2: Port A
    RCC->APB2ENR |=  RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPBEN
        | RCC_APB2ENR_IOPAEN ;

    //Set the config and mode bits for Port C bit 9 and 8 so they will
    // be push-pull outputs (up to 50 MHz)

}

void GPIO_Ports_Init(){
    RCC->APB2ENR |=  RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPBEN
        | RCC_APB2ENR_IOPAEN ;

}

void GPIO_Buzzer_Enable(){
    GPIOC->CRH |= GPIO_CRH_MODE9;// | GPIO_CRH_MODE10 ;
    GPIOC->CRH &= ~GPIO_CRH_CNF9;// & ~GPIO_CRH_CNF10 ;
   
}
void GPIO_AFIO_Init(){


}

	void GPIOA_Write_Zero(int x){
		
		uint32_t Mask = 0xffff;
		uint32_t Mask2 = 0x0001;
		Mask2 = Mask2<<x;
		uint32_t Temp = Mask^Mask2;
		GPIOA->ODR &=Temp;
}
	void GPIOA_Write_One(int x){
		
		
		uint32_t Mask2 = 0x0001;
		Mask2 = Mask2<<x;

		GPIOA->ODR |=Mask2;
}
	
	void GPIOC_Write_Zero(int x){
		
		uint32_t Mask = 0xffff;
		uint32_t Mask2 = 0x0001;
		Mask2 = Mask2<<x;
		uint32_t Temp = Mask^Mask2;
		GPIOC->ODR &=Temp;
}
	void GPIOC_Write_One(int x){
		
		
		uint32_t Mask2 = 0x0001;
		Mask2 = Mask2<<x;

		GPIOC->ODR |=Mask2;
}
	

	void GPIOB_Write_Zero(int x){
		
		uint32_t Mask = 0xffff;
		uint32_t Mask2 = 0x0001;
		Mask2 = Mask2<<x;
		uint32_t Temp = Mask^Mask2;
		GPIOB->ODR &=Temp;
}
	void GPIOB_Write_One(int x){
		
		
		uint32_t Mask2 = 0x0001;
		Mask2 = Mask2<<x;

		GPIOB->ODR |=Mask2;
}
	int GPIOB_Read(int x){
			uint32_t gpiobb;
			gpiobb = (GPIOB->IDR);
			uint32_t Mask = 0x0001;
			Mask = Mask<<x;
			return gpiobb&Mask;	
}
		int GPIOC_Read(int x){
			uint32_t gpiocc;
			gpiocc = (GPIOC->IDR);
			uint32_t Mask = 0x0001;
			Mask = Mask<<x;
			return gpiocc&Mask;
}
			int GPIOA_Read(int x){
			uint32_t gpioaa;
			gpioaa = (GPIOA->IDR);
			uint32_t Mask = 0x0001;
			Mask = Mask<<x;
			return gpioaa&Mask;		
}
			