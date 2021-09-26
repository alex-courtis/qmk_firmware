#include "km.c"

extern keymap_config_t keymap_config;

void keyboard_post_init_user(void) {
    keymap_config.nkro = true;
}

layer_state_t layer_state_set_user(layer_state_t layer_state) {
    uint8_t layer = biton32(layer_state);

    // layer indicator
    switch (layer) {
        case 1:
            // blue
            ergodox_right_led_2_off();
            ergodox_right_led_3_on();
            break;
        case 2:
            // green
            ergodox_right_led_2_on();
            ergodox_right_led_3_off();
            break;
        default:
            ergodox_right_led_2_off();
            ergodox_right_led_3_off();
            break;
    }

    return layer_state;
};

bool led_update_user(led_t led_state) {

    // red caps
    if (led_state.caps_lock) {
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }

    // led_update_kb() (caller) ignores this return
    return true;
}

