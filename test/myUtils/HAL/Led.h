#ifndef LED_H
#define LED_H

#include "../MCAL/Dio.h"

void Led_Init(uint8_t port, uint8_t pinNum);
void Led_On(uint8_t port, uint8_t pinNum);
void Led_Off(uint8_t port, uint8_t pinNum);
void Led_Toggle(uint8_t port, uint8_t pinNum);
void Led_Write(uint8_t port, uint8_t pinNum, uint8_t state);
uint8_t Led_ReadStatus(uint8_t port, uint8_t pinNum);

#endif