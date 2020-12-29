


            /*******************DAC AUDIO OUT*****************/


// Includes
#include "17_DAC_Audio.h"

// External Variables
extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim6;
extern DAC_HandleTypeDef hdac;

void Amp_En()
{
HAL_GPIO_WritePin(GPIOE,AMP_CTR_LCD_Pin,GPIO_PIN_SET); 
}
                                 
void Amp_Da()
{
HAL_GPIO_WritePin(GPIOE,AMP_CTR_LCD_Pin,GPIO_PIN_RESET); 
}	


void DAC_Start()
{
Amp_En();	
HAL_TIM_Base_Start(&htim6);
HAL_DAC_Start(&hdac,DAC_CHANNEL_2);
HAL_DAC_SetValue(&hdac, DAC_CHANNEL_2,DAC_ALIGN_12B_R,0x100);
}

/*
void DAC_Stop()
{
Amp_Da();	            
HAL_DAC_Stop(&hdac,DAC_CHANNEL_2);
}*/							





																		 /* End Of File */

