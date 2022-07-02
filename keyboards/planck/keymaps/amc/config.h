#pragma once

// needed to enable the front teeth and LED_LEVEL
#define ORYX_CONFIGURATOR

// layers in this repo are different to zsa
#define PLANCK_EZ_LED_LOWER 1
#define PLANCK_EZ_LED_RAISE 3
#define PLANCK_EZ_LED_ADJUST 2

#ifdef NKRO_ENABLE
#define FORCE_NKRO
#endif

