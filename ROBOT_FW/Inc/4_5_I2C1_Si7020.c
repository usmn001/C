


#include "4_5_I2C1_Si7020.h"
#include "15_LIGHTS.h"

// External Private Variable 
extern I2C_HandleTypeDef hi2c1;
		
		
static uint8_t s_8  = 1;
static uint8_t s_16 = 2;
static uint8_t s_24 = 3;
static uint8_t s_32 = 4;

static uint8_t rb2[4];                 // 4-Byte Buffer For Receiving Data

static uint16_t  esn_v = 0;             
static uint8_t  firm_v = 0 ; 

static uint16_t obj_hum_i = 0;
static float    obj_hum_f = 0; 

static uint16_t obj_temp_i11 = 0;
static float    obj_temp_f11 = 0;

static uint16_t obj_temp_i33 = 0;
static float    obj_temp_f33 = 0;

static uint8_t  heater_v = 0;             



void si_stat(void)
{
if(HAL_I2C_IsDeviceReady(&hi2c1,dev_addr3,1,1000)!=HAL_OK)	
{
i2c1_error_handler();
}
else
	led_green_on();
}


// READ Si7020-A20 FIRMWARE REVISION 

uint8_t r_firm_v(void)
{
if(	HAL_I2C_Mem_Read(&hi2c1,dev_addr3,cmd_rev,add_size3,(uint8_t*)rb2,s_8,t1) == HAL_OK)
{
firm_v = rb2[0];
}
return firm_v;
}

 // Command For Reading 1st Electronic ID Second Byte

uint16_t r_eid1(void)
{	
if(HAL_I2C_Mem_Read(&hi2c1,dev_addr3,cmd_eid1,add_size3,(uint8_t*)rb2,s_32,t1)==HAL_OK)
{
esn_v = rb2[2];
esn_v = esn_v<<8;
esn_v = rb2[3];	
}
return esn_v;	
}

// Command For Reading 2nd Electronic ID Second Byte

uint8_t r_eid2(void)
{	
if(HAL_I2C_Mem_Read(&hi2c1,dev_addr3,cmd_eid2,add_size3,(uint8_t*)rb2,s_32,t1)==HAL_OK)	
{
esn_v = rb2[0];
}		
return esn_v;	
}

// Command To Measure Relative Humidity ,Hold Master Mode

float r_hum1(void)
{	
uint16_t buff_hum[1];	
if( HAL_I2C_Mem_Read_DMA(&hi2c1,dev_addr3,cmd_rhm1,add_size,(uint8_t*)buff_hum,s_16)==HAL_OK)	
{	
obj_hum_f =( -6 + ( (125*buff_hum[0])/65536 ) );	
}	
return obj_hum_f;	
}

// Command To Measure Temperature  , Hold Master Mode

float r_temp11(void)
{	
uint16_t buff_temp11[1];	
if( HAL_I2C_Mem_Read_DMA(&hi2c1,dev_addr3,cmd_temp1 ,add_size,(uint8_t*)buff_temp11,s_16)==HAL_OK)	
{	
obj_temp_f11 =( -46.85+( (175.72*buff_temp11[0])/65536 ) );		
}
return obj_temp_f11;	
}

// Command For Reading Temperature , From Previous RH Measurement 

float r_temp33(void)
{	
uint16_t buff_temp33[1];	
if( HAL_I2C_Mem_Read_DMA(&hi2c1,dev_addr3,cmd_temp3 ,add_size,(uint8_t*)buff_temp33,s_16)==HAL_OK)	
{	
obj_temp_f33 =( -46.85+( (175.72*buff_temp33[0])/65536 ) );	
}
return obj_temp_f33;	
}



/********* Si7020 CONTROL REGISTER WRITE FUNCTIONS ON I2C1 FOR IC1 With Address 0x80 ***********/


// Command For Reading Heater Register

uint8_t r_heat(void)
{	
if( HAL_I2C_Mem_Read(&hi2c1,dev_addr3,cmd_rheat,add_size,(uint8_t*)rb2,s_8,t1)==HAL_OK)	
{
heater_v = rb2[0];
}		
return heater_v;	
}






// Command For Resetting Device

void rst_si7020(void)
{
uint8_t s2=2;                     // Size Of Data To Be Sent & Received = 2 Byte	
uint8_t tb2[2];                  // 2-Byte Buffer For Sending Data	
tb2[0] = 0x03;  
tb2[1] = 0x0A;	
HAL_I2C_Mem_Write(&hi2c1,dev_addr3,cmd_rst,add_size,(uint8_t*)tb2,s2,t1);	
}












