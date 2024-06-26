# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
LTO_ENABLE = yes
MOUSEKEY_ENABLE = no
RGBLIGHT_ENABLE = no
NKRO_ENABLE = yes

# don't have two devices enabled as hid_listen has no way of differentiating; this is for debug only
COMMAND_ENABLE = yes
CONSOLE_ENABLE = no

REL_PATH = keyboards/hhkb/keymaps/amc

SRC += keymap_gen.c

#SRC += $(KEYBOARD_OUTPUT)/src/keymap_gen.c

#$(foreach V, $(sort $(.VARIABLES)), $(info $V=$(value $V)))

#$(KEYBOARD_OUTPUT)/src/keymap_gen.c: $(REL_PATH)/amc.json
	#bin/qmk json2c --output $(KEYBOARD_OUTPUT)/src/keymap_gen.c $(REL_PATH)/amc.json
