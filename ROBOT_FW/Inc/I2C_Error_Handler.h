

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __I2C_Error_Handler_H
#define __I2C_Error_Handler_H

// Includes
#include "stm32f4xx_hal.h"


// External Private VARIABLE
extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;

static uint8_t hal_status = 0;

// Function Prototypes

void i2c1_error_handler(void);
void i2c2_error_handler(void);















#endif /* __I2C_Error_Handler_H */

                      /*************End Of File**************/
