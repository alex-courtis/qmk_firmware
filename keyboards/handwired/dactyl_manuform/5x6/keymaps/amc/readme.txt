???
MCU = ???
BOOTLOADER = ???
239a:80f4 Adafruit Pico
2e8a:0003 Raspberry Pi RP2 Boot

util/docker_cmd.sh qmk json2c amc_dactyl/amc.json -o amc_dactyl/km.c
util/docker_build.sh handwired/dactyl_manuform/6x6:amc:flash

Program the left first then disable MASTER_LEFT and program right
