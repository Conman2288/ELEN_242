// Header files
// From the C library
#include <stdio.h>
// From the Microblaze library
#include "xil_printf.h"
#include "xparameters.h"
#include "mb_interface.h"
// From the local folder
#include "hw_registers.h"

int main() {
	//Declare variables
	unsigned short leds, switches;

	while(1) {
		switches = SWITCH_DATA;

		if (switches & 0x0001) {
			leds = 0xffff;
		}
		else {
			leds = 0x0000;
		}
		LED_DATA = leds;
	}
}

