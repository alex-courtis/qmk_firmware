MCU = atmega32u4
BOOTLOADER = atmel-dfu
feed:6060 OLKB Planck
0483:df11 STMicroelectronics STM Device in DFU Mode


Use branch amc-planck-451e60047 until the upstream issue with planck lighting is resolved.


qmk json2c amc.json
qmk flash -kb planck/ez -km amc

