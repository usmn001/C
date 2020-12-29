

                             /*******8-UART Serial Camera**********/

#include "8_UART1.h"

static uint8_t rb[200];

void UART1_SEND(uint8_t Data[],uint16_t Size)
{	
HAL_UART_Transmit(&huart1,(uint8_t*)Data,Size,1000);
}


void UART1_RECV(uint16_t Size)
{	
HAL_UART_Receive(&huart1,(uint8_t*)rb,Size,1000);
}


