/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#ifdef NKRO_ENABLE
#define FORCE_NKRO
#endif

// ergodox_ez: 30
// #define DEBOUNCE

// qmk: sym_defer_g
// ergodox_ez: sym_eager_pr
// #define DEBOUNCE_TYPE

// qmk: 0
#define QMK_KEYS_PER_SCAN 4

