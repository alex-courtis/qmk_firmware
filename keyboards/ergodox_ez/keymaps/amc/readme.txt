BOOTLOADER = halfkay
MCU = atmega32u4
3297:4974 ZSA Technology Labs ErgoDox EZ
16c0:0478 Van Ooijen Technische Informatica Teensy Halfkay Bootloader

teensy-loader-cli:
/usr/lib/udev/rules.d/00-teensy.rules

qmk json2c amc.json > km.c
qmk flash -kb ergodox_ez -km amc

