// K33B Dactyl Tightly 4x5 keyboard

#pragma once

#define FORCE_NKRO

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17 // Specify a optional status led by GPIO number which blinks when entering the bootloader

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP0
#define I2C1_SCL_PIN GP1

// keymatrix size
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { GP21, GP20, GP19, GP18, GP17, GP16 }
#define MATRIX_COL_PINS { GP15, GP14, GP13, GP12, GP11, GP10 }

// diode direction placement
#define DIODE_DIRECTION COL2ROW

