

/******************************** SD RAM FUNCTIONS *************************************/

// Includes
#include "12_FMC_SDRAM.h"
#include "15_LIGHTS.h"

extern SDRAM_HandleTypeDef hsdram1;
static uint32_t mem_addr[] ={0x00};     // Pointer To Start Of Memory Address
uint32_t sd_rb[read_buf_size];          // 16 Kilo Byte Read Buffer



void mem_get_state()
{
if(HAL_SDRAM_STATE_READY ==HAL_SDRAM_GetState(&hsdram1))
{
led_green_on();
}	
}






// READ FUNCTION FOR READING SDRAM

void read_sd_mem()
{
HAL_SDRAM_Read_32b(&hsdram1,(uint32_t*)mem_addr,(uint32_t*)sd_rb,sizeof(sd_rb));	
}




// WRITE FUNCTION FOR WRITING SDRAM

void write_sd_mem(uint32_t*data)
{
HAL_SDRAM_Write_32b(&hsdram1,(uint32_t*)mem_addr,(uint32_t*)data,sizeof(data));
}














                      /******End Of Line*****/

