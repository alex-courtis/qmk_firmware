#include "km.c"

layer_state_t p_layer_state = 0;

extern keymap_config_t keymap_config;

void keyboard_post_init_user(void) {
    ergodox_right_led_1_set(LED_BRIGHTNESS_REALLY_LO);
    ergodox_right_led_2_set(LED_BRIGHTNESS_REALLY_LO);
    ergodox_right_led_3_set(LED_BRIGHTNESS_REALLY_LO);

    // https://gitlab.com/interception/linux/plugins/dual-function-keys/-/issues/16
    //keymap_config.nkro = true;
}

void suspend_wakeup_init_user(void) {
    layer_state_set_user(p_layer_state);

    // led_update_user is automatically called
}

void suspend_power_down_user(void) {
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
}

layer_state_t layer_state_set_user(layer_state_t layer_state) {
    p_layer_state = layer_state;

    uint8_t layer = biton32(layer_state);

    // clear to prevent stuck keys as per command_common
    clear_keyboard();

    // layer indicator
    switch (layer) {
        case 1:
            // blue - poor man's DFK
            ergodox_right_led_1_off();
            ergodox_right_led_2_off();
            ergodox_right_led_3_on();
            keymap_config.nkro = 1;
            break;
        case 2:
            // green - qwerty gaming
            ergodox_right_led_1_off();
            ergodox_right_led_2_on();
            ergodox_right_led_3_off();
            keymap_config.nkro = 1;
            break;
        case 3:
            // red - reverse dvorak gaming
            ergodox_right_led_1_on();
            ergodox_right_led_2_off();
            ergodox_right_led_3_off();
            keymap_config.nkro = 1;
            break;
        default:
            // no leds - vanilla
            ergodox_right_led_1_off();
            ergodox_right_led_2_off();
            ergodox_right_led_3_off();
            keymap_config.nkro = 1;
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

