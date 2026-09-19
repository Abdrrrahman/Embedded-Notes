// Dio.h

#ifndef Dio_H
#define Dio_H

#include <stdint.h>

// Pin Specific Functions
void Dio_SetPinDirection(uint8_t port, uint8_t pinNum, uint8_t direction);
void Dio_ConnectPinPullUp(uint8_t port, uint8_t pinNum, uint8_t isPullUp);
void Dio_WritePin(uint8_t port, uint8_t pinNum, uint8_t state);
void Dio_TogglePin(uint8_t port, uint8_t pinNum);
uint8_t Dio_ReadPin(uint8_t port, uint8_t pinNum);

// Nibble Functions
void Dio_WriteLowerNibble(uint8_t port, uint8_t value);
void Dio_WriteHigherNibble(uint8_t port, uint8_t value);

// Port Specific Functions
void Dio_SetPortDirection(uint8_t port, uint8_t direction);
void Dio_ConnectPortPullUp(uint8_t port, uint8_t isPullUp);
void Dio_WritePort(uint8_t port, uint8_t state);
void Dio_TogglePort(uint8_t port);
uint8_t Dio_ReadPort(uint8_t port);

#endif