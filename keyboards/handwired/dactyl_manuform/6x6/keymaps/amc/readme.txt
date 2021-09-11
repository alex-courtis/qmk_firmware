Elite-C Pro Micro Alternative
MCU = atmega32u4
BOOTLOADER = atmel-dfu
444d:3636 tshort Dactyl-Manuform (6x6)
03eb:2ff4 Atmel Corp. atmega32u4 DFU bootloader

Program the left first then disable MASTER_LEFT and program right


qmk json2c amc.json
qmk flash -kb handwired/dactyl_manuform/6x6 -km amc

