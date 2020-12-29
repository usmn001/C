
#include "19_UART2_GPS.h"



/* RESET GPS */

void GPS_RST(void)
{
HAL_GPIO_WritePin(GPS_RST_GPIO_Port,GPS_RST_Pin,GPIO_PIN_SET); // GREEN LED ON---> LED-B
}

/* SET GPS */

void GPS_SET(void)
{
HAL_GPIO_WritePin(GPS_RST_GPIO_Port,GPS_RST_Pin,GPIO_PIN_RESET); // GREEN LED ON---> LED-B
}



/************* GPS : INPUT SYSTEM MESSAGES**************/

void GPS_Config_Out_NONE(void)           /* GPS : Output Message Type : NMEA , 
	                                          Update To Both SRAM & FLASH */                                         
{
uint8_t cmd[] = {STQSYNC1,STQSYNC2,STQPL8B,STQPL03,ID_CFGFMT,OUT_MESS_NON,UP_SRAM_FLASH,STQBMCSM,STQENDSQ1,STQENDSQ2};		
uint8_t rcv[9];
if(HAL_UART_Transmit(&huart2,(uint8_t*)cmd,sizeof(cmd),1000)==HAL_OK)
{	
HAL_UART_Receive(&huart2,(uint8_t*)rcv,9,1000);
}
	//UART1_SEND((uint8_t*)cmd,sizeof(cmd));
//UART1_SEND((uint8_t*)rcv,sizeof(rcv));
}

void GPS_Config_Out_BINARY(void)           /* GPS : Output Message Type : NMEA , 
	                                          Update To Both SRAM & FLASH */                                         
{
uint8_t cmd[] = {STQSYNC1,STQSYNC2,STQPL8B,STQPL03,ID_CFGFMT,OUT_MESS_BIN,UP_SRAM_FLASH,ID_CFGFMT,STQENDSQ1,STQENDSQ2};		
uint8_t rcv[9];
if(HAL_UART_Transmit(&huart2,(uint8_t*)cmd,sizeof(cmd),1000)==HAL_OK)
{	
HAL_UART_Receive(&huart2,(uint8_t*)rcv,9,1000);
}
	//UART1_SEND((uint8_t*)cmd,sizeof(cmd));
//UART1_SEND((uint8_t*)rcv,sizeof(rcv));
}


void GPS_Config_Out_NMEA(void)           /* GPS : Output Message Type : NMEA , 
	                                          Update To Both SRAM & FLASH */                                         
{
uint8_t cmd[] = {STQSYNC1,STQSYNC2,STQPL8B,STQPL03,ID_CFGFMT,OUT_MESS_NMEA,UP_SRAM_FLASH,0x09,STQENDSQ1,STQENDSQ2};		
uint8_t rcv[9];
if(HAL_UART_Transmit(&huart2,(uint8_t*)cmd,sizeof(cmd),1000)==HAL_OK)
{	
HAL_UART_Receive_DMA(&huart2,(uint8_t*)rcv,9);
}
	//UART1_SEND((uint8_t*)cmd,sizeof(cmd));
//UART1_SEND((uint8_t*)rcv,sizeof(rcv));
}


void GPS_Config_Pos_Update_Rate(void)    /* GPS : Configure Position Update Rate rate    
                                         MSG ID = 0x0E , Rate = 0x20 , Attributes = 0x01 */
{
uint8_t cmd[] = {STQSYNC1,STQSYNC2,STQPL8B,STQPL03,ID_CFGPUPR,UPD_RATE_25_115200,UP_SRAM_FLASH,ID_CFGPUPR,STQENDSQ1,STQENDSQ2};	
uint8_t rcv[9];
if(HAL_UART_Transmit(&huart2,(uint8_t*)cmd,10,1000)==HAL_OK)
{	
HAL_UART_Receive(&huart2,(uint8_t*)rcv,9,1000);
}
	//UART1_SEND((uint8_t*)cmd,sizeof(cmd));
//UART1_SEND((uint8_t*)rcv,sizeof(rcv));
}



void GPS_Config_Bin_Meas_Data_Out(void)  /* GPS : Configure Binary Measurement Data Output    
                                         MSG ID = 0x0E , Rate = 0x20 , Attributes = 0x01 */
{
uint8_t cmd[] = {STQSYNC1 , STQSYNC2 , STQPL8B , STQPL08 , ID_CFGBMDO,B_M_OUT_1hz , MEAS_TIME_ENABLING_EN , RAW_MEAS_TIME_ENABLING_EN , SV_CH_STATUS_ENABLING_EN , RCV_STATE_ENABLING_EN , SV_CH_STATUS_ENABLING_EN , UP_SRAM_FLASH , STQENDSQ1 , STQENDSQ2};	
uint8_t rcv[9];
if(HAL_UART_Transmit(&huart2,(uint8_t*)cmd,(sizeof(cmd)),1000)==HAL_OK)
{	
HAL_UART_Receive(&huart2,(uint8_t*)rcv,9,1000);
}
	//UART1_SEND((uint8_t*)cmd,sizeof(cmd));
//UART1_SEND((uint8_t*)rcv,sizeof(rcv));
}




/********** QUERY INPUT MESSAGES *********/



void GPS_Query_Pos_Update_Rate(void)    /* GPS : Query Position Update Rate  */
{
unsigned char cmd[] = {STQSYNC1,STQSYNC2,STQPL8B,STQPL01,0x10,0x10,STQENDSQ1,STQENDSQ2};	
uint8_t rcv[sizeof(cmd)];
HAL_UART_Transmit(&huart2,(uint8_t*)cmd,(sizeof(cmd)),1000);	
HAL_UART_Receive(&huart2,(uint8_t*)rcv,sizeof(rcv),1000);
//UART1_SEND((uint8_t*)cmd,sizeof(cmd));
//UART1_SEND((uint8_t*)rcv,sizeof(rcv));
}


void GPS_QSID(void)                      /* GPS : QUERY SOFTWARE VERSION ID */   
{
uint8_t cmd[] = {0xA0,0xA1,0x00,0x03,0x02,0x02,0x0D,0x0A};
uint8_t rcv[sizeof(cmd)];
HAL_UART_Transmit(&huart2,(uint8_t*)cmd,sizeof(cmd),1000);
HAL_UART_Receive(&huart2,(uint8_t*)rcv,sizeof(rcv),1000);
//UART1_SEND((uint8_t*)cmd,sizeof(cmd));
//UART1_SEND((uint8_t*)rcv,sizeof(rcv));
}

void GPS_QRCNS(void)                      /* GPS : QUERY RECEIVER NAVIGATION STATUS */   
{
uint8_t cmd[] = {0xA0,0xA1,0x00,0x03,0xDF,0xDF,0x0D,0x0A};
uint8_t rcv[81];
HAL_UART_Transmit(&huart2,(uint8_t*)cmd,sizeof(cmd),1000);
HAL_UART_Receive(&huart2,(uint8_t*)rcv,sizeof(rcv),1000);
//UART1_SEND((uint8_t*)cmd,sizeof(cmd));
//UART1_SEND((uint8_t*)rcv,sizeof(rcv));
}


void GPS_QBDOS(void)                      /* GPS : QUERY BINARY MEASUREMENT DATA OUTPUT STATUS */   
{
uint8_t cmd[] = {0xA0,0xA1,0x00,0x01,0x1F,0x1F,0x0D,0x0A};
uint8_t rcv[15];
HAL_UART_Transmit(&huart2,(uint8_t*)cmd,sizeof(cmd),1000);
HAL_UART_Receive(&huart2,(uint8_t*)rcv,sizeof(rcv),1000);
//UART1_SEND((uint8_t*)cmd,sizeof(cmd));
//UART1_SEND((uint8_t*)rcv,sizeof(rcv));
}








/********************* Output Messages **************************/






void GPS_RCV_DATA(void)                 /* GPS : RECEIVE NMEA DATA */
{		
uint8_t gps_dta[200];	
HAL_UART_Receive_DMA(&huart2,(uint8_t*)gps_dta,sizeof(gps_dta));	
//UART1_SEND((uint8_t*)gps_dta,200);	
}




































































































