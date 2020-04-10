/* First Program in C */
/* Author � Chengyu Lou, Jan 2020 */
/* -----------
* FILENAME: something.c |
* 
* DESCRIPTION: 

* Something that clearly indicates the function of this program 
* 
* AUTHOR: (your name, your co-developers names, your SID) 
*/
#include "MySTM32Lib\Clock.h" 
#include "MySTM32Lib\GPIO.h" 
#include "MySTM32Lib\LCD.h" 
#include "MySTM32Lib\PWM.h" 
#include "MySTM32Lib\ADC1.h" 
#include "MySTM32Lib\IR.h" 
#include "MySTM32Lib\HCSR04.h"
#include "MySTM32Lib\TCRT5000.h"
#include "stm32f10x.h"
void Read_IR_Key();
uint32_t dataRead;
uint32_t dd = 0;

int main (void) {

	clockInit();
	GPIO_Ports_Init();
	//lcd
	LCD_IO_Init();
	LCD_init_trans();
	
	//buzzer led
	GPIO_Buzzer_Enable();

	//pwm
	Motor_init ();
	PWM_CH2_Init();
	PWM_CH3_Init();
	PWM_CH1_Init();
	PWM_CH4_Init();

	//IR receiver
	GPIOC_Input_Enable();
	
	//Temp sensor
    ADC1_Init();
	
	//ultrasonic
	Echo_Input_Enable();
	Trig_Output_Enable();

	//Line tracking
	TCRT5000_Input_Enable();


while(1){
	
	for(int i = 0; i<99999; i++){
	//Read 6 times every iteration
		if(!Read_PC10()){
				Read_IR_Key();
		}
		if(!Read_PC10()){
				Read_IR_Key();
		}
		if(!Read_PC10()){
				Read_IR_Key();
		}
		if(!Read_PC10()){
				Read_IR_Key();
		}
		if(!Read_PC10()){
				Read_IR_Key();
		}
		if(!Read_PC10()){
				Read_IR_Key();
		}
//measure distance every 20 iteration
		if(i%20 == 0){

			dd = Get_Distance()/58;//get distance in cm
			commandToLCD(LCD_LN2);
			reg_out(dd);
			
			if (dd < 10){
				GPIOC_Write_One(9);//sound buzzer
				set_DutyCycle(0);//stop motors
			}
			else {
				GPIOC_Write_Zero(9); //mute buzzer
			}
		}
	}

	//reg_out(Get_Distance());//read ultrasonic sensor data

	//reg_out(ADC1_Read(1));//read adc1 temp sensor

 }
}

void Read_IR_Key(){
		//while(Read_PC10());
		dataRead = receive_data ();
	//reg_out(dataRead); //display command
		if(dataRead == 16736925){ //up button
			dataToLCD(0x42);
			MoveForward();

		}
		else if (dataRead == 16754775){//down
			dataToLCD(0x43);
			MoveBackward();

		}
		else if (dataRead == 16720605){//left
			dataToLCD(0x44);
			MoveLeft();

		}
		else if (dataRead == 16761405){//right
			dataToLCD(0x45);
			MoveRight();
		}
		else if (dataRead == 16712445){//middle
			dataToLCD(0x46);
			set_DutyCycle(0);
			GPIOC_Write_Zero(9); //mute buzzer
			
		}
		else if (dataRead == 0x00ff6897){//1 button
			dd = 0;
			dd = Get_Distance()/58;
			commandToLCD(LCD_LN2);
			reg_out(dd);
			if (dd < 10){
			GPIOC_Write_One(9);//sound buzzer
			set_DutyCycle(0);
			}
			else {
				GPIOC_Write_Zero(9); //mute buzzer
			}
		}
			else if (dataRead == 0x00ff9867){//2 button
			commandToLCD(LCD_LN2);
			reg_out(ADC1_Read(0));//read adc1 temp sensor
			
		}
		else if (dataRead == 0x00ffb04f){//3 button
			dataToLCD(Read_PC13() | 0x30);

		}
		else{
			commandToLCD(LCD_CLR);//clear lcd
		}


		delay (200*6000);
	}
