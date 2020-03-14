/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#undef TAPPING_TERM
// default 200 keyboards/ergodox_ez/config.h
#define TAPPING_TERM  200

#undef TAPPING_TOGGLE
// default 1 keyboards/ergodox_ez/config.h
#define TAPPING_TOGGLE 1

// recommended by keyboards/ergodox_ez/readme.md with value 4 commonly used in community layouts
#define QMK_KEYS_PER_SCAN 4
// regardless of the above value, the ergodox scans ~800 per second (tested by instrumenting matrix_scan_user) which is far greater than the hhkb's at ~140. Dual function keys on the homen row are only usable with the much greater scan rate.
