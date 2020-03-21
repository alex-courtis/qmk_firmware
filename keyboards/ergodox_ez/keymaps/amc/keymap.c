#include QMK_KEYBOARD_H
#include "version.h"

extern keymap_config_t keymap_config;

static uint16_t num_lock_sets = 0;
static uint16_t caps_lock_resets = 0;

static uint16_t left_squishes = 0;
static uint16_t right_squishes = 0;

static uint8_t default_layer = 0;

#define LMODS (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_LCTRL) | MOD_BIT(KC_LALT))
#define L_ROW_LOW 1
#define L_ROW_HIGH 5
#define L_COL_LOW 0
#define L_COL_HIGH 3

#define RMODS (MOD_BIT(KC_RSHIFT) | MOD_BIT(KC_RCTRL) | MOD_BIT(KC_RALT))
#define R_ROW_LOW 8
#define R_ROW_HIGH 12
#define R_COL_LOW 0
#define R_COL_HIGH 3


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
	default_layer = biton32(state);

	dprintf("default_layer_state_set_user default_layer=%u\n", default_layer);

	// default layer 1 blue
	if (default_layer == 1) {
		ergodox_right_led_3_on();
	} else {
		ergodox_right_led_3_off();
	}

	return state;
}

uint32_t layer_state_set_user(uint32_t state) {
	uint8_t layer = biton32(state);

	dprintf("layer_state_set_user layer=%u default_layer=%u num_lock_sets=%u caps_lock_resets=%u left_squishes=%u right_squishes=%u\n", layer, default_layer, num_lock_sets, caps_lock_resets, left_squishes, right_squishes);

	// fn layer 2 red
	if (layer == 2) {
		ergodox_right_led_1_on();
	} else {
		ergodox_right_led_1_off();
	}

	return state;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	static uint8_t mods;

	if (default_layer != 0) {
		return true;
	}

	mods = get_mods();

	// let things through when we have mods on both sides
	// this is needed for things like command
	// finer filtering might be possible, but probably not needed
	if (mods & LMODS && mods & RMODS) {
		return true;
	}

	// todo: let other modifiers through via LSFT_T and friends

	if (mods & LMODS &&
			record->event.key.col >= L_COL_LOW && record->event.key.col <= L_COL_HIGH &&
			record->event.key.row >= L_ROW_LOW && record->event.key.row <= L_ROW_HIGH) {
		left_squishes++;
		return false;
	}

	if (mods & RMODS &&
			record->event.key.col >= R_COL_LOW && record->event.key.col <= R_COL_HIGH &&
			record->event.key.row >= R_ROW_LOW && record->event.key.row <= R_ROW_HIGH) {
		right_squishes++;
		return false;
	}

	return true;
}

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
