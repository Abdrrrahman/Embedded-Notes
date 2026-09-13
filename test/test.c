#define F_CPU 8000000UL
#include "myUtils/HAL/Button.h"
#include "myUtils/HAL/Led.h"
#include <util/delay.h>

int main(void) {

	Button_Init('A', 2);
	Led_Init('A', 7);

	while(1) {

		if(Button_ReadState('A', 2)) {

			/* 
				Waiting to make sure the bouncing is dumped.
			*/
			_delay_ms(40);


			/* 
				Check again.
			*/
			if(Button_ReadState('A', 2)) {
				Led_Toggle('A', 7);

				while(Button_ReadState('A', 2));
				// Looping doing nothing till the button is released.
			}
		}

		_delay_ms(10);
		// This delay is to give MCU some breath.
	}
}
