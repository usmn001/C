


#include "stm32f4xx_hal.h"
#include "15_lights.h"

// External Private Variable 
extern UART_HandleTypeDef huart1;


// FUNCTION PROTOTYPES

void UART1_SEND(uint8_t Data[],uint16_t Size);
void UART1_RECV(uint16_t Size);






