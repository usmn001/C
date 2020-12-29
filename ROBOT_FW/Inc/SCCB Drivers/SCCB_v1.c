

/****** SCCB FUNCTION DEFINITIONS********/


// Includes
#include "SCCB.h"

/**
  * @brief  This function handles SCCB Communication Timeout.
  * @param  hi2c: pointer to a I2C_HandleTypeDef structure that contains
  *         the configuration information for I2C module
  * @param  Flag: specifies the I2C flag to check.
  * @param  Status: The new Flag status (SET or RESET).
  * @param  Timeout: Timeout duration
  * @retval HAL status
  */
static HAL_StatusTypeDef SCCB_WaitOnFlagUntilTimeout(I2C_HandleTypeDef *hi2c, uint32_t Flag, FlagStatus Status, uint32_t Timeout)
{
  uint32_t tickstart = 0;

  /* Get tick */
  tickstart = HAL_GetTick();

  /* Wait until flag is set */
  if(Status == RESET)
  {
    while(__HAL_I2C_GET_FLAG(hi2c, Flag) == RESET)
    {
      /* Check for the Timeout */
      if(Timeout != HAL_MAX_DELAY)
      {
        if((Timeout == 0)||((HAL_GetTick() - tickstart ) > Timeout))
        {
          hi2c->State= HAL_I2C_STATE_READY;

          /* Process Unlocked */
          __HAL_UNLOCK(hi2c);

          return HAL_TIMEOUT;
        }
      }
    }
  }
  else
  {
    while(__HAL_I2C_GET_FLAG(hi2c, Flag) != RESET)
    {
      /* Check for the Timeout */
      if(Timeout != HAL_MAX_DELAY)
      {
        if((Timeout == 0)||((HAL_GetTick() - tickstart ) > Timeout))
        {
          hi2c->State= HAL_I2C_STATE_READY;

          /* Process Unlocked */
          __HAL_UNLOCK(hi2c);

          return HAL_TIMEOUT;
        }
      }
    }
  }
  return HAL_OK;
}
/**
  * @brief  Checks if target device is ready for communication.
  * @note   This function is used with Memory devices
  * @param  hi2c: pointer to a I2C_HandleTypeDef structure that contains
  *         the configuration information for I2C module
  * @param  DevAddress: Target device address
  * @param  Trials: Number of trials
  * @param  Timeout: Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCCB_IsDeviceReady(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint32_t Trials, uint32_t Timeout)
{
  uint32_t tickstart = 0, tmp1 = 0, tmp2 = 0, tmp3 = 0, I2C_Trials = 1;

  if(hi2c->State == HAL_I2C_STATE_READY)
  {
    /* Wait until BUSY flag is reset */
    if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_BUSY, SET, SCCB_TIMEOUT_BUSY_FLAG) != HAL_OK)
    {
      return HAL_BUSY;
    }

    /* Process Locked */
    __HAL_LOCK(hi2c);
    
    /* Disable Pos */
    hi2c->Instance->CR1 &= ~I2C_CR1_POS;
    hi2c->State = HAL_I2C_STATE_BUSY;
    hi2c->ErrorCode = HAL_I2C_ERROR_NONE;

    do
    {
      /* Generate Start */
      hi2c->Instance->CR1 |= I2C_CR1_START;

      /* Wait until SB flag is set */
      if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_SB, RESET, Timeout) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }

      /* Send slave address */
      hi2c->Instance->DR = I2C_7BIT_ADD_WRITE(DevAddress);

      /* Wait until ADDR or AF flag are set */
      /* Get tick */
      tickstart = HAL_GetTick();

      tmp1 = __HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_ADDR);
      tmp2 = __HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_AF);
      tmp3 = hi2c->State;
      while((tmp1 == RESET) && (tmp2 == RESET) && (tmp3 != HAL_I2C_STATE_TIMEOUT))
      {
        if((Timeout == 0)||((HAL_GetTick() - tickstart ) > Timeout))
        {
          hi2c->State = HAL_I2C_STATE_TIMEOUT;
        }
        tmp1 = __HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_ADDR);
        tmp2 = __HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_AF);
        tmp3 = hi2c->State;
      }
      hi2c->State = HAL_I2C_STATE_READY;

      /* Check if the ADDR flag has been set */
      if(__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_ADDR) == RESET)
      {
        /* Generate Stop */
        hi2c->Instance->CR1 |= I2C_CR1_STOP;

        /* Clear ADDR Flag */
        __HAL_I2C_CLEAR_ADDRFLAG(hi2c);

        /* Wait until BUSY flag is reset */
        if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_BUSY, SET, SCCB_TIMEOUT_BUSY_FLAG) != HAL_OK)
        {
          return HAL_TIMEOUT;
        }
        hi2c->State = HAL_I2C_STATE_READY;
        /* Process Unlocked */
        __HAL_UNLOCK(hi2c);
        return HAL_OK;
      }
      else
      {
        /* Generate Stop */
        hi2c->Instance->CR1 |= I2C_CR1_STOP;

        /* Clear AF Flag */
        __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_AF);

        /* Wait until BUSY flag is reset */
        if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_BUSY, SET, SCCB_TIMEOUT_BUSY_FLAG) != HAL_OK)
        {
          return HAL_TIMEOUT;
        }

      }
    }while(I2C_Trials++ < Trials);

    hi2c->State = HAL_I2C_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    return HAL_ERROR;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  This function handles I2C Communication Timeout for Master addressing phase.
  * @param  hi2c: pointer to a I2C_HandleTypeDef structure that contains
  *         the configuration information for I2C module
  * @param  Flag: specifies the I2C flag to check.
  * @param  Timeout: Timeout duration
  * @retval HAL status
  */
static HAL_StatusTypeDef SCCB_WaitOnMasterAddressFlagUntilTimeout(I2C_HandleTypeDef *hi2c, uint32_t Flag, uint32_t Timeout)
{
  uint32_t tickstart = 0;

  /* Get tick */
  tickstart = HAL_GetTick();

 
	
	/*
	while(__HAL_I2C_GET_FLAG(hi2c, Flag) == RESET)
  {
    if(__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_AF) == SET  )
    {
      // Generate Stop 
      hi2c->Instance->CR1 |= I2C_CR1_STOP;

      // Clear AF Flag 
      __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_AF);

      hi2c->ErrorCode = HAL_I2C_ERROR_AF;
      hi2c->State= HAL_I2C_STATE_READY;

      // Process Unlocked 
      __HAL_UNLOCK(hi2c);

      return HAL_ERROR;
    }*/

    /*// Check for the Timeout 
   // if(Timeout != HAL_MAX_DELAY)
    {
      if((Timeout == 0)||((HAL_GetTick() - tickstart ) > Timeout))
      {
        hi2c->State= HAL_I2C_STATE_READY;

        // Process Unlocked 
        __HAL_UNLOCK(hi2c);

        return HAL_TIMEOUT;
      }
    }
  }*/
  return HAL_OK;
}

                          /**********SCCB REQUEST MEMORY READ FUNCTION************/

/**
  * @brief  Master sends target device address followed by internal memory address for read request.
  * @param  hi2c: pointer to a I2C_HandleTypeDef structure that contains
  *         the configuration information for I2C module
  * @param  DevAddress: Target device address
  * @param  MemAddress: Internal memory address
  * @param  MemAddSize: Size of internal memory address
  * @param  Timeout: Timeout duration
  * @retval HAL status
  */
static HAL_StatusTypeDef SCCB_RequestMemoryRead(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint32_t Timeout)
{
  /* Enable Peripheral */
  hi2c->Instance->CR1 |= I2C_CR1_PE;

  /* Generate Start */
  hi2c->Instance->CR1 |= I2C_CR1_START;

  /* Wait until SB flag is set */
  if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_SB, RESET, Timeout) != HAL_OK)
  {
    return HAL_TIMEOUT;
  }

  // Send slave address 
  hi2c->Instance->DR = I2C_7BIT_ADD_WRITE(DevAddress);

  /*Wait until ADDR flag is reset 	
  if(SCCB_WaitOnMasterAddressFlagUntilTimeout(hi2c, I2C_FLAG_ADDR, Timeout) != HAL_OK)
  {
    if(hi2c->ErrorCode == HAL_I2C_ERROR_AF)
    {
      return HAL_ERROR;
    }
    else
    {
      return HAL_TIMEOUT;
    }
  }*/

  // Clear ADDR flag 
 // __HAL_I2C_CLEAR_ADDRFLAG(hi2c);

  /* Wait until TXE flag is set 
  if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_TXE, RESET, Timeout) != HAL_OK)
  {
    return HAL_TIMEOUT;
  }*/

  /* If Memory address size is 8Bit */
  if(MemAddSize == I2C_MEMADD_SIZE_8BIT)
  {
    /* Send Memory Address */
    hi2c->Instance->DR = I2C_MEM_ADD_LSB(MemAddress);
  }
  /* If Memory address size is 16Bit */
  else
  {
    /* Send MSB of Memory Address */
    hi2c->Instance->DR = I2C_MEM_ADD_MSB(MemAddress);

    /* Wait until TXE flag is set */ 
    if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_TXE, RESET, Timeout) != HAL_OK)
    {
      return HAL_TIMEOUT;
    }

    /* Send LSB of Memory Address */
    hi2c->Instance->DR = I2C_MEM_ADD_LSB(MemAddress);
  }

  /* Wait until TXE flag is set */ 
  if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_TXE, RESET, Timeout) != HAL_OK)
  {
    return HAL_TIMEOUT;
  }

  /* Generate Restart */
  hi2c->Instance->CR1 |= I2C_CR1_START;

  /* Wait until SB flag is set */
  if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_SB, RESET, Timeout) != HAL_OK)
  {
    return HAL_TIMEOUT;
  }

  /* Send slave address */
  hi2c->Instance->DR = I2C_7BIT_ADD_READ(DevAddress);

  /* Wait until ADDR flag is set 
  if(SCCB_WaitOnMasterAddressFlagUntilTimeout(hi2c, I2C_FLAG_ADDR, Timeout) != HAL_OK)
  {
    if(hi2c->ErrorCode == HAL_I2C_ERROR_AF)
    {
      return HAL_ERROR;
    }
    else
    {
      return HAL_TIMEOUT;
    }
  }*/

  return HAL_OK;
}





/**************SCCB MEMORY READ FUNCTION*********************/

/**
  * @brief  Read an amount of data in blocking mode from a specific memory address
  * @param  hi2c: pointer to a I2C_HandleTypeDef structure that contains
  *         the configuration information for I2C module
  * @param  DevAddress: Target device address
  * @param  MemAddress: Internal memory address
  * @param  MemAddSize: Size of internal memory address
  * @param  pData: Pointer to data buffer
  * @param  Size: Amount of data to be sent
  * @param  Timeout: Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCCB_Mem_Read(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  /* Check the parameters */
  assert_param(IS_I2C_MEMADD_SIZE(MemAddSize));

  if(hi2c->State == HAL_I2C_STATE_READY)
  {
    if((pData == NULL) || (Size == 0))
    {
      return  HAL_ERROR;
    }

    /* Wait until BUSY flag is reset */
    if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_BUSY, SET, SCCB_TIMEOUT_BUSY_FLAG) != HAL_OK)
    {
      return HAL_BUSY;
    }

    /* Process Locked */
    __HAL_LOCK(hi2c);
    
    /* Enable ACK & Pos &*/
		//hi2c->Instance->CR1 &= 0x00000;
    hi2c->Instance->CR1 |= I2C_CR1_ACK;
		hi2c->Instance->CR1 |= I2C_CR1_POS;
    hi2c->State = HAL_I2C_STATE_MEM_BUSY_RX;
    hi2c->ErrorCode = HAL_I2C_ERROR_NONE;

    // Send Slave Address and Memory Address 			
		if(SCCB_RequestMemoryRead(hi2c, DevAddress, MemAddress, MemAddSize, Timeout) != HAL_OK)
    {
      if(hi2c->ErrorCode == HAL_I2C_ERROR_AF)
      {
        // Process Unlocked 
        __HAL_UNLOCK(hi2c);
        return HAL_ERROR;
      }
      else
      {
        // Process Unlocked 
        __HAL_UNLOCK(hi2c);
        return HAL_TIMEOUT;
      }
    }

    if(Size == 1)
    {
      /* Disable Acknowledge */
      hi2c->Instance->CR1 &= ~I2C_CR1_ACK;

      /* Clear ADDR flag */
      __HAL_I2C_CLEAR_ADDRFLAG(hi2c);

      /* Generate Stop */
      hi2c->Instance->CR1 |= I2C_CR1_STOP;
    }
    else if(Size == 2)
    {
      /* Disable Acknowledge */
      hi2c->Instance->CR1 &= ~I2C_CR1_ACK;

      /* Enable Pos */
      hi2c->Instance->CR1 |= I2C_CR1_POS;

      /* Clear ADDR flag */
      __HAL_I2C_CLEAR_ADDRFLAG(hi2c);
    }
    else
    {
      /* Clear ADDR flag */
      __HAL_I2C_CLEAR_ADDRFLAG(hi2c);
    }

    while(Size > 0)
    {
      if(Size <= 3)
      {
        /* One byte */
        if(Size== 1)
        {
          /* Wait until RXNE flag is set */
          if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_RXNE, RESET, Timeout) != HAL_OK)
          {
            return HAL_TIMEOUT;
          }

          /* Read data from DR */
          (*pData++) = hi2c->Instance->DR;
          Size--;
        }
        /* Two bytes */
        else if(Size == 2)
        {
          /* Wait until BTF flag is set */
          if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_BTF, RESET, Timeout) != HAL_OK)
          {
            return HAL_TIMEOUT;
          }

          /* Generate Stop */
          hi2c->Instance->CR1 |= I2C_CR1_STOP;

          /* Read data from DR */
          (*pData++) = hi2c->Instance->DR;
          Size--;

          /* Read data from DR */
          (*pData++) = hi2c->Instance->DR;
          Size--;
        }
        /* 3 Last bytes */
        else
        {
          /* Wait until BTF flag is set */
          if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_BTF, RESET, Timeout) != HAL_OK)
          {
            return HAL_TIMEOUT;
          }

          /* Disable Acknowledge */
          hi2c->Instance->CR1 &= ~I2C_CR1_ACK;

          /* Read data from DR */
          (*pData++) = hi2c->Instance->DR;
          Size--;

          /* Wait until BTF flag is set */
          if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_BTF, RESET, Timeout) != HAL_OK)
          {
            return HAL_TIMEOUT;
          }

          /* Generate Stop */
          hi2c->Instance->CR1 |= I2C_CR1_STOP;

          /* Read data from DR */
          (*pData++) = hi2c->Instance->DR;
          Size--;

          /* Read data from DR */
          (*pData++) = hi2c->Instance->DR;
          Size--;
        }
      }
      else
      {
        /* Wait until RXNE flag is set */
        if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_RXNE, RESET, Timeout) != HAL_OK)
        {
          return HAL_TIMEOUT;
        }

        /* Read data from DR */
        (*pData++) = hi2c->Instance->DR;
        Size--;

        if(__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_BTF) == SET)
        {
          /* Read data from DR */
          (*pData++) = hi2c->Instance->DR;
          Size--;
        }
      }
    }

    hi2c->State = HAL_I2C_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}




/**********SCCB REQUEST MEMORY WRITE FUNCTION**********/



/**
  * @brief  Master sends target device address followed by internal memory address for write request.
  * @param  hi2c: pointer to a I2C_HandleTypeDef structure that contains
  *         the configuration information for I2C module
  * @param  DevAddress: Target device address
  * @param  MemAddress: Internal memory address
  * @param  MemAddSize: Size of internal memory address
  * @param  Timeout: Timeout duration
  * @retval HAL status
  */
static HAL_StatusTypeDef SCCB_RequestMemoryWrite(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint32_t Timeout)
{
  /* Generate Start */
  hi2c->Instance->CR1 |= I2C_CR1_START;

  /* Wait until SB flag is set */
  if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_SB, RESET, Timeout) != HAL_OK)
  {
    return HAL_TIMEOUT;
  }

  /* Send slave address */
  hi2c->Instance->DR = I2C_7BIT_ADD_WRITE(DevAddress);

  /* Wait until ADDR flag is set */
  if(SCCB_WaitOnMasterAddressFlagUntilTimeout(hi2c, I2C_FLAG_ADDR, Timeout) != HAL_OK)
  {
    if(hi2c->ErrorCode == HAL_I2C_ERROR_AF)
    {
      return HAL_ERROR;
    }
    else
    {
      return HAL_TIMEOUT;
    }
  }

  /* Clear ADDR flag */
  __HAL_I2C_CLEAR_ADDRFLAG(hi2c);

  /* Wait until TXE flag is set */
  if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_TXE, RESET, Timeout) != HAL_OK)
  {
    return HAL_TIMEOUT;
  }

  /* If Memory address size is 8Bit */
  if(MemAddSize == I2C_MEMADD_SIZE_8BIT)
  {
    /* Send Memory Address */
    hi2c->Instance->DR = I2C_MEM_ADD_LSB(MemAddress);
  }
  /* If Memory address size is 16Bit */
  else
  {
    /* Send MSB of Memory Address */
    hi2c->Instance->DR = I2C_MEM_ADD_MSB(MemAddress);

    /* Wait until TXE flag is set */
    if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_TXE, RESET, Timeout) != HAL_OK)
    {
      return HAL_TIMEOUT;
    }

    /* Send LSB of Memory Address */
    hi2c->Instance->DR = I2C_MEM_ADD_LSB(MemAddress);
  }

  return HAL_OK;
}



/************** SCCB WRITE FUNCTION*****************/


/**
  * @brief  Write an amount of data in blocking mode to a specific memory address
  * @param  hi2c: pointer to a I2C_HandleTypeDef structure that contains
  *         the configuration information for I2C module
  * @param  DevAddress: Target device address
  * @param  MemAddress: Internal memory address
  * @param  MemAddSize: Size of internal memory address
  * @param  pData: Pointer to data buffer
  * @param  Size: Amount of data to be sent
  * @param  Timeout: Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SCCB_Mem_Write(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  /* Check the parameters */
  assert_param(IS_I2C_MEMADD_SIZE(MemAddSize));

  if(hi2c->State == HAL_I2C_STATE_READY)
  {
    if((pData == NULL) || (Size == 0))
    {
      return  HAL_ERROR;
    }

    /* Wait until BUSY flag is reset */
    if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_BUSY, SET, SCCB_TIMEOUT_BUSY_FLAG) != HAL_OK)
    {
      return HAL_BUSY;
    }

    /* Process Locked */
    __HAL_LOCK(hi2c);
    
    /* Disable Pos */
    hi2c->Instance->CR1 &= ~I2C_CR1_POS;

    hi2c->State = HAL_I2C_STATE_MEM_BUSY_TX;
    hi2c->ErrorCode = HAL_I2C_ERROR_NONE;

    /* Send Slave Address and Memory Address */
    if(SCCB_RequestMemoryWrite(hi2c, DevAddress, MemAddress, MemAddSize, Timeout) != HAL_OK)
    {
      if(hi2c->ErrorCode == HAL_I2C_ERROR_AF)
      {
        /* Process Unlocked */
        __HAL_UNLOCK(hi2c);
        return HAL_ERROR;
      }
      else
      {
        /* Process Unlocked */
        __HAL_UNLOCK(hi2c);
        return HAL_TIMEOUT;
      }
    }

    while(Size > 0)
    {
      /* Wait until TXE flag is set */
      if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_TXE, RESET, Timeout) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }

      /* Write data to DR */
      hi2c->Instance->DR = (*pData++);
      Size--;

      if((__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_BTF) == SET) && (Size != 0))
      {
        /* Write data to DR */
        hi2c->Instance->DR = (*pData++);
        Size--;
      }
    }

    /* Wait until TXE flag is set */
    if(SCCB_WaitOnFlagUntilTimeout(hi2c, I2C_FLAG_TXE, RESET, Timeout) != HAL_OK)
    {
      return HAL_TIMEOUT;
    }

    /* Generate Stop */
    hi2c->Instance->CR1 |= I2C_CR1_STOP;

    hi2c->State = HAL_I2C_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}






/*******END OF FILE********/



