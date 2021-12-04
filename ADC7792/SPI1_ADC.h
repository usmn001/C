/*
 * SPI1_ADC.h
 *
 *  Created on: Aug 19, 2021
 *      Author: M Usman
 */

#ifndef INC_SPI1_ADC_H_
#define INC_SPI1_ADC_H_

#include "main.h"
#include <stdbool.h>
#define ADC_BUFFER_SIZE  (1)
#define ADC_BUFFER_SIZE (1)
#define ADC_MAX_TRY	    (5)
#define ADC_CONF_DELAY	(5)
#define ADC_EMPTY_BYTE  (0xFF)      // empty byte for reading SPI


/* ADC Status Register Codes */
typedef enum{
RDY            = 0x80U,
ERR            = 0x40U,
NO_ERR         = 0x00U,
STS_CH2        = 0x04U,
STS_CH1        = 0x02U,
STS_CH0        = 0x01U
}ADCStatus;

enum ADC_CHANNEL
{
  ADC_CHNL_1,
  ADC_CHNL_2,
  ADC_CHNL_3,
  ADC_CHNL_4,
  ADC_CHNL_5,
  ADC_CHNL_6,
  ADC_CHNL_7,
  ADC_CHNL_8,
  ADC_CHNL_9,
  ADC_CHNL_10,
  ADC_CNHL_11,
  ADC_CHNL_12,
  ADC_CHNL_13,
  ADC_CHNL_14,
  ADC_CHNL_15,
  ADC_CHNL_16,
  ADC_NUM_CHANNELS
};

enum CAL_REGISTER_TYPE
{
  CAL_REG_OFFSET,
  CAL_REG_GAIN
};

enum TTemperatureCannel
{
  TEMPERATURE_OFFSET,
  TEMPERATURE_GET
};

/* ADC Application Code Function Prototypes & Variable Declarations */

volatile uint16_t adcResult[ADC_NUM_CHANNELS];
volatile bool adcReady[ADC_NUM_CHANNELS];
//sample buffer
volatile uint16_t adcBuffer[ADC_BUFFER_SIZE][ADC_NUM_CHANNELS];
volatile uint8_t adcHead[ADC_NUM_CHANNELS];
volatile uint8_t adcTail[ADC_NUM_CHANNELS];
/* ADC_GetValue - get measured value  */
extern uint16_t ADC_GetValue(uint8_t channel);

uint8_t adcChannel;

/* MULTIPLEXER  Function Prototype */

void ADC_Switch(uint8_t channel);


/* ADC Communication Register Values */

#define ADC_MODE_CONTINUOUS     0x44   /* Writing ADC Communication Register For ADC Continuous Mode
                                       Comm Register Bits CR7(WEN)=0,CR6(R/W)=1,CR5(RS2)=0,CR4(RS1)=0,CR3(RS0)=0,CR2(CREAD)=1,CR1=0,CR0=0*/

#define REG_STATUS              0x40   /* Reading Status Register
                                       Comm Register Bits CR7(WEN)=0,CR6(R/W)=1,CR5(RS2)=0,CR4(RS1)=0,CR3(RS0)=0,CR2(CREAD)=0,CR1=0,CR0=0 */

#define REG_ID                  0x60   /* Reading ID Register
                                       Comm Register Bits CR7(WEN)=0,CR6(R/W)=1,CR5(RS2)=1,CR4(RS1)=0,CR3(RS0)=0,CR2(CREAD)=0,CR1=0,CR0=0 */

#define REG_MODE_WR             0x08    /* Writing Mode Register
                                       Comm Register Bits CR7(WEN)=0,CR6(R/W)=0,CRS(RS2)=0,CR4(RS1)=0,CR3(RS0)=1,CR2(READ)=0,CR1=0,CR0=0  */

#define REG_MODE_RD             0x48   /* Reading Mode Register
                                       Comm Register Bits CR7(WEN)=0,CR6(R/W)=1,CRS(RS2)=0,CR4(RS1)=0,CR3(RS0)=1,CR2(READ)=0,CR1=0,CR0=0  */

#define REG_CONFIG_WR           0x10    /* Writing Configuration Register
                                       Comm Register Bits CR7(WEN)=0,CR6(R/W)=0,CRS(RS2)=0,CR4(RS1)=1,CR3(RS0)=0,CR2(READ)=0,CR1=0,CR0=0  */

#define REG_CONFIG_RD           0x50   /* Reading Configuration Register
                                       Comm Register Bits CR7(WEN)=0,CR6(R/W)=1,CRS(RS2)=0,CR4(RS1)=1,CR3(RS0)=0,CR2(READ)=0,CR1=0,CR0=0  */

#define REG_DATA_RD             0x58   /* Reading Data Register
                                       Comm Register Bits CR7(WEN)=0,CR6(R/W)=1,CRS(RS2)=0,CR4(RS1)=1,CR3(RS0)=1,CR2(READ)=0,CR1=0,CR0=0  */

#define REG_IO_RD               0x68   /* Reading IO Register
                                       Comm Register Bits CR7(WEN)=0,CR6(R/W)=1,CRS(RS2)=1,CR4(RS1)=0,CR3(RS0)=1,CR2(READ)=0,CR1=0,CR0=0  */

#define REG_IO_WR               0x28   /* Writing IO Register
                                       Comm Register Bits CR7(WEN)=0,CR6(R/W)=0,CRS(RS2)=1,CR4(RS1)=0,CR3(RS0)=1,CR2(READ)=0,CR1=0,CR0=0  */

#define REG_OFFSET_RD           0x70   /* Reading OFFSET Register
                                       Comm Register Bits CR7(WEN)=0,CR6(R/W)=1,CRS(RS2)=1,CR4(RS1)=1,CR3(RS0)=0,CR2(READ)=0,CR1=0,CR0=0  */


#define REG_OFFSET_WR           0x30   /* Writing OFFSET Register
                                       Comm Register Bits CR7(WEN)=0,CR6(R/W)=0,CRS(RS2)=1,CR4(RS1)=1,CR3(RS0)=0,CR2(READ)=0,CR1=0,CR0=0  */

#define REG_FULLSCALE_RD        0x78   /* Reading FULL SCALE OFFSET Register
                                       Comm Register Bits CR7(WEN)=0,CR6(R/W)=1,CRS(RS2)=1,CR4(RS1)=1,CR3(RS0)=1,CR2(READ)=0,CR1=0,CR0=0  */


#define REG_FULLSCALE_WR        0x38   /* Writing FULL SCALE OFFSET Register
                                       Comm Register Bits CR7(WEN)=0,CR6(R/W)=0,CRS(RS2)=1,CR4(RS1)=1,CR3(RS0)=1,CR2(READ)=0,CR1=0,CR0=0  */



/* ADC I/O Operation Function Prototypes */

bool ADC_RESET(void);              /* Function For Resetting The ADC */
void ADC_CS(void);                 /* Function makes CS signal High to Low to indicate start of data frame*/
bool ADC_CR_WE(void);              /* Function For Enabling Write Operation To Communication Register */
uint8_t ADC_SR_RD(void);           /* Function For Reading ADC Status Register */
uint8_t ADC_ID_RD(void);           /* Function For Reading ADC ID Register */
uint16_t ADC_DATA_RD(void);        /* Function For Reading ADC DATA Register */
uint8_t ADC_IO_RD(void);           /* Function For Reading ADC IO Register */
bool ADC_IO_WR(void);              /* Function For Writing ADC IO Register : Excitation Current = 1mA ,
                                      Current Src IEXC1 connected to Pin IOUT1,Current Src IEXC2 connected to Pin IOUT2.
                                      IO7=0,IO6=0,IO5=0,IO4=0,IO3(IEXCDIR1)=0,IO2(IEXCDIR0)=0,IO1(IEXCEN1)=1,IO0(IEXCEN0)=1*/

/* ADC OFFSET & FULLSCALE Registers Function Prototypes */

uint16_t ADC_OFFSET_RD(void);      /* Function For Reading ADC OFFSET Register */

bool ADC_OFFSET_WR(void);          /* Function For Writing ADC OFFSET Register (Future Update) */

uint16_t ADC_FULLSCALE_RD(void);   /* Function For Reading ADC FULLSCALE Register */

bool ADC_FULLSCALE_WR(void);       /* Function For Writing ADC FULLSCALE Register (Future Update)*/


/* ADC MODE Register Function Prototypes */

uint16_t ADC_MODE_RD(void);        /* Function For Reading ADC Mode Register. */
bool ADC_MODE_IDL(void);           /* Function For Writing ADC Mode Register : ADC IDLE MODE. */
bool ADC_MODE_PWD(void);           /* Function For Writing ADC Mode Register : ADC POWER DOWN MODE. */

bool ADC_MODE_CONT(void);          /* Function For Writing ADC Mode Register : ADC Continuous Conversion Mode,
                                                                               ADC Internal Clock Not Available At CLK Pin,
                                                                               Filter Update Select Bits 16.7 Hz ADC frequency, 120 ms settling time, 65 dB rejection at 50 and 60 Hz)*/

bool ADC_INT_ZERO(void);           /* Function For Writing ADC Mode Register : ADC Continuous Conversion Mode,
                                                                               ADC Internal Zero-Scale Calibration ,
                                                                               ADC Internal Clock Not Available At CLK Pin,
                                                                               Filter Update Select Bits 16.7 Hz ADC frequency, 120 ms settling time, 65 dB rejection at 50 and 60 Hz)*/

/***************** ADC Configuration Register Functions Prototypes *****************/

uint16_t ADC_CONFIG_RD(void);       /* Function For Reading ADC Configuration Register. */

bool     ADC_CONFIG_WR(void);       /* Function For Writing ADC Configuration Register :
                                       Bias voltage generator disabled, Burnout Current Disabled,Unipolar,Boost disabled,Gain=16 ADC Input Voltage Range = 156.2mV
                                       CON15(VBIAS1)=0, CON14(VBIAS0)=0,CON13(B0)=0,CON12(U/B)=1,CON11(BOOST)=0,CON10(G2)=1,CON9(G1)=0,CON8(G0)=0
                                       Ext Ref App b/w Refin(+) & Refin(-) "CON7 (REFSEL)=0, Buffered Mode Of Operation CON4(BUF)=1, ", CON2(CH2)=0,CON1(CH1)=0,CON0(CH0)=0 Channel AIN1(+) – AIN1(–)
                                       CON6=0, CON5=0,  CON3=0 */






#endif /* INC_SPI1_ADC_H_ */
