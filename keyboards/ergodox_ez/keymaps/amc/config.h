/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#ifdef NKRO_ENABLE
#define FORCE_NKRO
#endif

// ergodox_ez default 30
#undef DEBOUNCE
#define DEBOUNCE 20

#define QMK_KEYS_PER_SCAN 4
