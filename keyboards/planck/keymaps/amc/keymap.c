#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_planck_1x2uC(
            KC_TAB,       KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,         KC_BSPC,
            KC_ESC,       KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,         KC_J,         KC_K,         KC_L,         KC_SCLN,      KC_ENT,
            KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_RSFT,
            KC_DEL,       LOWER,        KC_RGUI,      KC_RALT,      KC_RCTL,             KC_SPC,              RAISE,        KC_LEFT,      KC_DOWN,      KC_UP,        KC_RGHT
            ),
    [_LOWER] = LAYOUT_planck_1x2uC(
            LSFT(KC_1),   LSFT(KC_2),   LSFT(KC_3),   LSFT(KC_4),   LSFT(KC_5),   LSFT(KC_6),   LSFT(KC_7),   LSFT(KC_8),   LSFT(KC_9),   LSFT(KC_0),   LSFT(KC_MINS),LSFT(KC_EQL),
            LSFT(KC_F1),  LSFT(KC_F2),  LSFT(KC_F3),  LSFT(KC_F4),  LSFT(KC_F5),  LSFT(KC_F6),  KC_NO,        LSFT(KC_GRV), LSFT(KC_LBRC),LSFT(KC_RBRC),LSFT(KC_BSLS),LSFT(KC_QUOT),
            LSFT(KC_F7),  LSFT(KC_F8),  LSFT(KC_F9),  LSFT(KC_F10), LSFT(KC_F11), LSFT(KC_F12), KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
            KC_NO,        KC_TRNS,      KC_NO,        KC_NO,        KC_NO,               KC_NO,               KC_TRNS,      KC_NO,        KC_NO,        KC_NO,        KC_NO
            ),
    [_RAISE] = LAYOUT_planck_1x2uC(
            KC_1,         KC_2,         KC_3,         KC_4,         KC_5,         KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         KC_MINS,      KC_EQL,
            KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,        KC_F6,        KC_NO,        KC_GRV,       KC_LBRC,      KC_RBRC,      KC_BSLS,      KC_QUOT,
            KC_F7,        KC_F8,        KC_F9,        KC_F10,       KC_F11,       KC_F12,       KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
            KC_NO,        KC_TRNS,      KC_NO,        KC_NO,        KC_NO,               KC_NO,               KC_TRNS,      KC_NO,        KC_NO,        KC_NO,        KC_NO
            ),
    [_ADJUST] = LAYOUT_planck_1x2uC(
            RGB_TOG,      RGB_MOD,      RGB_HUI,      RGB_SAI,      RGB_VAI,      RGB_SPI,      KC_NO,        KC_NO,        KC_NO,        EEP_RST,      RESET,        DEBUG,
            KC_NO,        RGB_RMOD,     RGB_HUD,      RGB_SAD,      RGB_VAD,      RGB_SPD,      KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
            KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
            NK_TOGG,      KC_TRNS,      KC_NO,        KC_NO,        KC_NO,               KC_NO,               KC_TRNS,      KC_NO,        KC_NO,        KC_NO,        LED_LEVEL
            ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
