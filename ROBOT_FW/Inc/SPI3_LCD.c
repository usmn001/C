

                     /************LCD DRIVER FUNCTIONS*****************/


// Includes
#include "SPI3_LCD.h"
#include "SPI_ERROR_HANDLER.h"
#include "stm32f4xx_hal.h"
#include "UART1.h"
// Private variable
extern SPI_HandleTypeDef hspi3;

/* 8,16,32,64 Bit Buffers used for transmission */

static uint8_t  rb_8[4];             // A 8 Byte RX Buffer Of 1 Memory Locations
static uint16_t tb_16[1];            // A 16 Byte TX Buffer Of 1 Memory Locations
static uint16_t rb_16[2];            // A 16 Byte RX Buffer Of 1 Memory Locations
static uint32_t tb_32[1];            // A 32 Byte TX Buffer Of 1 Memory Locations
static uint32_t rb_32[3];            // A 32 Byte RX Buffer Of 1 Memory Locations
static uint64_t tb_64[1];            // A 64 Byte TX Buffer Of 1 Memory Locations
static uint64_t rb_64[1];            // A 64 Byte RX Buffer Of 1 Memory Locations



// Buffering Varaibles
static uint8_t  rd1 = 0;            // 8-Bit Variable For Storing & Returning Data To The Caller Function
static uint16_t rd2 = 0;            // 16-Bit Variable For Storing & Returning Data To The Caller Function
static uint32_t rd3 = 0;            // 32-Bit Variable For Storing & Returning Data To The Caller Function
static uint64_t rd4 = 0;            // 64-Bit Variable For Storing & Returning Data To The Caller Function

static uint8_t hal_status=0;


                        /***********LCD TOUCH CONTROLLER IO FUNCTIONS**************/
// LCD Touch On

void Lcd_Ton()
{
HAL_GPIO_WritePin(GPIOE,SPI_3_CS_TOUCH_Pin,GPIO_PIN_RESET);	
}	

// LCD Touch Off

void Lcd_Tof()
{
HAL_GPIO_WritePin(GPIOE,SPI_3_CS_TOUCH_Pin,GPIO_PIN_SET);	
}	

void DC()                                   // DC SELECTION METHOD
{ 

	/* GPIO Ports Clock Enable */
 __GPIOC_CLK_ENABLE();	
GPIO_InitTypeDef GPIO_InitStruct;

/*Configure GPIO pin : SPI_3_MOSI_LCD_Pin */
GPIO_InitStruct.Pin =SPI_3_MOSI_LCD_Pin | SPI_3_SCK_LCD_Pin ;
GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
GPIO_InitStruct.Pull = GPIO_PULLDOWN;
GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

/* SPI3 init function */
static void MX_SPI3_Init(void)
{

  hspi3.Instance = SPI3;
  hspi3.Init.Mode = SPI_MODE_MASTER;
  hspi3.Init.Direction = SPI_DIRECTION_2LINES;
  hspi3.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi3.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi3.Init.NSS = SPI_NSS_SOFT;
  hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi3.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi3.Init.TIMode = SPI_TIMODE_DISABLED;
  hspi3.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLED;
  hspi3.Init.CRCPolynomial = 10;
  HAL_SPI_Init(&hspi3);

}


                          /***********LCD CONTROLLER IO FUNCTIONS**************/


void Lcd_on(void)                 
{
HAL_GPIO_WritePin(GPIOE,SPI_3_CS_LCD_L_Pin,GPIO_PIN_RESET);		      // LCD CSX LOW
}


void Lcd_of(void)                 
{
HAL_GPIO_WritePin(GPIOE,SPI_3_CS_LCD_L_Pin,GPIO_PIN_SET);		        // LCD CSX HIGH 
}


void Lcd_Set()
{
HAL_GPIO_WritePin(GPIOE,LCD_RST_LCD_Pin,GPIO_PIN_SET);		          // RESET LCD
}

void Lcd_Rst()
{
HAL_GPIO_WritePin(GPIOE,LCD_RST_LCD_Pin,GPIO_PIN_RESET);		        // SET LCD
}


void Lcd_Bl_On()
{
HAL_GPIO_WritePin(GPIOD,LCD_BL_LCD_Pin,GPIO_PIN_SET);		            // LCD BACKLIGHT ON
}

void Lcd_Bl_Of()
{
HAL_GPIO_WritePin(GPIOD,LCD_BL_LCD_Pin,GPIO_PIN_RESET);		          // LCD BACKLIGHT OF 
}

void Lcd_S()                                                        // SERIAL DATA TRANSMISSION STARTS
{
HAL_GPIO_WritePin(GPIOE,SPI_3_CS_LCD_L_Pin,GPIO_PIN_SET);	
HAL_GPIO_WritePin(GPIOE,SPI_3_CS_LCD_L_Pin,GPIO_PIN_RESET);	
}

void Lcd_E()                                                        // SERIAL DATA TRANSMISSION ENDS 
{
HAL_GPIO_WritePin(GPIOE,SPI_3_CS_LCD_L_Pin,GPIO_PIN_SET);		
}


 // SET LCD DISPLAY ON

void Lcd_disp_on(void)     
{
uint8_t cmd[] ={disp_on};	
Lcd_S();                                                       // SERIAL DATA TRANSMISSION STARTS
hal_status = HAL_SPI_Transmit_DMA(&hspi3,(uint8_t*)cmd,s_8);	
Lcd_E();                                                       // SERIAL DATA TRANSMISSION ENDS 
if(hal_status!=HAL_OK)
{
spi3_error_handler(hal_status);
}		
}



	
	
 

	
	// SET LCD DISPLAY OFF

void Lcd_disp_of(void)     
{
Lcd_S();                                                       // SERIAL DATA TRANSMISSION STARTS
uint8_t cmd[] ={disp_on};                                                    
hal_status = HAL_SPI_Transmit_DMA(&hspi3,(uint8_t*)cmd,s_8);	
Lcd_E();                                                       // SERIAL DATA TRANSMISSION ENDS
if(hal_status!=HAL_OK)
{
spi3_error_handler(hal_status);
}		
}

void Lcd_mem_acc_con_w(uint8_t data)                           /* WRITE MEMORY ACCESS CONTROL */
{
uint8_t cmd[] ={mem_acc_con};	
Lcd_S();                                                       /* SERIAL DATA TRANSMISSION STARTS */
hal_status = HAL_SPI_Transmit_DMA(&hspi3,(uint8_t*)cmd,s_8);
uint8_t d1[] = {data};
Lcd_S();                                                       /* SERIAL DATA TRANSMISSION STARTS */
hal_status = HAL_SPI_Transmit_DMA(&hspi3,(uint8_t*)d1,s_8);
Lcd_E();                                                       /* SERIAL DATA TRANSMISSION ENDS */
if(hal_status!=HAL_OK)
{
spi3_error_handler(hal_status);
}		
}


uint8_t Lcd_mem_acc_con_r(void)
{	
uint8_t rb_8[1] = {0};                                         // A 8 Byte RX Buffer Of 5 Memory Locations 
uint8_t cmd[] = {mem_acc_con};
Lcd_S();                                                       // SERIAL DATA TRANSMISSION STARTS 	
hal_status = HAL_SPI_Transmit_DMA(&hspi3,(uint8_t*)cmd,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi3,(uint8_t*)rb_8,s_8);
Lcd_E();                                                       // SERIAL DATA TRANSMISSION ENDS 
rd1 = rb_8[0];
return rd1;	
}






 // LCD NORMAL MODE ON

void Lcd_norm_on(void)     
{
uint8_t cmd[] ={disp_norm_on};	
Lcd_S();                                                       // SERIAL DATA TRANSMISSION STARTS
hal_status = HAL_SPI_Transmit_DMA(&hspi3,(uint8_t*)cmd,s_8);
Lcd_E();                                                       // SERIAL DATA TRANSMISSION ENDS
if(hal_status!=HAL_OK)
{
spi3_error_handler(hal_status);
}		
}


uint16_t  d_gen(uint16_t data)
{
data = data+0x04;
return data;	
}


                       /********************LCD READ COMMANDS********************/



// READ LCD MANUFACTURER ID

uint8_t Lcd_man_id_r(void)
{
uint8_t rb_8[1] = {0};                                   /* A 8 Byte RX Buffer Of 5 Memory Locations */
uint8_t cmd[] = {man_id};
Lcd_S();                                                       /* SERIAL DATA TRANSMISSION STARTS */
hal_status = HAL_SPI_Transmit_DMA(&hspi3,(uint8_t*)cmd,s_8);
hal_status = HAL_SPI_Receive_DMA(&hspi3,(uint8_t*)rb_8,s_8);
Lcd_E();                                                       /* SERIAL DATA TRANSMISSION ENDS */
rd1 = rb_8[0];
return rd1;	
}




// READ MEMORY ACCESS CONTROL





uint8_t Lcd_dri_ver_r(void)                                   /* READ LCD MODULE DRIVER VERSION */
{
uint8_t rb_8[5] = {0,0,0,0,0}; 
uint8_t cmd[] ={dri_ver};	
Lcd_S();                                                       /* SERIAL DATA TRANSMISSION STARTS */
hal_status = HAL_SPI_Transmit_DMA(&hspi3,(uint8_t*)cmd,s_16);	
hal_status = HAL_SPI_Receive_DMA(&hspi3,(uint8_t*)rb_8,s_40);
Lcd_E();                                                       /* SERIAL DATA TRANSMISSION ENDS */
if(hal_status!=HAL_OK)
{
spi3_error_handler(hal_status);
}		
else
rd1 = rb_8[4];
return rd1;	
}


// READ LCD MODULE DRIVER ID

uint8_t Lcd_dri_id_r(void)
{
uint8_t rb_8[5] = {0,0,0,0,0}; 
uint8_t cmd[] ={dri_id};	
Lcd_S();                                                       /* SERIAL DATA TRANSMISSION STARTS */
hal_status = HAL_SPI_Transmit_DMA(&hspi3,(uint8_t*)cmd,s_16);	
hal_status = HAL_SPI_Receive_DMA(&hspi3,(uint8_t*)rb_8,s_40);
Lcd_E();                                                       /* SERIAL DATA TRANSMISSION ENDS */
if(hal_status!=HAL_OK)
{
spi3_error_handler(hal_status);
}		
else
rd1 = rb_8[4];
return rd1;	
}


 

uint8_t Lcd_disp_stat_r(void)                                /* READ LCD DISPLAY STATUS */
{
uint32_t param = 0;	
uint8_t cmd[] ={disp_stat};	
Lcd_S();                                                       /* SERIAL DATA TRANSMISSION STARTS */
hal_status = HAL_SPI_Transmit_DMA(&hspi3,(uint8_t*)cmd,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi3,(uint8_t*)rb_8,s_32);
Lcd_E();                                                       /* SERIAL DATA TRANSMISSION ENDS */
if(hal_status!=HAL_OK)
{
spi3_error_handler(hal_status);
}		
else
param = rb_8[0];
param = param<<8;
param = rb_8[1];
return param;



}

 

uint8_t Lcd_mem_r()                                          /* LCD MEMORY READ */ 
{

uint8_t cmd[] ={mem_read};
Lcd_S();                                                       /* SERIAL DATA TRANSMISSION STARTS */
hal_status = HAL_SPI_Transmit_DMA(&hspi3,(uint8_t*)cmd,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi3,(uint8_t*)rb_32,s_64);
Lcd_E();                                                       /* SERIAL DATA TRANSMISSION ENDS */
if(hal_status!=HAL_OK)
{
spi3_error_handler(hal_status);
}		
else
rd4 = rb_32[0];
return rd4;
}




uint8_t Lcd_disp_pow_mod_r(void)                              /* READ LCD DISPLAY POWER MODE */
{
uint8_t cmd[] ={disp_pow_mod};	
Lcd_S();                                                       /* SERIAL DATA TRANSMISSION STARTS */
hal_status = HAL_SPI_Transmit_DMA(&hspi3,(uint8_t*)cmd,s_16);
hal_status = HAL_SPI_Receive_DMA(&hspi3,(uint8_t*)rb_8,s_8);
Lcd_E();                                                       /* SERIAL DATA TRANSMISSION ENDS */
if(hal_status!=HAL_OK)
{
spi3_error_handler(hal_status);
}
rd2 = rb_8[0];
return rd2;
}




 
 
uint8_t Lcd_column_addr_r()                                   /* LCD COLUMN ADDRESS REGISTER READ */ 
{

uint8_t cmd[] ={column_addr};	
Lcd_S();                                                       /* SERIAL DATA TRANSMISSION STARTS */
hal_status = HAL_SPI_Transmit_DMA(&hspi3,(uint8_t*)cmd,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi3,(uint8_t*)rb_32,s_32);
Lcd_E();                                                       /* SERIAL DATA TRANSMISSION ENDS */
if(hal_status!=HAL_OK)
{
spi3_error_handler(hal_status);
}		
else
rd4 = rb_32[0];
return rd4;
}



uint8_t Lcd_page_addr_r()                                     /* LCD PAGE ADDRESS REGISTER READ */
{
uint8_t cmd[] ={page_addr};		
Lcd_S();                                                       /* SERIAL DATA TRANSMISSION STARTS */
hal_status = HAL_SPI_Transmit_DMA(&hspi3,(uint8_t*)cmd,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi3,(uint8_t*)rb_32,s_32);
Lcd_E();                                                       /* SERIAL DATA TRANSMISSION ENDS */
if(hal_status!=HAL_OK)
{
spi3_error_handler(hal_status);
}		
else
rd4 = rb_32[0];
return rd4;
}



uint8_t Lcd_rddsdr_r()                                         /* LCD SELF DIAGNOSTICS REGISTER READ */
{
uint8_t cmd[] ={rddsdr};		
Lcd_S();                                                       /* SERIAL DATA TRANSMISSION STARTS */
hal_status = HAL_SPI_Transmit_DMA(&hspi3,(uint8_t*)cmd,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi3,(uint8_t*)rb_8,s_8);
Lcd_E();                                                       /* SERIAL DATA TRANSMISSION ENDS */
if(hal_status!=HAL_OK)
{
spi3_error_handler(hal_status);
}		
else
rd1 = rb_8[0];
return rd1;
}



void Lcd_normal_mode_on()                                      /* NORMA DISPLAY MODE ON */
{
uint8_t cmd[] ={normal_mode_on};	
Lcd_S();                                                       /* SERIAL DATA TRANSMISSION STARTS */
hal_status = HAL_SPI_Transmit_DMA(&hspi3,(uint8_t*)cmd,s_8);	
Lcd_E();                                                       /* SERIAL DATA TRANSMISSION ENDS */
if(hal_status!=HAL_OK)
{
spi3_error_handler(hal_status);
}		
}



                            /**************** LCD WRITE COMMANDS****************/










void Lcd_column_addr_w(uint8_t sc15_8,uint8_t sc7_0,uint8_t ec15_8,uint8_t ec7_0)  /* LCD COLUMN ADDRESS REGISTER WRITE */ 
{

uint8_t cmd[] ={column_addr,sc15_8,sc7_0,ec15_8,ec7_0};	
Lcd_S();                                                       /* SERIAL DATA TRANSMISSION STARTS */
hal_status = HAL_SPI_Transmit_DMA(&hspi3,(uint8_t*)cmd,s_40);	
Lcd_E();                                                       /* SERIAL DATA TRANSMISSION ENDS */
if(hal_status!=HAL_OK)
{
spi3_error_handler(hal_status);
}		
}


 

void Lcd_page_addr_w(uint8_t sp15_8,uint8_t sp7_0,uint8_t ep15_8,uint8_t ep7_0) /* LCD PAGE ADDRESS REGISTER WRITE */
{

uint8_t cmd[] ={page_addr,sp15_8,sp7_0,ep15_8,ep7_0};	
Lcd_S();                                                       /* SERIAL DATA TRANSMISSION STARTS */
hal_status = HAL_SPI_Transmit_DMA(&hspi3,(uint8_t*)cmd,s_40);	
Lcd_E();                                                       /* SERIAL DATA TRANSMISSION ENDS */
if(hal_status!=HAL_OK)
{
spi3_error_handler(hal_status);
}		
}




void Lcd_mem_w(uint32_t data)                                  /* LCD MEMORY WRITE */  
{ 
uint8_t cmd[] ={mem_write,data};	
Lcd_S();                                                       /* SERIAL DATA TRANSMISSION STARTS */
hal_status = HAL_SPI_Transmit_DMA(&hspi3,(uint8_t*)cmd,s_32);
Lcd_E();                                                       /* SERIAL DATA TRANSMISSION ENDS */
if(hal_status!=HAL_OK)
{
spi3_error_handler(hal_status);
}		
}


