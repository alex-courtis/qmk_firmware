#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ergodox_pretty(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_COPY, KC_NO, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_PSTE, KC_NO, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_BSLS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, TT(2), KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, KC_NO, KC_PSTE, KC_COPY, KC_LEFT, KC_RGHT, KC_UP, KC_DOWN, KC_RBRC, LSFT(KC_INS), KC_NO, LCTL_T(KC_TAB), KC_LALT, KC_RALT, RCTL_T(KC_DEL), KC_NO, KC_NO, LSFT_T(KC_BSPC), LGUI_T(KC_ESC), KC_NO, KC_NO, RCTL_T(KC_ENT), RSFT_T(KC_SPC)),
	[1] = LAYOUT_ergodox_pretty(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LSFT_T(KC_A), LCTL_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F), KC_TRNS, KC_TRNS, RGUI_T(KC_J), RALT_T(KC_K), RCTL_T(KC_L), RSFT_T(KC_SCLN), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB, KC_NO, KC_NO, KC_DEL, KC_NO, KC_NO, KC_BSPC, KC_ESC, KC_NO, KC_NO, KC_ENT, KC_SPC),
	[2] = LAYOUT_ergodox_pretty(KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_SLCK, KC_PAUS, KC_INS, KC_NO, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGUP, KC_NO, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_NO, KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_PGDN, KC_END, KC_P1, KC_P2, KC_P3, KC_PENT, KC_NO, DF(0), DF(1), KC_NO, KC_NO, KC_NO, KC_P0, KC_P0, KC_PDOT, KC_PENT, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS)
};

extern keymap_config_t keymap_config;

static uint16_t num_lock_sets = 0;
static uint16_t caps_lock_resets = 0;

static uint8_t default_layer = 0;

#ifdef MODIFIER_SIDE_SQUISHING
static uint16_t left_squishes = 0;
static uint16_t right_squishes = 0;

#define LMODS (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_LCTRL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI))
#define L_ROW_LOW 1
#define L_ROW_HIGH 5
#define L_COL_LOW 0
#define L_COL_HIGH 3

#define RMODS (MOD_BIT(KC_RSHIFT) | MOD_BIT(KC_RCTRL) | MOD_BIT(KC_RALT) | MOD_BIT(KC_RGUI))
#define R_ROW_LOW 8
#define R_ROW_HIGH 12
#define R_COL_LOW 0
#define R_COL_HIGH 3

#endif // MODIFIER_SIDE_SQUISHING

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

	dprintf("layer_state_set_user layer=%u default_layer=%u\n", layer, default_layer);
	dprintf("                     num_lock_sets=%u caps_lock_resets=%u\n", num_lock_sets, caps_lock_resets);
#ifdef MODIFIER_SIDE_SQUISHING
	dprintf("                     left_squishes=%u right_squishes=%u\n", left_squishes, right_squishes);
#endif // MODIFIER_SIDE_SQUISHING

	// fn layer 2 red
	if (layer == 2) {
		ergodox_right_led_1_on();
	} else {
		ergodox_right_led_1_off();
	}

	return state;
};

#ifdef MODIFIER_SIDE_SQUISHING
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
#endif // MODIFIER_SIDE_SQUISHING

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
