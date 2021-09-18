MCU = atmega32u4
BOOTLOADER = atmel-dfu
feed:6060 OLKB Planck
0483:df11 STMicroelectronics STM Device in DFU Mode


qmk json2c amc.json > km.c
qmk flash -kb planck/ez/glow -km amc

