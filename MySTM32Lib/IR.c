 #include "stm32f10x.h"
 #include "IR.h"
 #include "Clock.h"
 
uint32_t data;
uint8_t count;

 
 //pc10
 void GPIOC_Input_Enable(){
	  GPIOC->CRH &=  ~GPIO_CRH_MODE10 & ~GPIO_CRH_CNF10_0 ;
    GPIOC->CRH |=  GPIO_CRH_CNF10_1 ;
 }
 
 int Read_PC10(){

			if((GPIOC->IDR)&0x0400){
				return 1;
			}
			else{
				return 0;
			}
	 
 }
 
//modified from https://controllerstech.com/ir-remote-with-stm32/
uint32_t receive_data (void)
{
	uint32_t code=0;
	  while (!(Read_PC10()));
	  while ((Read_PC10()));
	  for (int i=0; i<32; i++)
	  {
		  count=0;

		  while (!(Read_PC10())); // wait for pin to go high.. this is 562.5us LOW

		  while ((Read_PC10()))  // count the space length while the pin is high
		  {
			  count++;
			  delay(600);
		  }

		  if (count > 12) // if the space is more than 1.2 ms
		  {
			  code |= (1UL << (31-i));   // write 1
		  }

		  else code &= ~(1UL << (31-i));  // write 0
	  }
		
		return code;
}