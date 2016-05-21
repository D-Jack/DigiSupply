
#include <stddef.h>
#include <stdbool.h>

#include "i2c.h"

#include "fsl_i2c_master_driver.h"
#include "fsl_i2c_slave_driver.h"
#include "fsl_gpio_driver.h"

void I2C_Init(I2CTypedef_t *i2cObj)
{
  if(NULL == i2cObj)
    return;
  
  I2C_DRV_MasterInit(i2cObj->regs.instance, &i2cObj->config.state);
}

void I2C_DeInit(I2CTypedef_t *i2cObj)
{
  if(NULL == i2cObj)
    return;
  
  I2C_DRV_MasterDeinit(i2cObj->regs.instance);
  
  I2C_DRV_MasterSetBaudRate(i2cObj->regs.instance, &i2cObj->config.device);
}

int8_t I2C_Write(I2CTypedef_t *i2cObj, const uint16_t slaveAddress, const uint8_t *data, const uint32_t length)
{
  if(NULL == i2cObj || length == 0)
    return -1; //todo assign error codes
  
  return (int8_t)I2C_DRV_MasterSendDataBlocking(i2cObj->regs.instance, &i2cObj->config.device, NULL, 0, data, length, 100);
}

int8_t I2C_Read(I2CTypedef_t *i2cObj, const uint16_t slaveAddress, uint8_t *const data, const uint32_t length)
{
  return 0;
}

int8_t I2C_Transfer(I2CTypedef_t *i2cObj, const uint16_t slaveAddress, I2CTransfer_t *const transfer)
{
  if(NULL == i2cObj || NULL == transfer)
    return -1;
  
  switch(transfer->flags)
  {
  case I2CTransfer_TXTX:
    
    if(NULL == transfer->cmd || transfer->cmdLength == 0 || NULL == transfer->txBuf || transfer->txLength == 0)
      return -1;
    
    return (int8_t)I2C_DRV_MasterSendDataBlocking(i2cObj->regs.instance, &i2cObj->config.device, transfer->cmd, transfer->cmdLength, transfer->txBuf, transfer->txLength, 100);
    
    case I2CTransfer_TXRX:
    
    if(NULL == transfer->cmd || transfer->cmdLength == 0 || NULL == transfer->rxBuf || transfer->rxLength == 0)
      return -1;
    
    return (int8_t)I2C_DRV_MasterReceiveDataBlocking(i2cObj->regs.instance, &i2cObj->config.device, transfer->cmd, transfer->cmdLength, transfer->rxBuf, transfer->rxLength, 100);
  }
  
  return 0;
}