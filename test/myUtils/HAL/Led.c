#include "Led.h"

void Led_Init(uint8_t port, uint8_t pinNum) {
    Dio_SetPinDirection(port, pinNum, 1);
}

void Led_On(uint8_t port, uint8_t pinNum) {
    Dio_WritePin(port, pinNum, 1);
}

void Led_Off(uint8_t port, uint8_t pinNum) {
    Dio_WritePin(port, pinNum, 0);
}

void Led_Toggle(uint8_t port, uint8_t pinNum) {
    Dio_TogglePin(port, pinNum);
}

void Led_Write(uint8_t port, uint8_t pinNum, uint8_t state) {
    Dio_WritePin(port, pinNum, state);
}

uint8_t Led_ReadStatus(uint8_t port, uint8_t pinNum) {
    return Dio_ReadPin(port, pinNum);
}
