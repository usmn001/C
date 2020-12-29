

/****** SCCB FUNCTION DEFINITIONS********/


// Includes
#include "stm32f4xx_hal.h"
#include "SCCB.h"
#include "delay.h"


void SCCB_GPIO_Config(void)
{  
		
/* Enable GPIOB  clock */
__GPIOB_CLK_ENABLE();
	
GPIO_InitTypeDef GPIO_InitStruct;
	  
/*Configure GPIO pin : SCCB_SIC_BIT_Pin */
GPIO_InitStruct.Pin = SCCB_SIC_BIT_Pin;
GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
GPIO_InitStruct.Pull = GPIO_PULLUP;
GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
HAL_GPIO_Init(SCCB_SIC_BIT_GPIO_Port, &GPIO_InitStruct);
	
/*Configure GPIO pin : SCCB_SID_BIT_Pin */
GPIO_InitStruct.Pin = SCCB_SID_BIT_Pin;
GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
GPIO_InitStruct.Pull = GPIO_PULLUP;
HAL_GPIO_Init(SCCB_SID_BIT_GPIO_Port, &GPIO_InitStruct);	
}


void SCCB_SID_GPIO_OUTPUT(void)
{
 /* Enable GPIOB  clock */
__GPIOB_CLK_ENABLE();
	
GPIO_InitTypeDef GPIO_InitStruct;
	
/*Configure GPIO pin : SCCB_SID_BIT_Pin */
GPIO_InitStruct.Pin = SCCB_SID_BIT_Pin;
GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
GPIO_InitStruct.Pull = GPIO_NOPULL;
HAL_GPIO_Init(SCCB_SID_BIT_GPIO_Port, &GPIO_InitStruct);		
}


void SCCB_SID_GPIO_INPUT(void)
{
/* Enable GPIOB  clock */
__GPIOB_CLK_ENABLE();
	
GPIO_InitTypeDef GPIO_InitStruct;
	
 /*Configure GPIO pin : SCCB_SID_BIT_Pin */
GPIO_InitStruct.Pin = SCCB_SID_BIT_Pin;
GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
GPIO_InitStruct.Pull = GPIO_NOPULL;
HAL_GPIO_Init(SCCB_SID_BIT_GPIO_Port, &GPIO_InitStruct);	 
}


 
void  SCCB_SID_L(void)                                                    // SID BIT LOW
{
HAL_GPIO_WritePin(GPIOB,SCCB_SID_BIT_Pin,GPIO_PIN_RESET);			
}

void  SCCB_SID_H(void)
{
HAL_GPIO_WritePin(GPIOB,SCCB_SID_BIT_Pin,GPIO_PIN_SET);			             // SID BIT HIGH
}

void  SCCB_SIC_L(void)                                                   // SIC BIT LOW
{
HAL_GPIO_WritePin(GPIOB,SCCB_SIC_BIT_Pin,GPIO_PIN_RESET);			
}

void  SCCB_SIC_H(void)
{
HAL_GPIO_WritePin(GPIOB,SCCB_SIC_BIT_Pin,GPIO_PIN_SET);			             // SIC BIT HIGH
} 
 
 
void startSCCB(void)
{
    SCCB_SID_H();     //数据线高电平
    delay_us(500);

    SCCB_SIC_H();	   //在时钟线高的时候数据线由高至低
    delay_us(500);
 
    SCCB_SID_L();
    delay_us(500);

    SCCB_SIC_L();	 //数据线恢复低电平，单操作函数必要
    delay_us(500);
}

/*
-----------------------------------------------
   功能: stop命令,SCCB的停止信号
   参数: 无
 返回值: 无
-----------------------------------------------
*/
void stopSCCB(void)
{
    SCCB_SID_L();
    delay_us(500);

  	SCCB_SIC_H();	
    delay_us(500);

    SCCB_SID_H();	
    delay_us(500);
}

/*
-----------------------------------------------
   功能: noAck,用于连续读取中的最后一个结束周期
   参数: 无
 返回值: 无
-----------------------------------------------
*/
void noAck(void)
{
	
	SCCB_SID_H();	
	delay_us(500);
	
	SCCB_SIC_H();	
	delay_us(500);
	
	SCCB_SIC_L();	
	delay_us(500);
	
	SCCB_SID_L();	
	delay_us(500);

}


                              /***** SCCB WRITE BYTE*******/

unsigned char SCCBwriteByte(unsigned char m_data)
{
	unsigned char j,tem;

	for(j=0;j<8;j++) //循环8次发送数据
	{
		if((m_data<<j)&0x80)
		{
			SCCB_SID_H();	
		}
		else
		{
			SCCB_SID_L();	
		}
		delay_us(500);
		SCCB_SIC_H();	
		delay_us(500);
		SCCB_SIC_L();	
		delay_us(500);

	}
	delay_us(100);
	SCCB_SID_IN;/*设置SDA为输入*/
	delay_us(500);
	SCCB_SIC_H();	
	delay_us(100);
	if(SCCB_SID_STATE){tem=0;}   //SDA=1发送失败，返回0}
	else {tem=1;}   //SDA=0发送成功，返回1
	SCCB_SIC_L();	
	delay_us(500);	
        SCCB_SID_OUT;/*设置SDA为输出*/

	return (tem);  
}

                         /***** SCCB READ BYTE*******/

unsigned char SCCBreadByte(void)
{
	unsigned char read,j;
	read=0x00;
	
	SCCB_SID_IN;/*设置SDA为输入*/
	delay_us(500);
	for(j=8;j>0;j--) //循环8次接收数据
	{		     
		delay_us(500);
		SCCB_SIC_H();
		delay_us(500);
		read=read<<1;
		if(SCCB_SID_STATE) 
		{
			read=read+1;
		}
		SCCB_SIC_L();
		delay_us(500);
	}	
	return(read);
}


/********* SCCB READ REGISTER**********/


unsigned char rdOV7670Reg(unsigned char regID)
{
	//通过写操作设置寄存器地址
	
	startSCCB();
	
	if(0==SCCBwriteByte(0x42))
	{
		stopSCCB();
		return(0);
	}
	delay_us(100);
  	if(0==SCCBwriteByte(regID))
	{
		stopSCCB();
		return(0);
	}
	stopSCCB();
	
	delay_us(100);
	
	//设置寄存器地址后，才是读
	startSCCB();
	if(0==SCCBwriteByte(0x43))
	{
		stopSCCB();
		return(0);
	}
	delay_us(100);
 	unsigned char regDat=SCCBreadByte();
 	noAck();
 	stopSCCB();
 	return regDat;
}


/********* SCCB WRITE REGISTER**********/

unsigned char wrOV7670Reg(unsigned char regID, unsigned char regDat)
{
	startSCCB();
	if(0==SCCBwriteByte(0x42))
	{
		stopSCCB();
		return(0);
	}
	delay_us(100);
  	if(0==SCCBwriteByte(regID))
	{
		stopSCCB();
		return(0);
	}
	delay_us(100);
  	if(0==SCCBwriteByte(regDat))
	{
		stopSCCB();
		return(0);
	}
  	stopSCCB();
	
  	return(1);
}


/*******END OF FILE********/



