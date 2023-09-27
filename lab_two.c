// Header files
// From the C library
#include <stdio.h>
// From the Microblaze library
#include "xil_printf.h"
#include "xparameters.h"
#include "mb_interface.h"
// From the local folder
#include "hw_registers.h"

// Prototypes
unsigned char getCharacter();
void putCharacter(unsigned char ch);

 int main() {
	 // Spells my first name in ASCII on LCD screen
	putCharacter(0x43);
	putCharacter(0x6f);
	putCharacter(0x6e);
	putCharacter(0x6e);
	putCharacter(0x6f);
	putCharacter(0x72);
	// Puts in a space
	putCharacter(0x20);
	// Spells my last name in ASCII on LCD screen
	putCharacter(0x48);
	putCharacter(0x65);
	putCharacter(0x61);
	putCharacter(0x72);
	putCharacter(0x64);
	getCharacter();


}

unsigned char getCharacter() {
	unsigned char status, ch;

	// read serial2 status
	status = SERIAL2_STATUS;

	// masking status with 0x01
	status &= RX_FIFO_VALID_DATA;

	while(!status) {
		// read serial2 status
		status = SERIAL2_STATUS;

		// masking status with 0x01
		status &= RX_FIFO_VALID_DATA;
	}

	// read data from the receive buffer
	ch = SERIAL2_RX_FIFO;
	return ch;
}

void putCharacter(unsigned char ch) {
	unsigned char status;

	// read the status register for serial port 2
	status = SERIAL2_STATUS;

	// mask out all bits except for the TX_FIFO_FULL (0x08)
	status &= TX_FIFO_FULL;

	while (status) {
		// read the status register for serial port 2
		status = SERIAL2_STATUS;

		// mask out all bits except for the TX_FIFO_FULL (0x08)
		status &= TX_FIFO_FULL;
	}
	SERIAL2_TX_FIFO = ch;
}
