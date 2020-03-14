#include QMK_KEYBOARD_H
#include "version.h"

void keyboard_post_init_user(void) {
	keymap_config.nkro = true;
}
