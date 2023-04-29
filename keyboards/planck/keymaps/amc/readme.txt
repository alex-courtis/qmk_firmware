
MCU = atmega32u4
BOOTLOADER = atmel-dfu
feed:6060 OLKB Planck
0483:df11 STMicroelectronics STM Device in DFU Mode

util/docker_cmd.sh qmk json2c amc_planck/amc.json -o amc_planck/km.c
util/docker_build.sh planck/ez/glow:amc:flash

