BOOTLOADER = halfkay
MCU = atmega32u4
3297:4974 ZSA Technology Labs ErgoDox EZ
16c0:0478 Van Ooijen Technische Informatica Teensy Halfkay Bootloader


qmk json2c amc.json
qmk flash -kb ergodox_ez -km amc

