# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
LINK_TIME_OPTIMIZATION_ENABLE = yes
COMMAND_ENABLE = yes
MOUSEKEY_ENABLE = no
RGBLIGHT_ENABLE = no

# debug print statements will be preprocessor'd out unless yes
CONSOLE_ENABLE = ye

REL_PATH = keyboards/hhkb/keymaps/amc

SRC += $(KEYBOARD_OUTPUT)/src/keymap_gen.c

#$(foreach V, $(sort $(.VARIABLES)), $(info $V=$(value $V)))

$(KEYBOARD_OUTPUT)/src/keymap_gen.c: $(REL_PATH)/amc.json
	bin/qmk json2c --output $(KEYBOARD_OUTPUT)/src/keymap_gen.c $(REL_PATH)/amc.json
