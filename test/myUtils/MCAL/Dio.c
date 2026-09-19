// Dio.c

#include "Dio.h"
#include "std_macros.h"
#include <avr/io.h>

// Pin Specific Functions
void Dio_SetPinDirection(uint8_t port, uint8_t pinNum, uint8_t direction) {
    
    switch(port) {

        case 'A':
        case 'a':
            if(direction) {
                SET_BIT(DDRA, pinNum);
            } else {
                CLR_BIT(DDRA, pinNum);
            }
            break;

        case 'B':
        case 'b':
            if(direction) {
                SET_BIT(DDRB, pinNum);
            } else {
                CLR_BIT(DDRB, pinNum);
            }
            break;

        case 'C':
        case 'c':
            if(direction) {
                SET_BIT(DDRC, pinNum);
            } else {
                CLR_BIT(DDRC, pinNum);
            }
            break;

        case 'D':
        case 'd':
            if(direction) {
                SET_BIT(DDRD, pinNum);
            } else {
                CLR_BIT(DDRD, pinNum);
            }
            break;

        default:
            break;
    }
}

void Dio_ConnectPinPullUp(uint8_t port, uint8_t pinNum, uint8_t isPullUp) {
    switch(port) {
        case 'A':
        case 'a':
            if(isPullUp) {
                SET_BIT(PORTA, pinNum);
            } else {
                CLR_BIT(PORTA, pinNum);
            }
            break;

        case 'B':
        case 'b':
            if(isPullUp) {
                SET_BIT(PORTB, pinNum);
            } else {
                CLR_BIT(PORTB, pinNum);
            }
            break;

        case 'C':
        case 'c':
            if(isPullUp) {
                SET_BIT(PORTC, pinNum);
            } else {
                CLR_BIT(PORTC, pinNum);
            }
            break;

        case 'D':
        case 'd':
            if(isPullUp) {
                SET_BIT(PORTD, pinNum);
            } else {
                CLR_BIT(PORTD, pinNum);
            }
            break;

        default:
            break;
    }
}

void Dio_WritePin(uint8_t port, uint8_t pinNum, uint8_t state) {
    
    switch(port) {

        case 'A':
        case 'a':
            if(state) {
                SET_BIT(PORTA, pinNum);
            } else {
                CLR_BIT(PORTA, pinNum);
            }
            break;

        case 'B':
        case 'b':
            if(state) {
                SET_BIT(PORTB, pinNum);
            } else {
                CLR_BIT(PORTB, pinNum);
            }
            break;

        case 'C':
        case 'c':
            if(state) {
                SET_BIT(PORTC, pinNum);
            } else {
                CLR_BIT(PORTC, pinNum);
            }
            break;

        case 'D':
        case 'd':
            if(state) {
                SET_BIT(PORTD, pinNum);
            } else {
                CLR_BIT(PORTD, pinNum);
            }
            break;

        default:
            break;
    }
}


void Dio_TogglePin(uint8_t port, uint8_t pinNum) {

    switch(port) {

        case 'A':
        case 'a':
            TOG_BIT(PORTA, pinNum);
            break;

        case 'B':
        case 'b':
            TOG_BIT(PORTB, pinNum);
            break;

        case 'C':
        case 'c':
            TOG_BIT(PORTC, pinNum);
            break;

        case 'D':
        case 'd':
            TOG_BIT(PORTD, pinNum);
            break;

        default:
            break;
    }
}

uint8_t Dio_ReadPin(uint8_t port, uint8_t pinNum) {

    uint8_t state = 0;

    switch(port) {

        case 'A':
        case 'a':
            state = READ_BIT(PINA, pinNum);
            break;

        case 'B':
        case 'b':
            state = READ_BIT(PINB, pinNum);
            break;

        case 'C':
        case 'c':
            state = READ_BIT(PINC, pinNum);
            break;

        case 'D':
        case 'd':
            state = READ_BIT(PIND, pinNum);
            break;

        default:
            break;
    }

    return state;
}

// Nibble Functions
void Dio_WriteLowerNibble(uint8_t port, uint8_t value) {
    value &= 0x0f;

    switch(port) {
        case 'A':
        case 'a':
            PORTA &= 0xf0;
            PORTA |= value;
            break;

        case 'B':
        case 'b':
            PORTB &= 0xf0;
            PORTB |= value;
            break;

        case 'C':
        case 'c':
            PORTC &= 0xf0;
            PORTC |= value;
            break;

        case 'D':
        case 'd':
            PORTD &= 0xf0;
            PORTD |= value;
            break;

        default:
            break;
    }
}

void Dio_WriteHigherNibble(uint8_t port, uint8_t value) {
    value <<= 4;

    switch (port)
    {
        case 'A':
        case 'a':
            PORTA &= 0x0f;
            PORTA |= value;
            break;
        
        case 'B':
        case 'b':
            PORTB &= 0x0f;
            PORTB |= value;
            break;

        case 'C':
        case 'c':
            PORTC &= 0x0f;
            PORTC |= value;
            break;

        case 'D':
        case 'd':
            PORTD &= 0x0f;
            PORTD |= value;
            break;

        default:
            break;
    }
}

// Port Specific Functions
void Dio_SetPortDirection(uint8_t port, uint8_t direction) {

    switch(port) {

        case 'A':
        case 'a':
            if(direction) {
                DDRA = 0xff;
            } else {
                DDRA = 0x00;
            }
            break;

        case 'B':
        case 'b':
            if(direction) {
                DDRB = 0xff;
            } else {
                DDRB = 0x00;
            }
            break;

        case 'C':
        case 'c':
            if(direction) {
                DDRC = 0xff;
            } else {
                DDRC = 0x00;
            }
            break;

        case 'D':
        case 'd':
            if(direction) {
                DDRD = 0xff;
            } else {
                DDRD = 0x00;
            }
            break;

        default:
            break;
    }

}

void Dio_ConnectPortPullUp(uint8_t port, uint8_t isPullUp){
    switch(port) {
        case 'A':
        case 'a':
            if(isPullUp) {
                PORTA = 0xff;
            } else {
                PORTA = 0x00;
            }
            break;

        case 'B':
        case 'b':
            if(isPullUp) {
                PORTB = 0xff;
            } else {
                PORTB = 0x00;
            }
            break;

        case 'C':
        case 'c':
            if(isPullUp) {
                PORTC = 0xff;
            } else {
                PORTC = 0x00;
            }
            break;

        case 'D':
        case 'd':
            if(isPullUp) {
                PORTD = 0xff;
            } else {
                PORTD = 0x00;
            }
            break;

        default:
            break;
    }
}

void Dio_WritePort(uint8_t port, uint8_t state) {

    switch(port) {

        case 'A':
        case 'a':
            PORTA = state;
            break;

        case 'B':
        case 'b':
            PORTB = state;
            break;

        case 'C':
        case 'c':
            PORTC = state;
            break;

        case 'D':
        case 'd':
            PORTD = state;
            break;

        default:
            break;
    }
}

void Dio_TogglePort(uint8_t port) {

    switch(port) {

        case 'A':
        case 'a':
            PORTA = ~PORTA;
            break;

        case 'B':
        case 'b':
            PORTB = ~PORTB;
            break;

        case 'C':
        case 'c':
           PORTC = ~PORTC;
            break;

        case 'D':
        case 'd':
            PORTD = ~PORTD;
            break;

        default:
            break;
    }
    
}

uint8_t Dio_ReadPort(uint8_t port) {

    uint8_t state = 0;

    switch(port) {

        case 'A':
        case 'a':
            state = PINA;
            break;

        case 'B':
        case 'b':
            state = PINB;
            break;

        case 'C':
        case 'c':
            state = PINC;
            break;

        case 'D':
        case 'd':
            state = PIND;
            break;

        default:
            break;
    }

    return state;

}