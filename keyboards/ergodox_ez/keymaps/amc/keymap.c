#include QMK_KEYBOARD_H
#include "version.h"

extern keymap_config_t keymap_config;

static uint16_t num_lock_sets = 0;
static uint16_t caps_lock_resets = 0;

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

uint32_t default_layer_state_set_user(uint32_t state) {
	uint8_t layer = biton32(state);

	dprintf("default_layer_state_set_user layer=%u\n", layer);

	// default layer 1 blue
	if (layer == 1) {
		ergodox_right_led_3_on();
	} else {
		ergodox_right_led_3_off();
	}

	// default layer 2 green
	if (layer == 2) {
		ergodox_right_led_2_on();
	} else {
		ergodox_right_led_2_off();
	}

	return state;
}

uint32_t layer_state_set_user(uint32_t state) {
	uint8_t layer = biton32(state);

	dprintf("layer_state_set_user layer=%u num_lock_sets=%u caps_lock_resets=%u\n", layer, num_lock_sets, caps_lock_resets);

	// fn layer 3 red
	if (layer == 3) {
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
		if (!led_state.num_lock) {
			SEND_STRING(SS_TAP(X_NUMLOCK));
			num_lock_sets++;
		}
		if (led_state.caps_lock) {
			SEND_STRING(SS_TAP(X_CAPSLOCK));
			caps_lock_resets++;
		}
		lock_check_timer = timer_read();
	}
}
