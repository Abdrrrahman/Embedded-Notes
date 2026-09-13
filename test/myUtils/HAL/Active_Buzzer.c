#include "Active_Buzzer.h"

void Buzzer_Init(uint8_t port, uint8_t pinNum) {
    Dio_SetPinDirection(port, pinNum, 1);
}

void Buzzer_On(uint8_t port, uint8_t pinNum) {
    Dio_WritePin(port, pinNum, 1);
}

void Buzzer_Off(uint8_t port, uint8_t pinNum) {
    Dio_WritePin(port, pinNum, 0);
}

void Buzzer_Toggle(uint8_t port, uint8_t pinNum) {
    Dio_TogglePin(port, pinNum);
}

void Buzzer_Write(uint8_t port, uint8_t pinNum, uint8_t state) {
    Dio_WritePin(port, pinNum, state);
}

uint8_t Buzzer_ReadStatus(uint8_t port, uint8_t pinNum) {
    return Dio_ReadPin(port, pinNum);
}
