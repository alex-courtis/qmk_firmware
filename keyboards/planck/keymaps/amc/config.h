#pragma once

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

// needed to enable the front teeth and LED_LEVEL
#define ORYX_CONFIGURATOR

// layers in this repo are different to zsa
#define PLANCK_EZ_LED_LOWER 1
#define PLANCK_EZ_LED_RAISE 2
#define PLANCK_EZ_LED_ADJUST 3
