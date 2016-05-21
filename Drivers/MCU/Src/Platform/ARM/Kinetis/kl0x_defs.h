#ifndef KL0X_DEFS_H_
#define KL0X_DEFS_H_

/* Include the specific driver headers */
#include "fsl_i2c_master_driver.h"
#include "fsl_i2c_slave_driver.h"
#include "fsl_gpio_driver.h"

typedef union
{
  I2C_Type *    reg;
  uint32_t      instance;
}I2CRegsTypedef_t;

typedef struct
{
  i2c_device_t          device;
  i2c_master_state_t    state;
}I2CConfigTypedef_t;


#endif