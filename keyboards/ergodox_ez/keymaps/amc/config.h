/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#define LED_BRIGHTNESS_REALLY_LO 1

// ergodox_ez default 1
#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 1

// ergodox_ez default 30
#undef DEBOUNCE
#define DEBOUNCE 10

#define QMK_KEYS_PER_SCAN 4
