#ifndef ACTIVE_BUZZER_H
#define ACTIVE_BUZZER_H

#include "../MCAL/Dio.h"

void Buzzer_Init(uint8_t port, uint8_t pinNum);
void Buzzer_On(uint8_t port, uint8_t pinNum);
void Buzzer_Off(uint8_t port, uint8_t pinNum);
void Buzzer_Toggle(uint8_t port, uint8_t pinNum);
void Buzzer_Write(uint8_t port, uint8_t pinNum, uint8_t state);
uint8_t Buzzer_ReadStatus(uint8_t port, uint8_t pinNum);

#endif