#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ergodox_pretty(
            KC_1,        KC_2,        KC_3,        KC_4,        KC_5,        KC_6,        KC_NO,       KC_NO,       KC_7,        KC_8,        KC_9,        KC_0,        KC_MINS,     KC_EQL,
            KC_GRV,      KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,        KC_NO,       KC_NO,       KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        KC_LBRC,
            KC_BSLS,     KC_A,        KC_S,        KC_D,        KC_F,        KC_G,                                  KC_H,        KC_J,        KC_K,        KC_L,        KC_SCLN,     KC_QUOT,
            KC_NO,       KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,        TT(1),       KC_NO,       KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,     KC_NO,
            KC_NO,       KC_PSTE,     KC_LEFT,     KC_RIGHT,    KC_COPY,                                                         KC_RBRC,     KC_UP,       KC_DOWN,     LSFT(KC_INS),KC_NO,
                                                                             KC_TAB,      KC_LALT,     KC_RALT,     KC_DEL,
                                                                                          KC_NO,       KC_RSHIFT,
                                                                KC_BSPC,     KC_ESC,      KC_NO,       KC_NO,       KC_ENT,      KC_SPC
             ),
    [1] = LAYOUT_ergodox_pretty(
            KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_PSCR,     KC_SLCK,     KC_PAUS,     KC_INS,      KC_NO,       KC_NLCK,     KC_PSLS,     KC_PAST,     KC_PMNS,     KC_NO,
            KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_PGUP,     KC_NO,       KC_P7,       KC_P8,       KC_P9,       KC_PPLS,     KC_NO,
            KC_CAPS,     KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                                 KC_HOME,     KC_P4,       KC_P5,       KC_P6,       KC_PPLS,     KC_NO,
            KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_TRNS,     KC_PGDN,     KC_END,      KC_P1,       KC_P2,       KC_P3,       KC_PENT,     KC_NO,
            KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                                                           KC_P0,       KC_P0,       KC_PDOT,     KC_PENT,     KC_NO,
                                                                             KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
                                                                                          KC_NO,       KC_NO,
                                                                KC_TRNS,     KC_TRNS,     KC_NO,       KC_NO,       KC_TRNS,     KC_TRNS
            ),
};

extern keymap_config_t keymap_config;

void keyboard_post_init_user(void) {
    ergodox_right_led_1_set(LED_BRIGHTNESS_LO);
    ergodox_right_led_2_set(LED_BRIGHTNESS_LO);
    ergodox_right_led_3_set(LED_BRIGHTNESS_LO);

    keymap_config.nkro = true;
}

void suspend_power_down_user(void) {
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
}

uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);

    // red
    if (layer == 1) {
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }

    return state;
};

void matrix_scan_user(void) {
    static uint16_t lock_check_timer = 0;
    static led_t led_state;

    if (lock_check_timer == 0) {
        lock_check_timer = timer_read();
    }

    if (timer_elapsed(lock_check_timer) > 500) {
        led_state = host_keyboard_led_state();
        if (!led_state.num_lock)
            SEND_STRING(SS_TAP(X_NUMLOCK));
        if (led_state.caps_lock)
            SEND_STRING(SS_TAP(X_CAPSLOCK));
        lock_check_timer = timer_read();
    }
}
