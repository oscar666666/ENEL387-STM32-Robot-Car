 #include "stm32f10x.h"
 #include "LCD.h"
  #include "Clock.h"

void LCD_IO_Init(void){
	//Enable peripheral clocks for various ports and subsystems
    //Bit 4: Port C Bit3: Port B Bit 2: Port A
    RCC->APB2ENR |=  RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPBEN
        | RCC_APB2ENR_IOPAEN ;

    //Set the config and mode bits for Port C bit 9 and 8 so they will
    // be push-pull outputs (up to 50 MHz)
    GPIOB->CRL |= GPIO_CRL_MODE0 | GPIO_CRL_MODE1 | GPIO_CRL_MODE5;
	
	  GPIOC->CRL |= GPIO_CRL_MODE0 | GPIO_CRL_MODE1 | GPIO_CRL_MODE2 |
									GPIO_CRL_MODE3 | GPIO_CRL_MODE4 | GPIO_CRL_MODE5 |
									GPIO_CRL_MODE6 | GPIO_CRL_MODE7;

    GPIOC->CRL &= ~GPIO_CRL_CNF0_0     & ~GPIO_CRL_CNF1_0     & ~GPIO_CRL_CNF2_0     & 
									~GPIO_CRL_CNF3_0     & ~GPIO_CRL_CNF4_0     & ~GPIO_CRL_CNF5_0     &
									~GPIO_CRL_CNF6_0     & ~GPIO_CRL_CNF7_0    ;
	
	  GPIOB->CRL &= ~GPIO_CRL_CNF0_0     & ~GPIO_CRL_CNF1_0     & ~GPIO_CRL_CNF5_0    ;

}

/*
* Name: commandToLCD
* Type: PUBLIC
* Parameters: a single byte of command information for the LCD controller
* Returns: nothing
* Description: This function generates control timing and data signals to send one command byte to the LCD
*/
void commandToLCD(uint8_t data)
{
GPIOB->BSRR = LCD_CM_ENA; //RS low, E high
// GPIOC->ODR = data; //BAD: may affect upper bits on port C
GPIOC->ODR &= 0xFF00; //GOOD: clears the low bits without affecting high bits
GPIOC->ODR |= data; //GOOD: only affects lowest 8 bits of Port C
delay(8000);
GPIOB->BSRR = LCD_CM_DIS; //RS low, E low
delay(80000);
}

void dataToLCD(uint8_t data)
	{

GPIOB->BSRR = LCD_DM_ENA; //RS low, E high
// GPIOC->ODR = data; //BAD: may affect upper bits on port C
GPIOC->ODR &= 0xFF00; //GOOD: clears the low bits without affecting high bits
GPIOC->ODR |= data; //GOOD: only affects lowest 8 bits of Port C
delay(8000);
GPIOB->BSRR = LCD_DM_DIS; //RS low, E low
delay(80000);
}
void LCD_init_trans(){
	
commandToLCD(0x38);
	delay(80000);
commandToLCD(0x38);
	delay(80000);
commandToLCD(0x38);

commandToLCD(0x38);

commandToLCD(0x0F);

commandToLCD(0x01);

commandToLCD(0x06);
}
void reg_out( uint32_t reg_data){
int i;
uint32_t shifted_val;
uint8_t print_val;
dataToLCD (0x30);
dataToLCD (0x78);
for ( i=28; i >= 0 ; i = (i-4))
{
shifted_val = (reg_data >> i) & 0xf;
	if (shifted_val > 0x9){
		shifted_val = shifted_val - 0x9;
		print_val = (shifted_val | 0x40);
	}
	else{
		print_val = (shifted_val | 0x30);
	}
dataToLCD(print_val);
}
dataToLCD(0x20);
}
