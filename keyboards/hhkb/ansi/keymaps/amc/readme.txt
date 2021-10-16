MCU = atmega32u4
BOOTLOADER = atmel-dfu
4848:0001 q.m.k HHKB mod
03eb:2ff4 Atmel Corp. atmega32u4 DFU bootloader

qmk json2c amc.json > km.c
qmk flash -kb hhkb/ansi -km amc

