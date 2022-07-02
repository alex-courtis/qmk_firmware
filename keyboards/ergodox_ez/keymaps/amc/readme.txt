BOOTLOADER = halfkay
MCU = atmega32u4
3297:4974 ZSA Technology Labs ErgoDox EZ
16c0:0478 Van Ooijen Technische Informatica Teensy Halfkay Bootloader

teensy-loader-cli:
/usr/lib/udev/rules.d/00-teensy.rules

util/docker_cmd.sh qmk json2c amc_ergodox/amc.json > amc_ergodox/km.c
util/docker_build.sh ergodox_ez:amc:flash
