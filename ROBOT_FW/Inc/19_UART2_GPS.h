


/************************GPS : Function Definitions ***********************/


#ifndef _UART2_GPS_H
#define _UART2_GPS_H

/* Includes   */
#include "stm32f4xx_hal.h"
#include "8_UART1.h"


// External Private Variable 
extern UART_HandleTypeDef huart2;

#define STQSYNC1                0xA0        /* skytraq binary sync code 1 */
#define STQSYNC2                0xA1        /* skytraq binary sync code 2 */

#define STQPL8B                 0x00        /* skytraq payload remaining 8 bits */
#define STQPL01                 0x01        /* skytraq payload length 1 bytes */
#define STQPL02                 0x02        /* skytraq payload length 2 bytes */
#define STQPL03                 0x03        /* skytraq payload length 3 bytes */
#define STQPL04                 0x04        /* skytraq payload length 4 bytes */
#define STQPL05                 0x05        /* skytraq payload length 5 bytes */
#define STQPL06                 0x06        /* skytraq payload length 6 bytes */
#define STQPL07                 0x07        /* skytraq payload length 7 bytes */
#define STQPL08                 0x08        /* skytraq payload length 8 bytes */


#define STQBMCSM                0x01        /* skyraq binary message checksum */

#define STQENDSQ1               0x0D        /* skytraq binary message end code */
#define STQENDSQ2               0x0A        /* skytraq binary message end code */

#define ID_STQTIME              0xDC        /* skytraq message id: measurement time info */
#define ID_STQRAW               0xDD        /* skytraq message id: raw channel measurement */
#define ID_STQSFRB              0xE0        /* skytraq message id: subframe buffer data */
#define ID_RESTART              0x01        /* skytraq message id: system restart */
#define ID_CFGSERI              0x05        /* skytraq message id: configure serial port */
#define ID_CFGFMT               0x09         /* skytraq message id: configure message format */
#define ID_CFGPUPR              0x0E        /* skytraq message id: configure  */
#define ID_CFGBMDO              0x1E        /* skytraq message id : configure binary measurement data output */

#define ID_CFGRATE              0x12        /* skytraq message id: configure message rate */

/* Configure Message Type, Attribute : 2 */

#define OUT_MESS_NON            0x00        /*Output None*/ 
#define OUT_MESS_NMEA           0x01        
#define OUT_MESS_BIN            0x02 

/* Configure Message Type, Attribute : 3 */

#define UP_SRAM                 0x00
#define UP_SRAM_FLASH           0x01

/* Configure Position Update Rate, Attributes 2*/

#define UPD_RATE_7_38400        0x07        /* For BAUD RATE = 38400  */ 
#define UPD_RATE_25_115200      0x25        /* For BAUD RATE = 115200 */
#define UPD_RATE_40_230400      0x42        /* For BAUD RATE = 230400 */
 
/* Configure Binary Measurement Output Rate : Attributes 2,3,4,5,6,7 */

/*Attribute : 2 */
#define B_M_OUT_1hz                      0x00         
#define B_M_OUT_2hz                      0x01
#define B_M_OUT_4hz                      0x02
#define B_M_OUT_5hz                      0x03         
#define B_M_OUT_10hz                     0x04
#define B_M_OUT_20hz                     0x05

/*Attribute : 3 */
#define MEAS_TIME_ENABLING_DA            0x00
#define MEAS_TIME_ENABLING_EN            0x01

/*Attribute : 4 */
#define RAW_MEAS_TIME_ENABLING_DA        0x00
#define RAW_MEAS_TIME_ENABLING_EN        0x01

/*Attribute : 5 */
#define SV_CH_STATUS_ENABLING_DA          0x00
#define SV_CH_STATUS_ENABLING_EN         0x01 
 

/*Attribute : 6 */
#define RCV_STATE_ENABLING_DA            0x00
#define RCV_STATE_ENABLING_EN            0x01

/*Attribute : 7 */
#define SV_CH_STATUS_ENABLING_DA          0x00
#define SV_CH_STATUS_ENABLING_EN         0x01 

/* Attribute : 8 */
#define SUBFRAME_GPS_DA                  0x00
#define SUBFRAME_GPS_EN                  0x01
             




/* I-O FUNCTION PROTOTYPES */

void GPS_RST(void);           /* RESET GPS */ 
void GPS_SET(void);           /* SET GPS */


// FUNCTION PROTOTYPES

void GPS_Config_Out_NONE(void);
void GPS_Config_Out_BINARY(void);
void GPS_Config_Out_NMEA(void);          // GPS : OUTPUT MESSAGE = NMEA , Attribute = 0x00 Update to SRAM ONLY

void GPS_Config_Pos_Update_Rate(void);   // GPS : Configure Position Update Rate rate, MSG ID = 0x0E , Rate = 0x20 , Attributes = 0x01 */
void GPS_Config_Bin_Meas_Data_Out(void);

void GPS_QSID(void);                     /* GPS : QUERY SOFTWARE VERSION ID */ 
void GPS_Query_Pos_Update_Rate(void);    // GPS : Query Position Update Rate
void GPS_QRCNS(void);                    /* GPS : QUERY RECEIVER NAVIGATION STATUS */  
void GPS_QBDOS(void);                    /* GPS : QUERY BINARY MEASUREMENT DATA OUTPUT STATUS */

void GPS_RCV_DATA(void);                 /* GPS : RECEIVE NMEA DATA */

 













#endif /* _UART2_GPS_H */

/*************END OF FILE************/
