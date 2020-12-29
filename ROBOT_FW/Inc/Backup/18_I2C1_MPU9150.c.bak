

                  /******************* MPU9150 FUNCTION DEFINITIONS*******************/


// Includes
#include "18_I2C1_MPU9150.h"
#include "15_LIGHTS.h"

// External Private Variable 
extern I2C_HandleTypeDef hi2c1;

/* 8,16,32,64 Bit Buffers used for transmission */

static uint8_t  tb_8[1];             // A 8 Byte TX Buffer Of 1 Memory Locations
static uint8_t  rb_8[1];             // A 8 Byte RX Buffer Of 1 Memory Locations
static uint16_t tb_16[1];            // A 16 Byte TX Buffer Of 1 Memory Locations
static uint16_t rb_16[1];            // A 16 Byte RX Buffer Of 1 Memory Locations
static uint32_t tb_32[1];            // A 32 Byte TX Buffer Of 1 Memory Locations
static uint32_t rb_32[1];            // A 32 Byte RX Buffer Of 1 Memory Locations
static uint64_t tb_64[1];            // A 64 Byte TX Buffer Of 1 Memory Locations
static uint64_t rb_64[1];            // A 64 Byte RX Buffer Of 1 Memory Locations

// Buffering Varaibles
static uint8_t  rd1 = 0;             // 8-Bit Variable For Storing & Returning Data To The Caller Function
static uint16_t rd2 = 0;             // 16-Bit Variable For Storing & Returning Data To The Caller Function
static uint32_t rd3 = 0;             // 32-Bit Variable For Storing & Returning Data To The Caller Function
static uint64_t rd4 = 0;             // 64-Bit Variable For Storing & Returning Data To The Caller Function






void mpu_stat(void)
{
if(HAL_I2C_IsDeviceReady(&hi2c1,MPU9150_ADDRESS_AD0_HIGH ,1,1000)==HAL_OK)
{
led_green_on();	
}
else 
	led_red_on();
}

                /***************MPU9150: POWER , I/O MANAGEMENT FUNCTIONS ****************/


/* ACCELROMETER : SLEEP MODE OF,
                  TEMPERATURE SENSOR DISABLED , INTERNAL CLOCK 8Mhz ENABLED */

void slp_mod_of(void)
{
uint8_t mem_add = MPU9150_PWR_MGMT_1;	
tb_8[0] = 0x08;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}


/* ACCELROMETER : SLEEP MODE ON,
                  TEMPERATURE SENSOR DISABLED, INTERNAL CLOCK 8Mhz ENABLED */ 

void slp_mod_on(void)
{
uint8_t mem_add = MPU9150_PWR_MGMT_1;	
tb_8[0] = 0x48;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}


/* ACCELROMETER : RESET */

void rst_acc(void)
{
uint8_t mem_add = MPU9150_PWR_MGMT_1;	
tb_8[0] = 0x80;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}



/* ACCELROMETER : CYCLE BETWEEN WAKE UP & SLEEP MODES ENABLED,
                  SLEEP MODE OF, TEMPERATURE SENSOR DISABLED,INTERNAL CLOCK 8Mhz ENABLED */ 

void cyc_wak_slp_on(void)
{
uint8_t mem_add = MPU9150_PWR_MGMT_1;	
tb_8[0] = 0x28;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}


 /* ACCELROMETER : CYCLE BETWEEN WAKE UP & SLEEP MODES DISABLED,
                   TEMPERATURE SENSOR DISABLED,INTERNAL CLOCK 8Mhz ENABLED */

void cyc_wak_slp_of(void)
{
uint8_t mem_add = MPU9150_PWR_MGMT_1;	
tb_8[0] = 0x00;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}



 /* ACCELROMETER : WAKE UP FREQUENCY = 10 Hz */
                   

void wake_up_freq(void)
{
uint8_t mem_add = MPU9150_PWR_MGMT_2;	
tb_8[0] = 0xC0;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}

                         /***********GYROSCOPE & ACCELROMETER READ FUNCTIONS************/


// READ SMPRT_DIV REGISTER OF MPU9150

uint8_t r_smprt_div (void)
{
uint8_t mem_add = MPU9150_SMPLRT_DIV ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}

// READ CONFIG REGISTER OF MPU9150

uint8_t r_config (void)
{
uint8_t mem_add =  MPU9150_CONFIG ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}

// READ GYRO_CONFIG REGISTER OF MPU9150

uint8_t r_gyro_config(void)
{
uint8_t mem_add = MPU9150_GYRO_CONFIG   ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ ACCEL_CONFIG REGISTER OF MPU9150

uint8_t r_accel_config(void)
{
uint8_t mem_add =  MPU9150_ACCEL_CONFIG   ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ FF_THR REGISTER OF MPU9150

uint8_t r_MPU9150_FF_THR (void)
{
uint8_t mem_add = MPU9150_FF_THR ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ FF_DUR REGISTER OF MPU9150

uint8_t r_MPU9150_FF_DUR(void)
{
uint8_t mem_add =  MPU9150_FF_DUR ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ MOT_THR REGISTER OF MPU9150

uint8_t r_MPU9150_MOT_THR(void)
{
uint8_t mem_add = MPU9150_MOT_THR;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ MOT_DUR REGISTER OF MPU9150

uint8_t r_MPU9150_MOT_DUR(void)
{
uint8_t mem_add =  MPU9150_MOT_DUR   ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}



// READ ZRMOT_THR REGISTER OF MPU9150

uint8_t r_MPU9150_ZRMOT_THR (void)
{
uint8_t mem_add = MPU9150_ZRMOT_THR  ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ ZRMOT_DUR REGISTER OF MPU9150

uint8_t r_MPU9150_ZRMOT_DUR(void)
{
uint8_t mem_add = MPU9150_ZRMOT_DUR  ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ FIFO_EN REGISTER OF MPU9150

uint8_t r_MPU9150_FIFO_EN(void)
{
uint8_t mem_add = MPU9150_FIFO_EN;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ MST_CTRL REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_MST_CTRL(void)
{
uint8_t mem_add =  MPU9150_I2C_MST_CTRL;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}




// READ SLV0_ADDR REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_SLV0_ADDR (void)
{
uint8_t mem_add = MPU9150_I2C_SLV0_ADDR ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ SLV0_REG REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_SLV0_REG (void)
{
uint8_t mem_add =  MPU9150_I2C_SLV0_REG  ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ SLV0_CTRL  REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_SLV0_CTRL(void)
{
uint8_t mem_add = MPU9150_I2C_SLV0_CTRL;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ SLV1_ADDR REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_SLV1_ADDR(void)
{
uint8_t mem_add =  MPU9150_I2C_SLV1_ADDR  ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}



// READ SLV1_REG REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_SLV1_REG (void)
{
uint8_t mem_add = MPU9150_I2C_SLV1_REG ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ SLV1_CTRL REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_SLV1_CTRL(void)
{
uint8_t mem_add = MPU9150_I2C_SLV1_CTRL  ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ SLV2_ADDR REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_SLV2_ADDR(void)
{
uint8_t mem_add = MPU9150_I2C_SLV2_ADDR;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ SLV2_REG REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_SLV2_REG(void)
{
uint8_t mem_add = MPU9150_I2C_SLV2_REG ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}



// READ SLV1_REG REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_SLV2_CTRL  (void)
{
uint8_t mem_add =  MPU9150_I2C_SLV2_CTRL  ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ SLV3_ADDR REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_SLV3_ADDR(void)
{
uint8_t mem_add = MPU9150_I2C_SLV3_ADDR  ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ SLV3_REG REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_SLV3_REG(void)
{
uint8_t mem_add = MPU9150_I2C_SLV3_REG;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ SLV3_CTRL REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_SLV3_CTRL(void)
{
uint8_t mem_add = MPU9150_I2C_SLV3_CTRL ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}




// READ SLV4_ADDR REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_SLV4_ADDR (void)
{
uint8_t mem_add = MPU9150_I2C_SLV4_ADDR ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ SLV4_REG REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_SLV4_REG(void)
{
uint8_t mem_add =  MPU9150_I2C_SLV4_REG ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ SLV4_DO REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_SLV4_DO(void)
{
uint8_t mem_add = MPU9150_I2C_SLV4_DO;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ SLV4_CTRL REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_SLV4_CTRL(void)
{
uint8_t mem_add =  MPU9150_I2C_SLV4_CTRL;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}



// READ SLV4_DI REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_SLV4_DI (void)
{
uint8_t mem_add = MPU9150_I2C_SLV4_DI ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ MST_STATUS REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_MST_STATUS(void)
{
uint8_t mem_add = MPU9150_I2C_MST_STATUS  ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ INT_PIN_CFG REGISTER OF MPU9150

uint8_t r_MPU9150_INT_PIN_CFG(void)
{
uint8_t mem_add = MPU9150_INT_PIN_CFG;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ INT_ENABLE REGISTER OF MPU9150

uint8_t r_MPU9150_INT_ENABLE(void)
{
uint8_t mem_add =  MPU9150_INT_ENABLE;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}




// READ INT_STATUS REGISTER OF MPU9150

uint8_t r_MPU9150_INT_STATUS (void)
{
uint8_t mem_add = MPU9150_INT_STATUS ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ ACCEL_XOUT_H REGISTER OF MPU9150

uint16_t r_MPU9150_ACCEL_XOUT_H (void)
{
uint8_t mem_add =  MPU9150_ACCEL_XOUT_H ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_16,s_16,timeout)==HAL_OK)
{
rd2 = rb_16[0];
}	
return rd2;
}


// READ ACCEL_XOUT_L REGISTER OF MPU9150

uint8_t r_MPU9150_ACCEL_XOUT_L(void)
{
uint8_t mem_add = MPU9150_ACCEL_XOUT_L;	
if(HAL_I2C_Mem_Read_DMA(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ ACCEL_YOUT_H REGISTER OF MPU9150

uint16_t r_MPU9150_ACCEL_YOUT_H(void)
{
uint8_t mem_add =  MPU9150_ACCEL_YOUT_H  ;	
if(HAL_I2C_Mem_Read_DMA(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_16,s_16)==HAL_OK)
{
rd2 = rb_16[0];
}	
return rd2;
}



// READ ACCEL_YOUT_L REGISTER OF MPU9150

uint8_t r_MPU9150_ACCEL_YOUT_L (void)
{
uint8_t mem_add = MPU9150_ACCEL_YOUT_L ;	
if(HAL_I2C_Mem_Read_DMA(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ ACCEL_ZOUT_H REGISTER OF MPU9150

uint16_t r_MPU9150_ACCEL_ZOUT_H(void)
{
uint8_t mem_add = MPU9150_ACCEL_ZOUT_H;	
if(HAL_I2C_Mem_Read_DMA(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_16,s_16)==HAL_OK)
{
rd2 = rb_16[0];
}	
return rd2;
}


// READ ACCEL_ZOUT_L REGISTER OF MPU9150

uint8_t r_MPU9150_ACCEL_ZOUT_L(void)
{
uint8_t mem_add = MPU9150_ACCEL_ZOUT_L;	
if(HAL_I2C_Mem_Read_DMA(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ GYRO_XOUT_H REGISTER OF MPU9150

uint16_t r_MPU9150_GYRO_XOUT_H(void)
{
uint8_t mem_add = MPU9150_GYRO_XOUT_H  ;	
if(HAL_I2C_Mem_Read_DMA(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_16,s_16)==HAL_OK)
{
rd2 = rb_16[0];
}	
return rd2;
}



// READ GYRO_XOUT_L REGISTER OF MPU9150

uint8_t r_MPU9150_GYRO_XOUT_L  (void)
{
uint8_t mem_add =  MPU9150_GYRO_XOUT_L  ;	
if(HAL_I2C_Mem_Read_DMA(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ GYRO_YOUT_H REGISTER OF MPU9150

uint16_t r_MPU9150_GYRO_YOUT_H(void)
{
uint8_t mem_add = MPU9150_GYRO_YOUT_H;	
if(HAL_I2C_Mem_Read_DMA(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_16,s_16)==HAL_OK)
{
rd2 = rb_16[0];
}	
return rd2;
}


// READ GYRO_YOUT_L REGISTER OF MPU9150

uint8_t r_MPU9150_GYRO_YOUT_L(void)
{
uint8_t mem_add = MPU9150_GYRO_YOUT_L;	
if(HAL_I2C_Mem_Read_DMA(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ GYRO_ZOUT_H REGISTER OF MPU9150

uint16_t r_MPU9150_GYRO_ZOUT_H(void)
{
uint8_t mem_add = MPU9150_GYRO_ZOUT_H ;	
if(HAL_I2C_Mem_Read_DMA(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_16,s_16)==HAL_OK)
{
rd2 = rb_16[0];
}	
return rd2;
}


// READ GYRO_ZOUT_L REGISTER OF MPU9150

uint8_t r_MPU9150_GYRO_ZOUT_L(void)
{
uint8_t mem_add = MPU9150_GYRO_ZOUT_L ;	
if(HAL_I2C_Mem_Read_DMA(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}

// READ MOT_DETECT_STATUS REGISTER OF MPU9150

uint8_t r_MPU9150_MOT_DETECT_STATUS(void)
{
uint8_t mem_add = MPU9150_MOT_DETECT_STATUS;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}



// READ DELAY_CTRL REGISTER OF MPU9150

uint8_t r_MPU9150_I2C_MST_DELAY_CTRL(void)
{
uint8_t mem_add = MPU9150_I2C_MST_DELAY_CTRL;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ PATH_RESET REGISTER OF MPU9150

uint8_t r_MPU9150_SIGNAL_PATH_RESET(void)
{
uint8_t mem_add = MPU9150_SIGNAL_PATH_RESET;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ DETECT_CTRL REGISTER OF MPU9150

uint8_t r_MPU9150_MOT_DETECT_CTRL(void)
{
uint8_t mem_add = MPU9150_MOT_DETECT_CTRL  ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}



// READ USER_CTRL REGISTER OF MPU9150

uint8_t r_MPU9150_USER_CTRL  (void)
{
uint8_t mem_add =  MPU9150_USER_CTRL  ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ PWR_MGMT_1 REGISTER OF MPU9150

uint8_t r_pwr_mgmt_1(void)
{
uint8_t mem_add = MPU9150_PWR_MGMT_1  ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ PWR_MGMT_2 REGISTER OF MPU9150

uint8_t r_pwr_mgmt_2(void)
{
uint8_t mem_add = MPU9150_PWR_MGMT_2  ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ FIFO_COUNTH REGISTER OF MPU9150

uint8_t r_MPU9150_FIFO_COUNTH(void)
{
uint8_t mem_add = MPU9150_FIFO_COUNTH;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ FIFO_COUNTL REGISTER OF MPU9150

uint8_t r_MPU9150_FIFO_COUNTL (void)
{
uint8_t mem_add = MPU9150_FIFO_COUNTL ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ FIFO_R_W  REGISTER OF MPU9150

uint8_t r_MPU9150_FIFO_R_W(void)
{
uint8_t mem_add = MPU9150_FIFO_R_W ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}


// READ WHO AM I REGISTER OF MPU9150

uint8_t r_who_am_i(void)
{
uint8_t mem_add = MPU9150_WHO_AM_I  ;	
if(HAL_I2C_Mem_Read(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)rb_8,s_8,timeout)==HAL_OK)
{
rd1 = rb_8[0];
}	
return rd1;
}



                             /***********GYROSCOPE & ACCELROMETER WRITE FUNCTIONS************/


// WRITE SMPRT_DIV REGISTER OF MPU9150

void w_smprt_div(uint8_t data)
{
uint8_t mem_add = MPU9150_SMPLRT_DIV   ;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}



// WRITE CONFIG REGISTER OF MPU9150

void w_config(uint8_t data)
{
uint8_t mem_add = MPU9150_CONFIG   ;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}


// WRITE GYRO_CONFIG REGISTER OF MPU9150

void w_gyro_config(uint8_t data)
{
uint8_t mem_add = MPU9150_GYRO_CONFIG   ;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}

                                    
// WRITE ACCEL_CONFIG REGISTER OF MPU9150

void w_MPU9150_ACCEL_CONFIG(uint8_t data)
{
uint8_t mem_add = MPU9150_ACCEL_CONFIG   ;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}



// WRITE FF_THR REGISTER OF MPU9150

void w_MPU9150_FF_THR(uint8_t data)
{
uint8_t mem_add = MPU9150_FF_THR;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}


// WRITE FF_DUR REGISTER OF MPU9150

void w_MPU9150_FF_DUR(uint8_t data)
{
uint8_t mem_add = MPU9150_FF_DUR;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}


// WRITE MOT_THR REGISTER OF MPU9150

void w_MPU9150_MOT_THR(uint8_t data)
{
uint8_t mem_add = MPU9150_MOT_THR;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}



// WRITE MOT_DUR REGISTER OF MPU9150

void w_MPU9150_MOT_DUR(uint8_t data)
{
uint8_t mem_add = MPU9150_MOT_DUR   ;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}


// WRITE ZRMOT_THR REGISTER OF MPU9150

void w_MPU9150_ZRMOT_THR(uint8_t data)
{
uint8_t mem_add = MPU9150_ZRMOT_THR   ;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}

                                    
// WRITE ZRMOT_DUR REGISTER OF MPU9150

void w_MPU9150_ZRMOT_DUR(uint8_t data)
{
uint8_t mem_add = MPU9150_ZRMOT_DUR;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}



// WRITE FIFO_EN REGISTER OF MPU9150

void w_MPU9150_FIFO_EN(uint8_t data)
{
uint8_t mem_add = MPU9150_FIFO_EN;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}


// WRITE MST_CTRL REGISTER OF MPU9150

void w_MPU9150_I2C_MST_CTRL(uint8_t data)
{
uint8_t mem_add = MPU9150_I2C_MST_CTRL;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}



// WRITE INT_PIN_CFG REGISTER OF MPU9150

void w_MPU9150_INT_PIN_CFG(uint8_t data)
{
uint8_t mem_add = MPU9150_INT_PIN_CFG   ;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}

                                    
// WRITE INT_ENABLE REGISTER OF MPU9150

void w_MPU9150_INT_ENABLE(uint8_t data)
{
uint8_t mem_add = MPU9150_INT_ENABLE;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}



// WRITE MST_DELAY_CTRL REGISTER OF MPU9150

void w_MPU9150_I2C_MST_DELAY_CTRL(uint8_t data)
{
uint8_t mem_add = MPU9150_I2C_MST_DELAY_CTRL;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}


// WRITE PATH_RESET REGISTER OF MPU9150

void w_MPU9150_SIGNAL_PATH_RESET(uint8_t data)
{
uint8_t mem_add = MPU9150_SIGNAL_PATH_RESET;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}



// WRITE MOT_DETECT_CTRL REGISTER OF MPU9150

void w_MPU9150_MOT_DETECT_CTRL(uint8_t data)
{
uint8_t mem_add = MPU9150_MOT_DETECT_CTRL;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}

                                    
// WRITE USER_CTRL REGISTER OF MPU9150

void w_MPU9150_USER_CTRL(uint8_t data)
{
uint8_t mem_add = MPU9150_USER_CTRL;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}


// WRITE FIFO_COUNTH REGISTER OF MPU9150

void w_MPU9150_FIFO_COUNTH(uint8_t data)
{
uint8_t mem_add = MPU9150_FIFO_COUNTH;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}


// WRITE FIFO_COUNTL REGISTER OF MPU9150

void w_MPU9150_FIFO_COUNTL(uint8_t data)
{
uint8_t mem_add = MPU9150_FIFO_COUNTL;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}


// WRITE FIFO_R_W REGISTER OF MPU9150

void w_MPU9150_FIFO_R_W(uint8_t data)
{
uint8_t mem_add = MPU9150_FIFO_R_W;	
tb_8[0] = data;	
if(HAL_I2C_Mem_Write(&hi2c1,MPU9150_ADDRESS_AD0_HIGH,mem_add,mem_add_size,(uint8_t*)tb_8,s_8,timeout)!=HAL_OK)
{
	i2c1_error_handler();	
}
}











                         /******************End Of File********************/




