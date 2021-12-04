/*
 * SPI1_ADC.c
 *
 *  Created on: Aug 19, 2021
 *      Author: M Usman
 */
#include "SPI1_ADC.h"
extern SPI_HandleTypeDef hspi1;



//------------------------------------------------------------------------------
/// @brief      Switch multiplexers
/// @param [in] channel Number of channel to activate
//------------------------------------------------------------------------------

void ADC_Switch(uint8_t channel)
{
  HAL_GPIO_WritePin(GPIOB, MUX_EN_Pin, GPIO_PIN_SET);
  switch (channel)
  {
    case ADC_CHNL_1:
      HAL_GPIO_WritePin(GPIOA, MUX_A0_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A1_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A2_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A3_Pin, GPIO_PIN_RESET);
      break;
    case ADC_CHNL_2:
      HAL_GPIO_WritePin(GPIOA, MUX_A0_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A1_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A2_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A3_Pin, GPIO_PIN_RESET);
      break;
    case ADC_CHNL_3:
      HAL_GPIO_WritePin(GPIOA, MUX_A0_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A1_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A2_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A3_Pin, GPIO_PIN_RESET);
      break;
    case ADC_CHNL_4:
      HAL_GPIO_WritePin(GPIOA, MUX_A0_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A1_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A2_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A3_Pin, GPIO_PIN_RESET);
      break;
    case ADC_CHNL_5:
      HAL_GPIO_WritePin(GPIOA, MUX_A0_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A1_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A2_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A3_Pin, GPIO_PIN_RESET);
      break;
    case ADC_CHNL_6:
      HAL_GPIO_WritePin(GPIOA, MUX_A0_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A1_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A2_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A3_Pin, GPIO_PIN_RESET);
      break;
    case ADC_CHNL_7:
      HAL_GPIO_WritePin(GPIOA, MUX_A0_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A1_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A2_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A3_Pin, GPIO_PIN_RESET);
      break;
    case ADC_CHNL_8:
      HAL_GPIO_WritePin(GPIOA, MUX_A0_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A1_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A2_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A3_Pin, GPIO_PIN_RESET);
      break;
    case ADC_CHNL_9:
      HAL_GPIO_WritePin(GPIOA, MUX_A0_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A1_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A2_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A3_Pin, GPIO_PIN_SET);
      break;
     case ADC_CHNL_10:
      HAL_GPIO_WritePin(GPIOA, MUX_A0_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A1_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A2_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A3_Pin, GPIO_PIN_SET);
      break;
     case ADC_CNHL_11:
      HAL_GPIO_WritePin(GPIOA, MUX_A0_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A1_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A2_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A3_Pin, GPIO_PIN_SET);
      break;
     case ADC_CHNL_12:
      HAL_GPIO_WritePin(GPIOA, MUX_A0_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A1_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A2_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A3_Pin, GPIO_PIN_SET);
      break;
     case ADC_CHNL_13:
      HAL_GPIO_WritePin(GPIOA, MUX_A0_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A1_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A2_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A3_Pin, GPIO_PIN_SET);
      break;
     case ADC_CHNL_14:
      HAL_GPIO_WritePin(GPIOA, MUX_A0_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A1_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A2_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A3_Pin, GPIO_PIN_SET);
      break;
     case ADC_CHNL_15:
      HAL_GPIO_WritePin(GPIOA, MUX_A0_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, MUX_A1_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A2_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A3_Pin, GPIO_PIN_SET);
      break;
     case ADC_CHNL_16:
      HAL_GPIO_WritePin(GPIOA, MUX_A0_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A1_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A2_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, MUX_A3_Pin, GPIO_PIN_SET);
      break;
    default:
      break;
  }
  //HAL_GPIO_WritePin(GPIOB, MUX_EN_Pin, GPIO_PIN_SET);
}

/* ADC I/O Function Definitions */

void ADC_CS(void){
HAL_GPIO_WritePin(GPIOA,ADC_SPI_NSS_Pin, GPIO_PIN_SET);
HAL_Delay(1);
HAL_GPIO_WritePin(GPIOA,ADC_SPI_NSS_Pin, GPIO_PIN_RESET);
}

void ADC_CS_E(void){
HAL_GPIO_WritePin(GPIOA,ADC_SPI_NSS_Pin, GPIO_PIN_SET);
}

bool ADC_RESET(void){
uint8_t TX_BUFF[5] = {0xff,0xff,0xff,0xff,0xff}; /* Writing 32 consequtive 1's on DIN Line */
ADC_CS();
if(HAL_OK==HAL_SPI_Transmit_DMA(&hspi1,TX_BUFF,sizeof(TX_BUFF))){
    ADC_CS_E();
	return 1;
}
return 0;
}

/* Function For Enabling Write Operation To Communication Register */

bool ADC_CR_WE(void){
uint8_t TX_BUFF[] = {ADC_MODE_CONTINUOUS};
ADC_CS();
if(HAL_OK==HAL_SPI_Transmit_DMA(&hspi1,TX_BUFF,sizeof(TX_BUFF))){
	ADC_CS_E();
	return 1;
}
return 0;
}

/* Function For Reading ID Register Of ADC */
uint8_t ADC_ID_RD(void){
uint8_t TX_BUFF[1] = {REG_ID};
uint8_t RX_BUFF[1]={0};
uint8_t rb;
ADC_CS();
if(HAL_OK== HAL_SPI_Transmit_DMA(&hspi1,TX_BUFF,sizeof(TX_BUFF))){
   if(HAL_OK==HAL_SPI_Receive_DMA(&hspi1,RX_BUFF,sizeof(RX_BUFF))){
   ADC_CS_E();
   rb = RX_BUFF[0];
   return rb;
}
}
return 0x44;
}

/* Function For Reading Status Register Of ADC */

uint8_t ADC_SR_RD(void){
uint8_t TX_BUFF[] = {REG_STATUS};
uint8_t RX_BUFF[1] = {0x00};
uint8_t rb=0x00;
ADC_CS();
if(HAL_OK==HAL_SPI_TransmitReceive_DMA(&hspi1,TX_BUFF,RX_BUFF,sizeof(TX_BUFF))){
	if(HAL_OK==HAL_SPI_Receive_DMA(&hspi1,RX_BUFF,sizeof(RX_BUFF))){
		ADC_CS_E();
		rb = RX_BUFF[0];
		return rb;
	}
}
return rb;
}


/************* ADC Mode Register Functions *************/


/* Function For Reading MODE Register Of ADC */

uint16_t ADC_MODE_RD(void){
uint8_t TX_BUFF[] = {REG_MODE_RD};
uint8_t RX_BUFF[2]={0};
uint16_t rb = 0x0000;
ADC_CS();
if(HAL_OK==HAL_SPI_Transmit_DMA(&hspi1,TX_BUFF,sizeof(TX_BUFF))){
	if(HAL_OK==HAL_SPI_Receive_DMA(&hspi1,RX_BUFF,sizeof(RX_BUFF))){
		ADC_CS_E();
		rb = RX_BUFF[0];
		rb = rb<<8;
		rb = rb | RX_BUFF[1];
		return rb;
	}
}
return 0x0000;
}

/* Function For Writing MODE Register Of ADC : ADC IDLE MODE */

bool ADC_MODE_IDL(void){
uint8_t TX_BUFF[] = {REG_MODE_WR,0x40,0x00};
uint16_t rb = 0x0000;
ADC_CS();
if(HAL_OK==HAL_SPI_Transmit_DMA(&hspi1,TX_BUFF,sizeof(TX_BUFF))){
	ADC_CS_E();
	rb = ADC_MODE_RD();
	if(rb==0x4000){
		return 1;
	}
}
return 0;        /* ADC IDLE MODE NOT CONFIGURED */
}

/* Function For Writing ADC Mode Register : ADC POWER DOWN MODE*/

bool ADC_MODE_PWD(void){
uint8_t TX_BUFF[] = {REG_MODE_WR,0x60,0x00};
uint16_t rb = 0x0000;
ADC_CS();
if( HAL_OK==HAL_SPI_Transmit_DMA(&hspi1,TX_BUFF,sizeof(TX_BUFF))){
	ADC_CS_E();
	rb = ADC_MODE_RD();
	if(rb==0x6000){
		return 1;
	}
}
return 0;        /* ADC POWER DOWN MODE NOT CONFIGURED */
}

/* Function For Writing ADC Mode Register : ADC Continuous Conversion Mode,
 *                                          ADC Internal 64 Khz Clock Not Available At CLK Pin .
 *                                          Filter Update Select Bits 16.7 Hz ADC frequency, 120 ms settling time, 65 dB rejection at 50 and 60 Hz)*/


bool ADC_MODE_CONT(void){
uint8_t TX_BUFF[] = {REG_MODE_WR,0x00,0x0A};
uint16_t rb = 0x0000;
ADC_CS();
if(HAL_OK==HAL_SPI_Transmit_DMA(&hspi1,TX_BUFF,sizeof(TX_BUFF))){
	ADC_CS_E();
	rb=ADC_MODE_RD();
	if(rb==0x000A){
		return 1;
    }
    return 0;        /* ADC Continuous Conversion Mode, CONFIGURED */
}
return 0;        /* ADC Continuous Conversion Mode, CONFIGURED */
}

/* Function For Writing ADC Mode Register : ADC Continuous Conversion Mode,
 *                                          ADC Internal Zero-Scale Calibration.
 *                                          ADC Internal 64 Khz Clock Not Available At CLK Pin .
 *                                          Filter Update Select Bits 16.7 Hz ADC frequency, 120 ms settling time, 65 dB rejection at 50 and 60 Hz)*/


bool ADC_INT_ZERO(void){
uint8_t TX_BUFF[] = {REG_MODE_WR,0x80,0x0A};
uint16_t rb = 0x0000;
ADC_CS();
if(HAL_OK==HAL_SPI_Transmit_DMA(&hspi1,TX_BUFF,sizeof(TX_BUFF))){
	ADC_CS_E();
	rb = ADC_MODE_RD();
	if(rb==0x800A){
while(ADC_SR_RD()!=0x8){

}
		return 1;
	}
}
return 0; /* ADC Internal Zero-Scale Calibration NOT CONFIGURED */
}





/********** ADC Configuration Register Functions */

/* Function For Reading Configuration Register Of ADC */

uint16_t ADC_CONFIG_RD(void){
uint8_t TX_BUFF[] = {REG_CONFIG_RD};
uint8_t RX_BUFF[2]={0};
uint16_t rb = 0x0000;
ADC_CS();
if(HAL_OK==HAL_SPI_Transmit_DMA(&hspi1,TX_BUFF,sizeof(TX_BUFF))){
	if(HAL_OK==HAL_SPI_Receive_DMA(&hspi1,RX_BUFF,sizeof(RX_BUFF))){
		ADC_CS_E();
		rb = RX_BUFF[0];
		rb = rb<<8;
		rb = rb | RX_BUFF[1];
		return rb;
	}
	return HAL_ERROR;
}
return HAL_ERROR;


}

/* Function For Writing Configuration Register Of ADC :
Bias voltage generator disabled, Burnout Current Disabled,Unipolar,Boost disabled,Gain=16 ADC Input Voltage Range = 156.2mV
CON15(VBIAS1)=0, CON14(VBIAS0)=0,CON13(B0)=0,CON12(U/B)=1,CON11(BOOST)=0,CON10(G2)=1,CON9(G1)=0,CON8(G0)=0
Ext Ref App b/w Refin(+) & Refin(-), Buffered Mode Of Operation, ", (CH2)=0,CON1(CH1)=0,CON0(CH0)=0 Channel AIN1(+) – AIN1(–)
CON7(REFSEL)=0, CON6=0, CON5=0,        CON4(BUF)=1, CON3=0,          CON2=0, CON1=0,     CON0=0  */


bool ADC_CONFIG_WR(void){
uint8_t TX_BUFF[] = {REG_CONFIG_WR,0x14,0x10};
uint16_t rb = 0x0000;
ADC_CS();
if(HAL_OK== HAL_SPI_Transmit_DMA(&hspi1,TX_BUFF,sizeof(TX_BUFF))){
	ADC_CS_E();
	rb = ADC_CONFIG_RD();
	if(rb==0x1410){
		return 1;
	}
}
	return 0;        /* ADC Configuration Register Not Configured */
}

/* Function For Reading ADC Data Register */

uint16_t ADC_DATA_RD(void){
uint8_t TX_BUFF[] = {REG_DATA_RD};
uint8_t RX_BUFF[2]={0};
uint16_t rb = 0x0000;
do
{

}while(RDY==ADC_SR_RD());     /* Keep waiting for RDY bit to get cleared,Cleared when data is written to the ADC data register */
ADC_CS();
if(HAL_OK== HAL_SPI_Transmit_DMA(&hspi1,TX_BUFF,sizeof(TX_BUFF))){
if(HAL_OK==HAL_SPI_Receive_DMA(&hspi1,RX_BUFF,sizeof(RX_BUFF))){
ADC_CS_E();
rb = RX_BUFF[0];
rb = rb<<8;
rb = rb | RX_BUFF[1];
}
}

return rb;
}


/* Function For Reading ADC IO Register */

uint8_t ADC_IO_RD(void){
uint8_t TX_BUFF[] = {REG_IO_RD};
uint8_t RX_BUFF[1]={0};
uint8_t rb = 0x00;
ADC_CS();
if(HAL_OK== HAL_SPI_Transmit_DMA(&hspi1,TX_BUFF,sizeof(TX_BUFF))){
	if(HAL_OK==HAL_SPI_Receive_DMA(&hspi1,RX_BUFF,sizeof(RX_BUFF))){
		ADC_CS_E();
		rb = RX_BUFF[0];
}
}
return rb;
}


/* Function For Writing ADC IO Register */

bool ADC_IO_WR(void){
uint8_t TX_BUFF[] = {REG_IO_WR,0x03};
uint8_t rb = 0x00;
ADC_CS();
if(HAL_OK==HAL_SPI_Transmit_DMA(&hspi1,TX_BUFF,sizeof(TX_BUFF))){
	ADC_CS_E();
	rb = ADC_IO_RD();
	if(rb==0x03){
		return 1;
	}
}
return 0;        /* ADC IO Register Not Configured */
}


/* Function For Reading ADC OFFSET Register */

uint16_t ADC_OFFSET_RD(void){
uint8_t TX_BUFF[] = {REG_OFFSET_RD};
uint8_t RX_BUFF[2]={0};
uint16_t rb = 0x0000;
ADC_CS();
if(HAL_OK== HAL_SPI_Transmit_DMA(&hspi1,TX_BUFF,sizeof(TX_BUFF))){
	if(HAL_OK==HAL_SPI_Receive_DMA(&hspi1,RX_BUFF,sizeof(RX_BUFF))){
	ADC_CS_E();
	rb = RX_BUFF[0];
	rb = rb<<8;
	rb = rb | RX_BUFF[1];
}
}
return rb;
}

/* Function For Writing ADC OFFSET Register ( Future Update)

bool ADC_OFFSET_WR(uint8_t){
uint8_t TX_BUFF[] = {REG_OFFSET_WR,0x00,05};
uint16_t rb = 0x00;
ADC_MODE_IDL();
ADC_CS();
if(HAL_OK==HAL_SPI_Transmit_DMA(&hspi1,TX_BUFF,sizeof(TX_BUFF))){
	ADC_CS_E();
	rb = ADC_IO_RD();
	if(rb==0x0005){
		return 1;
	}
}
return 0;
}  ADC OFFSET Register Not Configured */


/* Function For Reading ADC FULLSCALE Register */

uint16_t ADC_FULLSCALE_RD(void){
uint8_t TX_BUFF[] = {REG_FULLSCALE_RD};
uint8_t RX_BUFF[2]={0};
uint16_t rb = 0x0000;
ADC_CS();
if(HAL_OK== HAL_SPI_Transmit_DMA(&hspi1,TX_BUFF,sizeof(TX_BUFF))){
	if(HAL_OK==HAL_SPI_Receive_DMA(&hspi1,RX_BUFF,sizeof(RX_BUFF))){
	ADC_CS_E();
	rb = RX_BUFF[0];
	rb = rb<<8;
	rb = rb | RX_BUFF[1];
}
}
return rb;
}

/* Function For Writing ADC FULLSCALE Register (Future Update)

bool ADC_FULLSCALE_WR(uint16_t value){
uint8_t TX_BUFF[] = {REG_FULLSCALE_WR,value};
uint16_t rb = 0x0000;
ADC_MODE_IDL();
ADC_CS();
if(HAL_OK==HAL_SPI_Transmit_DMA(&hspi1,TX_BUFF,sizeof(TX_BUFF))){
	ADC_CS_E();
	rb = ADC_IO_RD();
	if(rb==value){
		return 1;
	}
}
return 0;
} ADC FULLSCALE Register Not Configured */



//------------------------------------------------------------------------------
// ADC_HasSample - has the buffer any sample
//------------------------------------------------------------------------------
bool ADC_HasSample(uint8_t channel)
{
  return adcReady[channel];
}

//------------------------------------------------------------------------------
// ADC_GetSample - get next sample from the buffer
//------------------------------------------------------------------------------
uint16_t ADC_GetSample(uint8_t channel)
{
  uint32_t sample=0;
  uint8_t ix;

  for (ix=0; ix<ADC_BUFFER_SIZE; ix++)
    sample += (uint32_t)adcBuffer[ix][channel];
  return (uint16_t)(sample/ADC_BUFFER_SIZE);
}

//------------------------------------------------------------------------------
// ADC_GetValue - get measured value
//------------------------------------------------------------------------------
uint16_t ADC_GetValue(uint8_t channel)
{
  if (ADC_HasSample(channel))
    adcResult[channel] = ADC_GetSample(channel);
  else
    adcResult[channel] = 0;
  return adcResult[channel];
}

