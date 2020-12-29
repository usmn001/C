// Includes
#include "SPI_ERROR_HANDLER.h"
#include "15_LIGHTS.h"
// External Private Variables
extern SPI_HandleTypeDef hspi2;
extern SPI_HandleTypeDef hspi3;



void spi2_error_handler(uint8_t hal_status)
{
uint8_t state=0;
uint8_t error = 0;
switch(hal_status)
{
	case 0x01 : state = HAL_SPI_GetState(&hspi2);          // HAL_ERROR
              error = HAL_SPI_GetError(&hspi2);
	            led_red_on();
	            break;

  case 0x02 : state = HAL_SPI_GetState(&hspi2);          // HAL_BUSY  
              error = HAL_SPI_GetError(&hspi2); 
	            led_red_on();
              break;
	
	case 0x03 : state = HAL_SPI_GetState(&hspi2);          //  HAL_TIMEOUT
              error = HAL_SPI_GetError(&hspi2);
	            led_red_on(); 
              break;
}	 
	
	
}

void spi3_error_handler(uint8_t hal_status)
{
uint8_t state=0;
uint8_t error = 0;
switch(hal_status)
{

	case 0x01 : state = HAL_SPI_GetState(&hspi3);          // HAL_ERROR
              error = HAL_SPI_GetError(&hspi3);
	           
	            led_red_on();
	            break;

  case 0x02 : state = HAL_SPI_GetState(&hspi3);          // HAL_BUSY  
              error = HAL_SPI_GetError(&hspi3); 
	            led_red_on();
              break;
	
	case 0x03 : state = HAL_SPI_GetState(&hspi3);          //  HAL_TIMEOUT
              error = HAL_SPI_GetError(&hspi3);
	            led_red_on(); 
              break;
}	 	
}






















