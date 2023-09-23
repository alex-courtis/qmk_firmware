// K33B Dactyl Tightly 4x5 keyboard

#pragma once

#define FORCE_NKRO 

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17 // Specify a optional status led by GPIO number which blinks when entering the bootloader

// serial pin for communication betwen halves
#define SERIAL_USART_TX_PIN GP28

// serial method to use
#define SERIAL_PIO_USE_PIO1

// keymatrix size
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { GP0, GP1, GP2, GP3, GP4, GP5 }
#define MATRIX_COL_PINS { GP6, GP7, GP8, GP9, GP10, GP11 }

// diode direction placement
#define DIODE_DIRECTION ROW2COL
