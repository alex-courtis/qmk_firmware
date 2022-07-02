MCU = atmega32u4
BOOTLOADER = atmel-dfu
feed:6060 OLKB Planck
0483:df11 STMicroelectronics STM Device in DFU Mode

docker image qmkfm/qmk_cli /lib/udev/rules.d/60-dfu-util.rules

util/docker_cmd.sh qmk json2c amc_planck/amc.json -o amc_planck/km.c
util/docker_build.sh planck/ez/glow:amc:flash

