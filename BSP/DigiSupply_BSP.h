#ifndef DIGISUPPLY_BSP_H_
#define DIGISUPPLY_BSP_H_

/* The callback function*/
typedef (void *msgCallback_t)(uint8_t *msg, uin8_t length);

void HardwareInit(void);


void EnableDigiPot(void);
void DisableDigiPot(void);
int8_t SetDigiPotValue(const uint8_t value);
int8_t GetDigiPotValue(uint8_t *const value);

void IncomeMSGCallback_Register(msgCallback_t callback);
void IncomeMSGCallback_UnRegister(msgCallback_t callback);

#endif