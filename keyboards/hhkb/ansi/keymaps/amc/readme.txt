MCU = atmega32u4
BOOTLOADER = atmel-dfu
4848:0001 q.m.k HHKB mod
03eb:2ff4 Atmel Corp. atmega32u4 DFU bootloader

~/.dotfiles/root/usr/lib/udev/rules.d/50-amc-hhkb.rules

util/docker_cmd.sh qmk json2c amc_hhkb/amc.json -o amc_hhkb/km.c
util/docker_build.sh hhkb/ansi:amc:flash

