#include QMK_KEYBOARD_H

Use branch amc-planck-451e60047 until the upstream issue with planck lighting is resolved.

// bin/qmk json2c ~/src/qmk_firmware/keyboards/planck/keymaps/amc/amc.json
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT_planck_1x2uC(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LCTL, KC_DEL, KC_LGUI, KC_LALT, MO(1), KC_SPC, MO(2), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
        [1] = LAYOUT_planck_1x2uC(LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), LSFT(KC_MINS), LSFT(KC_EQL), LSFT(KC_F1), LSFT(KC_F2), LSFT(KC_F3), LSFT(KC_F4), LSFT(KC_F5), LSFT(KC_F6), LSFT(KC_F7), LSFT(KC_F8), LSFT(KC_F9), LSFT(KC_F10), LSFT(KC_F11), LSFT(KC_F12), LSFT(KC_CAPS), KC_BTN3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LSFT(KC_GRV), LSFT(KC_LBRC), LSFT(KC_RBRC), LSFT(KC_BSLS), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
        [2] = LAYOUT_planck_1x2uC(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_CAPS, KC_BTN3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_GRV, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
        [3] = LAYOUT_planck_1x2uC(RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_NO, KC_NO, KC_NO, EEP_RST, RESET, DEBUG, KC_NO, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, LED_LEVEL)
};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, 1, 2, 3);
}

void keyboard_post_init_user(void) {
    keymap_config.nkro = true;
}
