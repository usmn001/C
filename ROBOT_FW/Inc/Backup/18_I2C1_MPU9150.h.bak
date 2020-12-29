
/************************MPU9150 Definitions ***********************/
#ifndef _18_I2C1_MPU9150_H
#define _18_I2C1_MPU9150_H

// Version : 2

// Includes
#include "I2C_Error_Handler.h"
#include "stm32f4xx_hal.h"

/* Gyroscope/Accelrometer Registers */

#define MPU9150_ADDRESS_AD0_HIGH   0xD0 // I2C Address address pin high (VCC)

#define MPU9150_SMPLRT_DIV         0x19   // R/W
#define MPU9150_CONFIG             0x1A   // R/W
#define MPU9150_GYRO_CONFIG        0x1B   // R/W
#define MPU9150_ACCEL_CONFIG       0x1C   // R/W
#define MPU9150_FF_THR             0x1D   // R/W
#define MPU9150_FF_DUR             0x1E   // R/W
#define MPU9150_MOT_THR            0x1F   // R/W
#define MPU9150_MOT_DUR            0x20   // R/W
#define MPU9150_ZRMOT_THR          0x21   // R/W
#define MPU9150_ZRMOT_DUR          0x22   // R/W
#define MPU9150_FIFO_EN            0x23   // R/W
#define MPU9150_I2C_MST_CTRL       0x24   // R/W
#define MPU9150_I2C_SLV0_ADDR      0x25   // R/W
#define MPU9150_I2C_SLV0_REG       0x26   // R/W
#define MPU9150_I2C_SLV0_CTRL      0x27   // R/W
#define MPU9150_I2C_SLV1_ADDR      0x28   // R/W
#define MPU9150_I2C_SLV1_REG       0x29   // R/W
#define MPU9150_I2C_SLV1_CTRL      0x2A   // R/W
#define MPU9150_I2C_SLV2_ADDR      0x2B   // R/W
#define MPU9150_I2C_SLV2_REG       0x2C   // R/W
#define MPU9150_I2C_SLV2_CTRL      0x2D   // R/W
#define MPU9150_I2C_SLV3_ADDR      0x2E   // R/W
#define MPU9150_I2C_SLV3_REG       0x2F   // R/W
#define MPU9150_I2C_SLV3_CTRL      0x30   // R/W
#define MPU9150_I2C_SLV4_ADDR      0x31   // R/W
#define MPU9150_I2C_SLV4_REG       0x32   // R/W
#define MPU9150_I2C_SLV4_DO        0x33   // R/W
#define MPU9150_I2C_SLV4_CTRL      0x34   // R/W
#define MPU9150_I2C_SLV4_DI        0x35   // R  
#define MPU9150_I2C_MST_STATUS     0x36   // R
#define MPU9150_INT_PIN_CFG        0x37   // R/W
#define MPU9150_INT_ENABLE         0x38   // R/W
#define MPU9150_INT_STATUS         0x3A   // R  
#define MPU9150_ACCEL_XOUT_H       0x3B   // R  
#define MPU9150_ACCEL_XOUT_L       0x3C   // R  
#define MPU9150_ACCEL_YOUT_H       0x3D   // R  
#define MPU9150_ACCEL_YOUT_L       0x3E   // R  
#define MPU9150_ACCEL_ZOUT_H       0x3F   // R  
#define MPU9150_ACCEL_ZOUT_L       0x40   // R  
#define MPU9150_TEMP_OUT_H         0x41   // R  
#define MPU9150_TEMP_OUT_L         0x42   // R  
#define MPU9150_GYRO_XOUT_H        0x43   // R  
#define MPU9150_GYRO_XOUT_L        0x44   // R  
#define MPU9150_GYRO_YOUT_H        0x45   // R  
#define MPU9150_GYRO_YOUT_L        0x46   // R  
#define MPU9150_GYRO_ZOUT_H        0x47   // R  
#define MPU9150_GYRO_ZOUT_L        0x48   // R  
#define MPU9150_EXT_SENS_DATA_00   0x49   // R  
#define MPU9150_EXT_SENS_DATA_01   0x4A   // R  
#define MPU9150_EXT_SENS_DATA_02   0x4B   // R  
#define MPU9150_EXT_SENS_DATA_03   0x4C   // R  
#define MPU9150_EXT_SENS_DATA_04   0x4D   // R  
#define MPU9150_EXT_SENS_DATA_05   0x4E   // R  
#define MPU9150_EXT_SENS_DATA_06   0x4F   // R  
#define MPU9150_EXT_SENS_DATA_07   0x50   // R  
#define MPU9150_EXT_SENS_DATA_08   0x51   // R  
#define MPU9150_EXT_SENS_DATA_09   0x52   // R  
#define MPU9150_EXT_SENS_DATA_10   0x53   // R  
#define MPU9150_EXT_SENS_DATA_11   0x54   // R  
#define MPU9150_EXT_SENS_DATA_12   0x55   // R  
#define MPU9150_EXT_SENS_DATA_13   0x56   // R  
#define MPU9150_EXT_SENS_DATA_14   0x57   // R  
#define MPU9150_EXT_SENS_DATA_15   0x58   // R  
#define MPU9150_EXT_SENS_DATA_16   0x59   // R  
#define MPU9150_EXT_SENS_DATA_17   0x5A   // R  
#define MPU9150_EXT_SENS_DATA_18   0x5B   // R  
#define MPU9150_EXT_SENS_DATA_19   0x5C   // R  
#define MPU9150_EXT_SENS_DATA_20   0x5D   // R  
#define MPU9150_EXT_SENS_DATA_21   0x5E   // R  
#define MPU9150_EXT_SENS_DATA_22   0x5F   // R  
#define MPU9150_EXT_SENS_DATA_23   0x60   // R  
#define MPU9150_MOT_DETECT_STATUS  0x61   // R  
#define MPU9150_I2C_SLV0_DO        0x63   // R/W
#define MPU9150_I2C_SLV1_DO        0x64   // R/W
#define MPU9150_I2C_SLV2_DO        0x65   // R/W
#define MPU9150_I2C_SLV3_DO        0x66   // R/W
#define MPU9150_I2C_MST_DELAY_CTRL 0x67   // R/W
#define MPU9150_SIGNAL_PATH_RESET  0x68   // R/W
#define MPU9150_MOT_DETECT_CTRL    0x69   // R/W
#define MPU9150_USER_CTRL          0x6A   // R/W
#define MPU9150_PWR_MGMT_1         0x6B   // R/W
#define MPU9150_PWR_MGMT_2         0x6C   // R/W
#define MPU9150_FIFO_COUNTH        0x72   // R/W
#define MPU9150_FIFO_COUNTL        0x73   // R/W
#define MPU9150_FIFO_R_W           0x74   // R/W
#define MPU9150_WHO_AM_I           0x75   // R





// HAL_I2C1 Driver Parameter Definitios

#define s_8                       1         // Amount Of Data To Be Sent & Received = 1 Byte
#define s_16                      2         // Amount of Data To Be Sent & Received = 2 Byte
#define s_32                      4         // Amount of Data To Be Sent & Received = 4 Byte
#define s_40                      5         // Amount of Data To Be Sent & Received = 5 Byte
#define s_64                      8         // Amount of Data To Be Sent & Received = 8 Byte
#define timeout                  1000       // TIMEOUT DURATION IN MILLISECONDS . In Seconds = 1S 

#define mem_add_size     I2C_MEMADD_SIZE_8BIT     // POINTER REGISTER ADDRESS SIZE IS OF 8-BITS


// FUNCTION PROTOTYPES
void mpu_stat(void);


/* POWER , I/O MANAGEMENT FUNCTION PROTOTYPES */


void slp_mod_of(void);                      // ACCELROMETER : SLEEP MODE OF , TEMPERATURE SENSOR DISABLED, INTERNAL CLOCK 8Mhz ENABLED
void slp_mod_on(void);                      // ACCELROMETER : SLEEP MODE ON , TEMPERATURE SENSOR DISABLED, INTERNAL CLOCK 8Mhz ENABLED
void rst_acc(void);                         // ACCELROMETER : RESET    
void cyc_wak_slp_on(void);                  // ACCELROMETER : CYCLE BETWEEN WAKE UP & SLEEP MODES ENABLED,SLEEP MODE OF, TEMPERATURE SENSOR DISABLED,INTERNAL CLOCK 8Mhz ENABLED 
void cyc_wak_slp_of(void);                  // ACCELROMETER : CYCLE BETWEEN WAKE UP & SLEEP MODES DISABLED,TEMPERATURE SENSOR DISABLED,INTERNAL CLOCK 8Mhz ENABLED
void wake_up_freq(void);                    // ACCELROMETER : WAKE UP FREQUENCY = 10 Hz

/* READ FUNCTION PROTOTYPES */

uint8_t r_smprt_div (void);                 
uint8_t r_config (void);                    
uint8_t r_gyro_config(void);                
uint8_t r_accel_config(void);               
uint8_t r_MPU9150_FF_THR (void);   
uint8_t r_MPU9150_FF_DUR(void);
uint8_t r_MPU9150_MOT_THR(void);
uint8_t r_MPU9150_MOT_DUR(void);
uint8_t r_MPU9150_ZRMOT_THR (void);
uint8_t r_MPU9150_ZRMOT_DUR(void);
uint8_t r_MPU9150_FIFO_EN(void);
uint8_t r_MPU9150_I2C_MST_CTRL(void);
uint8_t r_MPU9150_I2C_SLV0_ADDR (void);
uint8_t r_MPU9150_I2C_SLV0_REG (void);
uint8_t r_MPU9150_I2C_SLV0_CTRL(void);
uint8_t r_MPU9150_I2C_SLV1_ADDR(void);
uint8_t r_MPU9150_I2C_SLV1_REG (void);
uint8_t r_MPU9150_I2C_SLV1_CTRL(void);
uint8_t r_MPU9150_I2C_SLV2_ADDR(void);
uint8_t r_MPU9150_I2C_SLV2_REG(void);
uint8_t r_MPU9150_I2C_SLV2_CTRL(void);
uint8_t r_MPU9150_I2C_SLV3_ADDR(void);
uint8_t r_MPU9150_I2C_SLV3_REG(void);
uint8_t r_MPU9150_I2C_SLV3_CTRL(void);
uint8_t r_MPU9150_I2C_SLV4_ADDR (void);
uint8_t r_MPU9150_I2C_SLV4_REG(void);
uint8_t r_MPU9150_I2C_SLV4_DO(void);
uint8_t r_MPU9150_I2C_SLV4_CTRL(void);
uint8_t r_MPU9150_I2C_SLV4_DI (void);
uint8_t r_MPU9150_I2C_MST_STATUS(void);
uint8_t r_MPU9150_INT_PIN_CFG(void);
uint8_t r_MPU9150_INT_ENABLE(void);
uint8_t r_MPU9150_INT_STATUS (void);
uint16_t r_MPU9150_ACCEL_XOUT_H (void);
uint8_t r_MPU9150_ACCEL_XOUT_L(void);
uint16_t r_MPU9150_ACCEL_YOUT_H(void);
uint8_t r_MPU9150_ACCEL_YOUT_L (void);
uint16_t r_MPU9150_ACCEL_ZOUT_H(void);
uint8_t r_MPU9150_ACCEL_ZOUT_L(void);
uint16_t r_MPU9150_GYRO_XOUT_H(void);
uint8_t r_MPU9150_GYRO_XOUT_L (void);
uint16_t r_MPU9150_GYRO_YOUT_H(void);
uint8_t r_MPU9150_GYRO_YOUT_L(void);
uint16_t r_MPU9150_GYRO_ZOUT_H(void);
uint8_t r_MPU9150_GYRO_ZOUT_L(void);
uint8_t r_MPU9150_MOT_DETECT_STATUS(void);
uint8_t r_MPU9150_I2C_MST_DELAY_CTRL(void);
uint8_t r_MPU9150_SIGNAL_PATH_RESET(void);
uint8_t r_MPU9150_MOT_DETECT_CTRL(void);
uint8_t r_MPU9150_USER_CTRL(void);
uint8_t r_pwr_mgmt_1(void);                 
uint8_t r_pwr_mgmt_2(void);
uint8_t r_MPU9150_FIFO_COUNTH(void);
uint8_t r_MPU9150_FIFO_COUNTL (void);
uint8_t r_MPU9150_FIFO_R_W(void);               
uint8_t r_who_am_i(void);                   


/* WRITE FUNCTION PROTOTYPES */

void w_smprt_div(uint8_t data);          
void w_config(uint8_t data);             
void w_gyro_config(uint8_t data);        
void w_MPU9150_ACCEL_CONFIG(uint8_t data);
void w_MPU9150_FF_THR(uint8_t data);
void w_MPU9150_FF_DUR(uint8_t data);
void w_MPU9150_MOT_THR(uint8_t data);
void w_MPU9150_MOT_DUR(uint8_t data);
void w_MPU9150_ZRMOT_THR(uint8_t data);
void w_MPU9150_ZRMOT_DUR(uint8_t data);
void w_MPU9150_FIFO_EN(uint8_t data);
void w_MPU9150_I2C_MST_CTRL(uint8_t data);
void w_MPU9150_INT_PIN_CFG(uint8_t data);
void w_MPU9150_INT_ENABLE(uint8_t data);
void w_MPU9150_I2C_MST_DELAY_CTRL(uint8_t data);	
void w_MPU9150_SIGNAL_PATH_RESET(uint8_t data);
void w_MPU9150_MOT_DETECT_CTRL(uint8_t data);	
void w_MPU9150_USER_CTRL(uint8_t data);
void w_MPU9150_FIFO_COUNTH(uint8_t data);	
void w_MPU9150_FIFO_COUNTL(uint8_t data);
void w_MPU9150_FIFO_R_W(uint8_t data);	









#endif /* _18_I2C1_MPU9150_H */

                     /*************End Of File**************/
