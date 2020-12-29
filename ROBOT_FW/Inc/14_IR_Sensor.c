

                         /***********14_IR Sensor : Function Definitions**************/
/*Includes    */
#include "14_IR_Sensor.h"


/* External Varaibles */
extern TIM_HandleTypeDef htim3;

void Start_Timer3_IR2()
{
HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_1);
}

void Start_Timer3_IR1()
{
HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_2);
}











/************* IR_Sensor : End Of File **************/







