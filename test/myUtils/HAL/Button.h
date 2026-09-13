#ifndef BUTTON_H
#define BUTTON_H

#include "../MCAL/Dio.h"

void Button_Init(uint8_t port, uint8_t pinNum);
uint8_t Button_ReadState(uint8_t port, uint8_t pinNum);

#endif