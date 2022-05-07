MCU = atmega32u4
BOOTLOADER = atmel-dfu
feed:6060 OLKB Planck
0483:df11 STMicroelectronics STM Device in DFU Mode

dfu-util:
/usr/lib/udev/rules.d/60-dfuse.rules

qmk json2c amc.json > km.c
util/docker_build.sh planck/ez/glow:amc:flash

