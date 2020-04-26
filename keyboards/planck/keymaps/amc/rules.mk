SRC += muse.c
# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
LINK_TIME_OPTIMIZATION_ENABLE = yes
MOUSEKEY_ENABLE = no
WEBUSB_ENABLE = yes
ORYX_ENABLE = yes
COMMAND_ENABLE = no

# don't have two devices enabled as hid_listen has no way of differentiating; this is for debug only
CONSOLE_ENABLE = no
