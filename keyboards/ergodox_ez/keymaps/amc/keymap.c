#include QMK_KEYBOARD_H

// bin/qmk json2c ~/src/qmk_firmware/keyboards/ergodox_ez/keymaps/amc/amc.json
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT_ergodox_pretty(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_NO, TT(1), KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_NO, KC_NO, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_RBRC, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, KC_NO, KC_LSFT, KC_LEFT, KC_RGHT, KC_NO, KC_NO, KC_UP, KC_DOWN, LSFT(KC_INS), KC_NO, KC_TAB, KC_LGUI, KC_RGUI, KC_DEL, KC_F2, KC_F3, KC_BSPC, KC_ESC, KC_F1, KC_F4, KC_ENT, KC_SPC),
        [1] = LAYOUT_ergodox_pretty(KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_NO, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3, KC_PENT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
KC_NO, KC_P0, KC_P0, KC_PDOT, KC_PENT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

//extern keymap_config_t keymap_config;

void keyboard_post_init_user(void) {
    ergodox_right_led_1_set(LED_BRIGHTNESS_REALLY_LO);
    ergodox_right_led_2_set(LED_BRIGHTNESS_REALLY_LO);
    ergodox_right_led_3_set(LED_BRIGHTNESS_REALLY_LO);

    // very curious: this causes dfk to fail
    //keymap_config.nkro = true;
}

void suspend_power_down_user(void) {
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
}

uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);

    // blue
    if (layer == 1)
        ergodox_right_led_3_on();
    else
        ergodox_right_led_3_off();

    return state;
};


bool led_update_user(led_t led_state) {

    // red
    if (led_state.caps_lock)
        ergodox_right_led_1_on();
    else
        ergodox_right_led_1_off();

    // green
    if (led_state.num_lock)
        ergodox_right_led_2_on();
    else
        ergodox_right_led_2_off();

    return true;
}
