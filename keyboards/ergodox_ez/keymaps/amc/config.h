/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

// ergodox_ez default 1
#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 2

// ergodox_ez default 30
#undef DEBOUNCE
#define DEBOUNCE 5

// recommended by keyboards/ergodox_ez/readme.md with value 4 commonly used in community layouts
#define QMK_KEYS_PER_SCAN 4
