Elite-C Pro Micro Alternative
MCU = atmega32u4
BOOTLOADER = atmel-dfu
444d:3636 tshort Dactyl-Manuform (6x6)
03eb:2ff4 Atmel Corp. atmega32u4 DFU bootloader

util/docker_cmd.sh qmk json2c amc_dactyl/amc.json -o amc_dactyl/km.c
util/docker_build.sh handwired/dactyl_manuform/6x6:amc:flash

Program the left first then disable MASTER_LEFT and program right
