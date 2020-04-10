 #include "stm32f10x.h"
 #include "HCSR04.h"

  //pc12 enable input
 void Echo_Input_Enable(){
	  GPIOC->CRH &=  ~GPIO_CRH_MODE12 & ~GPIO_CRH_CNF12_0 ;
    GPIOC->CRH |=  GPIO_CRH_CNF12_1 ;
 }
 //pc11 enable gpio output
 void Trig_Output_Enable(){
    GPIOC->CRH |= GPIO_CRH_MODE11;// | GPIO_CRH_MODE10 ;
    GPIOC->CRH &= ~GPIO_CRH_CNF11;// & ~GPIO_CRH_CNF10 ;
   
}
  int Read_PC12(){

	if((GPIOC->IDR)&0x1000){
		return 1;
		}
	else{
		return 0;
		}
	 
 }

 //modified from https://controllerstech.com/hc-sr04-ultrasonic-sensor-and-stm32/
uint32_t Get_Distance(){
	uint32_t t =0;
	GPIOC_Write_Zero(11);
	delay(12);
	GPIOC_Write_One(11);//turn on trig pin
	delay(60);
	GPIOC_Write_Zero(11);//turn off trig pin
	while(!Read_PC12());
	while(Read_PC12()){
		t++;//count time
		delay(6);
	}
	return t;
}
	