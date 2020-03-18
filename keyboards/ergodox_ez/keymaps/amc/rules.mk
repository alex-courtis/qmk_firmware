# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
LINK_TIME_OPTIMIZATION_ENABLE = yes
MOUSEKEY_ENABLE = no
RGBLIGHT_ENABLE = no

# don't have two devices enabled as hid_listen has no way of differentiating; this is for debug only
COMMAND_ENABLE = no
CONSOLE_ENABLE = no

REL_PATH = keyboards/ergodox_ez/keymaps/amc

SRC += $(KEYBOARD_OUTPUT)/src/keymap_gen.c

#$(foreach V, $(sort $(.VARIABLES)), $(info $V=$(value $V)))

$(KEYBOARD_OUTPUT)/src/keymap_gen.c: $(REL_PATH)/amc.json
	bin/qmk json2c --output $(KEYBOARD_OUTPUT)/src/keymap_gen.c $(REL_PATH)/amc.json
