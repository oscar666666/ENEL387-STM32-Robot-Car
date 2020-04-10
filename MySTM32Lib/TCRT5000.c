 #include "stm32f10x.h"
 #include "TCRT5000.h"
 
  void TCRT5000_Input_Enable(){
	  GPIOC->CRH &=  ~GPIO_CRH_MODE13 & ~GPIO_CRH_CNF13_0 ;
    GPIOC->CRH |=  GPIO_CRH_CNF13_1 ;
		
			  GPIOC->CRH &=  ~GPIO_CRH_MODE14 & ~GPIO_CRH_CNF14_0 ;
    GPIOC->CRH |=  GPIO_CRH_CNF14_1 ;
		
			  GPIOC->CRH &=  ~GPIO_CRH_MODE15 & ~GPIO_CRH_CNF15_0 ;
    GPIOC->CRH |=  GPIO_CRH_CNF15_1 ;
 }
	
  int Read_PC13(){//tcrt5000 num 1

			if((GPIOC->IDR)&0x2000){
				return 1;
			}
			else{
				return 0;
			}
 }
	  int Read_PC14(){//tcrt5000 num 2

			if((GPIOC->IDR)&0x4000){
				return 1;
			}
			else{
				return 0;
			}
 }
int Read_PC15(){ //tcrt5000 num 3

			if((GPIOC->IDR)&0x8000){
				return 1;
			}
			else{
				return 0;
			}
 }