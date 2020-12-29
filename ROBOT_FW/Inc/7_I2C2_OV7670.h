
#ifndef _I2C2_OV7670_H
#define _I2C2_OV7670_H

// Includes

#include "stm32f4xx_hal.h"





/***************** OV7670 Device Driver Definitions **************************/


// Device Pointer Register Address Values & Size

#define    PID             0x0A
#define    VER             0x0B


// HAL_I2C_Mem_Read(),HAL_I2C_Mem_Write () Parameter Values For OV7670 Camera

#define cam_dev_r               0x21         // OV7670 device address for read 
//#define cam_dev_r               0x43         // OV7670 device address for read
//#define cam_dev_w               0x42         // OV7670 device address for write
#define add_size     I2C_MEMADD_SIZE_8BIT    
#define s_8                       1          // Amount Of Data To Be Sent & Received = 1 Byte
#define s_16                      2          // Amount of Data To Be Sent & Received = 2 Byte
#define s_32                      4          // Amount of Data To Be Sent & Received = 4 Byte
#define s_40                      5          // Amount of Data To Be Sent & Received = 5 Byte
#define s_64                      8          // Amount of Data To Be Sent & Received = 8 Byte
#define timeout                  1000        // TIMEOUT DURATION IN MILLISECONDS . In Seconds = 1S    	
#define mem_size     I2C_MEMADD_SIZE_8BIT    // POINTER REGISTER ADDRESS SIZE IS OF 8-BITS


// I2C2 FUNCTION PROTOTYPES


uint8_t cam_pid(void);
uint8_t cam_ver(void);
uint8_t r_cam_gain(void);
uint8_t r_cam_blue(void);
uint8_t r_cam_red(void);

// CAMERA FUNCTION PROTOTYPES

void    Cam_Set(void);            // Set Camera
void    Cam_Rst(void);            // Reset Camera
void    Cam_Pwup(void);           // Power Up Camera
void    Cam_Pwdn(void);           // Power Down Camera
void    Cam_Stat(void);

uint8_t R_Cam_PID(void);


uint8_t Cam_Ver(void);
void    w_pid_msb(uint8_t data);  // WRITE PID MSB
void set_OV7670reg(void);



#endif /* _I2C2_OV7670_H */
                        
  												/*********End Of File**********/



