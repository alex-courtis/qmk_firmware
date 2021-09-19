#include "km.c"

extern keymap_config_t keymap_config;

void keyboard_post_init_user(void) {
    ergodox_right_led_1_set(LED_BRIGHTNESS_REALLY_LO);
    ergodox_right_led_2_set(LED_BRIGHTNESS_REALLY_LO);
    ergodox_right_led_3_set(LED_BRIGHTNESS_REALLY_LO);

    // https://gitlab.com/interception/linux/plugins/dual-function-keys/-/issues/16
    //keymap_config.nkro = true;
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

    if ((layer_state_is(0) || layer_state_is(1)) && led_state.caps_lock) {

        // red capslock for layer 0 and 1
        ergodox_right_led_1_on();
    } else if (layer_state_is(2) && led_state.num_lock) {

        // red numlock for layer 2
        ergodox_right_led_1_on();
    } else {

        // off elsewhere
        ergodox_right_led_1_off();
    }

    // led_update_kb() (caller) ignores this return
    return true;
}

