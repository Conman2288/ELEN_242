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
    // Declare variables
    unsigned short leds, switches;

    while (1) {
        switches = SWITCH_DATA;

        if (switches & 0x8000) {
            leds |= 0x0001;
        } else {
            leds &= ~0x0001;
        }

        if (switches & 0x4000) {
            leds |= 0x0002;
        } else {
            leds &= ~0x0002;
        }

        if (switches & 0x2000) {
            leds |= 0x0004;
        } else {
            leds &= ~0x0004;
        }

        if (switches & 0x1000) {
            leds |= 0x0008;
        } else {
            leds &= ~0x0008;
        }

        if (switches & 0x0800) {
            leds |= 0x0010;
        } else {
            leds &= ~0x0010;
        }

        if (switches & 0x0400) {
            leds |= 0x0020;
        } else {
            leds &= ~0x0020;
        }

        if (switches & 0x0200) {
            leds |= 0x0040;
        } else {
            leds &= ~0x0040;
        }

        if (switches & 0x0100) {
            leds |= 0x0080;
        } else {
            leds &= ~0x0080;
        }

        if (switches & 0x0080) {
            leds |= 0x0100;
        } else {
            leds &= ~0x0100;
        }

        if (switches & 0x0040) {
            leds |= 0x0200;
        } else {
            leds &= ~0x0200;
        }

        if (switches & 0x0020) {
            leds |= 0x0400;
        } else {
            leds &= ~0x0400;
        }

        if (switches & 0x0010) {
            leds |= 0x0800;
        } else {
            leds &= ~0x0800;
        }

        if (switches & 0x0008) {
            leds |= 0x1000;
        } else {
            leds &= ~0x1000;
        }

        if (switches & 0x0004) {
            leds |= 0x2000;
        } else {
            leds &= ~0x2000;
        }

        if (switches & 0x0002) {
            leds |= 0x4000;
        } else {
            leds &= ~0x4000;
        }

        if (switches & 0x0001) {
            leds |= 0x8000;
        } else {
            leds &= ~0x8000;
        }

        LED_DATA = leds;
    }
}
