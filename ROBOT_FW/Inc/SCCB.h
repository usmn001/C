

/****** SCCB PROTOCOL HEADER FILE********/


#ifndef _SCCB_H
#define _SCCB_H



#define SCCB_SIC_BIT     SCCB_SIC_BIT_Pin//端口第7位
#define SCCB_SID_BIT     SCCB_SID_BIT_Pin	 //端口第8位
#define SCCB_SID_IN      SCCB_SID_GPIO_INPUT();
#define SCCB_SID_OUT     SCCB_SID_GPIO_OUTPUT();
#define SCCB_SID_STATE	 GPIOB->IDR&0x40

///////////////////////////////////////////	 
void SCCB_GPIO_Config(void);
void SCCB_SID_GPIO_OUTPUT(void);
void SCCB_SID_GPIO_INPUT(void);
void startSCCB(void);
void stopSCCB(void);
void noAck(void);
unsigned char SCCBwriteByte(unsigned char m_data);
unsigned char SCCBreadByte(void);

unsigned char rdOV7670Reg(unsigned char regID);
unsigned char wrOV7670Reg(unsigned char regID, unsigned char regDat);
















/*
#define SCCB_TIMEOUT_FLAG          ((uint32_t)35)     
#define SCCB_TIMEOUT_ADDR_SLAVE    ((uint32_t)10000)  
#define SCCB_TIMEOUT_BUSY_FLAG     ((uint32_t)10000)  




#define SCCB_FLAG_SMBALERT               ((uint32_t)0x00018000)
#define SCCB_FLAG_TIMEOUT                ((uint32_t)0x00014000)
#define SCCB_FLAG_PECERR                 ((uint32_t)0x00011000)
#define SCCB_FLAG_OVR                    ((uint32_t)0x00010800)
#define SCCB_FLAG_AF                     ((uint32_t)0x00010400)
#define SCCB_FLAG_ARLO                   ((uint32_t)0x00010200)
#define SCCB_FLAG_BERR                   ((uint32_t)0x00010100)
#define SCCB_FLAG_TXE                    ((uint32_t)0x00010080)
#define SCCB_FLAG_RXNE                   ((uint32_t)0x00010040)
#define SCCB_FLAG_STOPF                  ((uint32_t)0x00010010)
#define SCCB_FLAG_ADD10                  ((uint32_t)0x00010008)
#define SCCB_FLAG_BTF                    ((uint32_t)0x00010004)
#define SCCB_FLAG_ADDR                   ((uint32_t)0x00010002)
#define SCCB_FLAG_SB                     ((uint32_t)0x00010001)
#define SCCB_FLAG_DUALF                  ((uint32_t)0x00100080)
#define SCCB_FLAG_SMBHOST                ((uint32_t)0x00100040)
#define SCCB_FLAG_SMBDEFAULT             ((uint32_t)0x00100020)
#define SCCB_FLAG_GENCALL                ((uint32_t)0x00100010)
#define SCCB_FLAG_TRA                    ((uint32_t)0x00100004)
#define SCCB_FLAG_BUSY                   ((uint32_t)0x00100002)
#define SCCB_FLAG_MSL                    ((uint32_t)0x00100001)


// Includes
#include "stm32f4xx_hal.h"




// Function Prototypes

HAL_StatusTypeDef HAL_SCCB_IsDeviceReady(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint32_t Trials, uint32_t Timeout);

HAL_StatusTypeDef HAL_SCCB_Mem_Write(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);

HAL_StatusTypeDef HAL_SCCB_Mem_Read(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);

*/




#endif /* _SCCB_H */
               

          /*********End Of File**********/












													
													
													
													
													
													
													
													
													
													
													
													
			
			