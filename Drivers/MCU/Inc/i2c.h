#ifndef I2C_H_
#define I2C_H_

#include <stddef.h>
#include "mcu_regs.h"

typedef enum
{
  I2CTransfer_TXTX,
  I2CTransfer_TXRX,
}I2CFlags_t;


typedef struct
{
  I2CRegsTypedef_t      regs;
  I2CConfigTypedef_t    config;
}I2CTypedef_t;

typedef struct
{
  I2CFlags_t    flags;
  uint8_t       *cmd;
  uint32_t      cmdLength;
  union
  {
    uint8_t       *txBuf;
    uint8_t       *rxBuf;
  };
  union
  {
    uint32_t      txLength;
    
    uint32_t      rxLength;
  };
}I2CTransfer_t;

/*
* I2C Initialization function
* This function initializes the I2C module
* \param[in] i2cObj - pointer to the I2CTypedef_t structure
*/
extern void I2C_Init(I2CTypedef_t *i2cObj);

/*
* I2C Deinitialization function
* This function deinitializes and resets the I2C module to its default state
* \param[in] i2cObj - pointer to the I2CTypedef_t structure
*/
extern void I2C_DeInit(I2CTypedef_t *i2cObj);

/*
* I2C Enable function
* This function enables the I2C module
* \param[in] i2cObj - pointer to the I2CTypedef_t structure
*/
extern void I2C_Enable(I2CTypedef_t *i2cObj);

/*
* I2C Disable function
* This function disables the I2C module
* \param[in] i2cObj - pointer to the I2CTypedef_t structure
*/
extern void I2C_Disable(I2CTypedef_t *i2cObj);

/*
* I2C Write function
* This function writes a number of bytes to a I2C slave
* \param[in] i2cObj - pointer to the I2CTypedef_t structure
* \param[in] slaveAddress - the slave address of the slave device
* \param[in] data - pointer to the data to be sent
* \param[in] length - the length of the data
* \param[out] the error code
*/
extern int8_t I2C_Write(I2CTypedef_t *i2cObj, const uint16_t slaveAddress, const uint8_t *data, const uint32_t length);

/*
* I2C Write function
* This function writes a number of bytes to a I2C slave
* \param[in] i2cObj - pointer to the I2CTypedef_t structure
* \param[in] slaveAddress - the slave address of the slave device
* \param[in] data - pointer to the received data
* \param[in] length - the length of the data to be received
* \param[out] the error code
*/
extern int8_t I2C_Read(I2CTypedef_t *i2cObj, const uint16_t slaveAddress, uint8_t *const data, const uint32_t length);

extern int8_t I2C_Transfer(I2CTypedef_t *i2cObj, const uint16_t slaveAddress, I2CTransfer_t *transfer);

#endif