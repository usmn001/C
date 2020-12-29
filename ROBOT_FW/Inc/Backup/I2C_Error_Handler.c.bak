

#include "I2C_Error_Handler.h"

static uint8_t state=0;
static uint8_t error = 0;





void i2c1_stop_signal()      
{
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);	
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,GPIO_PIN_RESET);	
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,GPIO_PIN_SET);	
}

void i2c1_error_handler(void)
{
state = HAL_I2C_GetState(&hi2c1);          
error = HAL_I2C_GetError(&hi2c1);          
}	 
	
void i2c2_error_handler(void)
{
state = HAL_I2C_GetState(&hi2c2);          
error = HAL_I2C_GetError(&hi2c2);          
}	 	

/*
void i2c2_error_handler(void)
{
state = HAL_I2C_GetState(&hi2c2);          
error = HAL_I2C_GetError(&hi2c2);
	switch(state)
	{
		case  0x00 :	    printf("I2C not yet initialized or disabled "); 
                      printf(" \n I2C State : %i ",state );		
			                break;      
		
    case  0x01 :      printf("I2C initialized and ready for use "); 
		                  printf(" \n I2C State : %i ",state );
                			break;  
		
    case  0x02 :      printf("I2C internal process is ongoing  "); 
		                  printf(" \n I2C State : %i ",state ); 
                			break;        
		
    case  0x12 :      printf("Data Transmission process is ongoing  ");
		                  printf(" \n I2C State : %i ",state );
		                  break;
		
    case  0x22 :      printf("Data Reception process is ongoing  ");
		                  printf(" \n I2C State : %i ",state );
		                  break;
		
    case  0x42 :      printf("Memory Data Reception process is ongoing  ");
		                  printf(" \n I2C State : %i ",state );
			                break;		
											
    case  0x03 :      printf("I2C timeout state  ");
		                  printf(" \n I2C State : %i ",state );
		                  break;
											
    case  0x04 :      printf("I2C error state  ");
		                  printf(" \n I2C State : %i ",state );
		                  break;
	}
	
	
	switch(error)
	{
		case  0x00 :	    printf(" \n No error"); 
                      printf(" \n I2C Error Code : %i ",error );		
			                break;      
		
    case  0x01 :      printf(" \n BERR error "); 
		                  printf(" \n I2C Error Code : %i ",error );
                			break;  
		
    case  0x02 :      printf(" \n ARLO error  "); 
		                  printf(" \n I2C Error Code : %i ",error );
                			break;        
		
    case  0x04 :      printf(" \n AF error");
		                  printf(" \n I2C Error Code : %i ",error );
		                  break;
		
    case  0x08 :      printf(" \n OVR error ");
		                  printf(" \n I2C Error Code : %i ",error );
		                  break;
		
    case  0x10 :      printf(" \n DMA transfer error ");
		                  printf(" \n I2C Error Code : %i ",error );
			                break;		
											
    case  0x20 :      printf(" \n Timeout Error   ");
		                  printf(" \n I2C Error Code : %i ",error );
		                  break;
	


}


}*/





                       /***************************End Of File***************/

