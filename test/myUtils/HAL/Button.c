#include "Button.h"

void Button_Init(uint8_t port, uint8_t pinNum) {
  Dio_SetPinDirection(port, pinNum, 0);
}

uint8_t Button_ReadState(uint8_t port, uint8_t pinNum) {
  return Dio_ReadPin(port, pinNum);
}