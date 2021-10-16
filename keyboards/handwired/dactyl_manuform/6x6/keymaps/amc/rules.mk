# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
LTO_ENABLE = yes
MOUSEKEY_ENABLE = no
COMMAND_ENABLE = no
NKRO_ENABLE = yes
BOOTLOADER = atmel-dfu

# don't have two devices enabled as hid_listen has no way of differentiating; this is for debug only
CONSOLE_ENABLE = no

