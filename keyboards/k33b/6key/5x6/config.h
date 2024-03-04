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

// Left half recognized by pin pulled high
#define SPLIT_HAND_PIN GP27

// TAP_MILLISEC: 200
#define TAPPING_TERM 200

// DOUBLE_TAP_MILLISEC: 150
#define QUICK_TAP_TERM 150

// consumption, mutex
#define HOLD_ON_OTHER_KEY_PRESS
// #define PERMISSIVE_HOLD

// KEY on release without consumption
// #define RETRO_TAPPING

