

// Includes
#include "3_I2C1_TMP006.h"


extern I2C_HandleTypeDef hi2c1;

void tmp1_stat(void)
{
	uint8_t hal_status=0;
hal_status=(HAL_I2C_IsDeviceReady(&hi2c1,dev_addr,2,1000));
	
if(hal_status!=0x00)
{
i2c1_error_handler();
}
	

}

void tmp2_stat(void)
{
	uint8_t hal_status=0;
hal_status=(HAL_I2C_IsDeviceReady(&hi2c1,dev_addr2,2,1000));
	
if(hal_status!=0x00)
	{
i2c1_error_handler();
}
	

}
static uint8_t s_8 = 1;
static uint8_t s_16 = 2;
static uint16_t temp1_reg_v = 0;
static uint16_t sens1_reg_v = 0;
static uint16_t temp2_reg_v = 0;
static uint16_t sens2_reg_v = 0;
	/************* TMP006 Registers Read Functions Polling Based For TMP With Address = 0x82  *****************/



// DEVICE ID READ FUNCTION

uint16_t r_dev_id1(void)
{
uint16_t dev_id = 0;	
uint16_t dev_id_v1 = 0;
uint16_t dev_id_v2 = 0;	
if( HAL_I2C_Mem_Read(&hi2c1,dev_addr,dev_id_reg,add_size,(uint8_t*)rb1,size1,timeout)==HAL_OK)	
{
dev_id_v1 = rb1[0];
dev_id_v1 = dev_id_v1<<8;	
dev_id_v2 = rb1[1];
dev_id = dev_id_v1 + dev_id_v2;	
}		
return dev_id;	
}

// MANUFACTURER ID READ FUNCTION

uint16_t r_man_id1(void)
{
uint16_t man_id = 0;	
uint16_t man_id_v1 = 0;
uint16_t man_id_v2 = 0;	
if( HAL_I2C_Mem_Read(&hi2c1,dev_addr,man_id_reg,add_size,(uint8_t*)rb1,size1,timeout)==HAL_OK)	
{
man_id_v1 = rb1[0];
man_id_v1 = man_id_v1<<8;	
man_id_v2 = rb1[1];
man_id = man_id_v1 + man_id_v2;
		
}	
return man_id;	
}


// CONFIGURATION REGISTER READ FUNCTION

uint16_t r_config1(void)
{
uint16_t config_reg_v=0;	
if( HAL_I2C_Mem_Read(&hi2c1,dev_addr,config_reg,add_size,(uint8_t*)rb1,size1,timeout)==HAL_OK)	
{
uint16_t config_reg1 = 0;
uint16_t config_reg2 = 0;	
config_reg1 = rb1[0];
config_reg1 = config_reg1<<8;
config_reg2 = rb1[1];	
config_reg_v = 	config_reg1 + config_reg2;
}	
	
return config_reg_v;	
}


// TEMPERATURE REGISTER READ FUNCTION	

uint16_t r_temp1(void)
{
uint16_t buff_temp1[1];
if( HAL_I2C_Mem_Read_DMA(&hi2c1,dev_addr,temp_reg,add_size,(uint8_t*)buff_temp1,s_16)==HAL_OK)	
{
temp1_reg_v = buff_temp1[0];
}		
return temp1_reg_v;	
}


// SENSOR REGISTER READ FUNCTION

uint16_t r_sens1(void)
{
uint16_t buff_sens1[1];
if( HAL_I2C_Mem_Read_DMA(&hi2c1,dev_addr,sens_reg,add_size,(uint8_t*)buff_sens1,s_16)==HAL_OK)	
{	
sens1_reg_v = buff_sens1[0];
}	
return sens1_reg_v;	
}





			/************* TMP006 CONFIGURATION REGISTER WRITE FUNCTIONS ON I2C1 FOR IC2 With Address 0x80*****************/

// DEVICE ID READ FUNCTION

uint16_t r_dev_id2(void)
{
uint16_t dev_id = 0;	
uint16_t dev_id_v1 = 0;
uint16_t dev_id_v2 = 0;	
if( HAL_I2C_Mem_Read(&hi2c1,dev_addr2,dev_id_reg,add_size,(uint8_t*)rb1,size1,timeout)==HAL_OK)	
{
dev_id_v1 = rb1[0];
dev_id_v1 = dev_id_v1<<8;	
dev_id_v2 = rb1[1];
dev_id = dev_id_v1 + dev_id_v2;	
}		
return dev_id;	
}

// MANUFACTURER ID READ FUNCTION

uint16_t r_man_id2(void)
{
uint16_t man_id = 0;	
uint16_t man_id_v1 = 0;
uint16_t man_id_v2 = 0;	
if( HAL_I2C_Mem_Read(&hi2c1,dev_addr2,man_id_reg,add_size,(uint8_t*)rb1,size1,timeout)==HAL_OK)	
{
man_id_v1 = rb1[0];
man_id_v1 = man_id_v1<<8;	
man_id_v2 = rb1[1];
man_id = man_id_v1 + man_id_v2;
		
}	
return man_id;	
}


// CONFIGURATION REGISTER READ FUNCTION

uint16_t r_config2(void)
{
uint16_t config_reg_v = 0;	
if( HAL_I2C_Mem_Read(&hi2c1,dev_addr2,config_reg,add_size,(uint8_t*)rb1,size1,timeout)==HAL_OK)	
{
uint16_t config_reg1 = 0;
uint16_t config_reg2 = 0;	
config_reg1 = rb1[0];
config_reg1 = config_reg1<<8;
config_reg2 = rb1[1];	
config_reg_v = 	config_reg1 + config_reg2;
}	
	
return config_reg_v;	
}


// TEMPERATURE REGISTER READ FUNCTION	

uint16_t r_temp2(void)
{
uint16_t buff_temp2[1];
if( HAL_I2C_Mem_Read_DMA(&hi2c1,dev_addr2,temp_reg,add_size,(uint8_t*)buff_temp2,s_16)==HAL_OK)	
{
temp2_reg_v = buff_temp2[0]; 
}	
return temp2_reg_v;	
}


// SENSOR REGISTER READ FUNCTION	

uint16_t r_sens2(void)
{
uint16_t buff_sens2[1];
if( HAL_I2C_Mem_Read_DMA(&hi2c1,dev_addr2,sens_reg,add_size,(uint8_t*)buff_sens2,s_16)==HAL_OK)	
{
sens2_reg_v = buff_sens2[0];
}	
return sens2_reg_v;	
}




/********* TMP006 CONFIGURATION REGISTER WRITE FUNCTIONS ON I2C1 FOR IC1 With Address 0x82 ***********/

void p_up_tmp1(void)
{
tb1[0] = 0x70;  // POWER UP TMP006
tb1[1] = 0x00;	
HAL_I2C_Mem_Write(&hi2c1,dev_addr,config_reg,add_size,(uint8_t*)tb1,size1,timeout);	
}

void p_down_tmp1(void) 
{
tb1[0] = 0x00;  // POWER DOWN TMP006
tb1[1] = 0x00;	
HAL_I2C_Mem_Write(&hi2c1,dev_addr,config_reg,add_size,(uint8_t*)tb1,size1,timeout);
}

void rst_tmp1(void)
{
tb1[0] = 0x80;  // RESET TMP006
tb1[1] = 0x00;	
HAL_I2C_Mem_Write(&hi2c1,dev_addr,config_reg,add_size,(uint8_t*)tb1,size1,timeout);	
}

void tmp1_1_samp(void) 
{
tb1[0] = 0x71;  // Power Up TMP006 , Conversion Rate = 1 Samples Per Second , EN =1 (DRDY Bit Enabled)
tb1[1] = 0x00;	 //
HAL_I2C_Mem_Write(&hi2c1,dev_addr,config_reg,add_size,(uint8_t*)tb1,size1,timeout);	
}

void tmp1_2_samp(void) 
{
tb1[0] = 0x73;  // Power Up TMP006 , Conversion Rate = 2 Samples Per Second , EN =1 (DRDY Bit Enabled)
tb1[1] = 0x00;	 //
HAL_I2C_Mem_Write(&hi2c1,dev_addr,config_reg,add_size,(uint8_t*)tb1,size1,timeout);	
}

void tmp1_4_samp(void) 
{
tb1[0] = 0x75;  // Power Up TMP006 , Conversion Rate = 4 Samples Per Second , EN =1 (DRDY Bit Enabled)
tb1[1] = 0x00;	 //
HAL_I2C_Mem_Write(&hi2c1,dev_addr,config_reg,add_size,(uint8_t*)tb1,size1,timeout);	
}

void tmp1_8_samp(void) 
{
tb1[0] = 0x77;  // Power Up TMP006 , Conversion Rate = 8 Samples Per Second , EN =1 (DRDY Bit Enabled)
tb1[1] = 0x00;	 //
HAL_I2C_Mem_Write(&hi2c1,dev_addr,config_reg,add_size,(uint8_t*)tb1,size1,timeout);	
}

void tmp1_16_samp(void) 
{
tb1[0] = 0x79;  // Power Up TMP006 , Conversion Rate = 16 Samples Per Second , EN =1 (DRDY Bit Enabled)
tb1[1] = 0x00;	 //
HAL_I2C_Mem_Write(&hi2c1,dev_addr,config_reg,add_size,(uint8_t*)tb1,size1,timeout);	
}





/********* TMP006 CONFIGURATION REGISTER WRITE FUNCTIONS ON I2C1 FOR IC1 With Address 0x80 ***********/


void p_up_tmp2(void)
{
tb1[0] = 0x70;  // POWER UP TMP006
tb1[1] = 0x00;	
HAL_I2C_Mem_Write(&hi2c1,dev_addr2,config_reg,add_size,(uint8_t*)tb1,size1,timeout);	
}

void p_down_tmp2(void) 
{
tb1[0] = 0x00;  // POWER DOWN TMP006
tb1[1] = 0x00;	
HAL_I2C_Mem_Write(&hi2c1,dev_addr2,config_reg,add_size,(uint8_t*)tb1,size1,timeout);
}

void rst_tmp2(void)
{
tb1[0] = 0x80;  // RESET TMP006
tb1[1] = 0x00;	
HAL_I2C_Mem_Write(&hi2c1,dev_addr,config_reg,add_size,(uint8_t*)tb1,size1,timeout);	
}

void tmp2_1_samp(void) 
{
tb1[0] = 0x71;  // Power Up TMP006 , Conversion Rate = 1 Samples Per Second , EN =1 (DRDY Bit Enabled)
tb1[1] = 0x00;	 //
HAL_I2C_Mem_Write(&hi2c1,dev_addr2,config_reg,add_size,(uint8_t*)tb1,size1,timeout);	
}

void tmp2_2_samp(void) 
{
tb1[0] = 0x73;  // Power Up TMP006 , Conversion Rate = 2 Samples Per Second , EN =1 (DRDY Bit Enabled)
tb1[1] = 0x00;	 //
HAL_I2C_Mem_Write(&hi2c1,dev_addr2,config_reg,add_size,(uint8_t*)tb1,size1,timeout);	
}

void tmp2_4_samp(void) 
{
tb1[0] = 0x75;  // Power Up TMP006 , Conversion Rate = 4 Samples Per Second , EN =1 (DRDY Bit Enabled)
tb1[1] = 0x00;	 //
HAL_I2C_Mem_Write(&hi2c1,dev_addr,config_reg,add_size,(uint8_t*)tb1,size1,timeout);	
}

void tmp2_8_samp(void) 
{
tb1[0] = 0x77;  // Power Up TMP006 , Conversion Rate = 8 Samples Per Second , EN =1 (DRDY Bit Enabled)
tb1[1] = 0x00;	 //
HAL_I2C_Mem_Write(&hi2c1,dev_addr2,config_reg,add_size,(uint8_t*)tb1,size1,timeout);	
}

void tmp2_16_samp(void) 
{
tb1[0] = 0x79;  // Power Up TMP006 , Conversion Rate = 16 Samples Per Second , EN =1 (DRDY Bit Enabled)
tb1[1] = 0x00;	 //
HAL_I2C_Mem_Write(&hi2c1,dev_addr2,config_reg,add_size,(uint8_t*)tb1,size1,timeout);	
}


