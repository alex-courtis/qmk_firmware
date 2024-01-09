https://github.com/bullwinkle3000/vial-qmk at 6a91508acd

`qmk_firmware/keyboards/handwired/wylderbuilds`

Modify amc.json at https://config.qmk.fm

Generate km.c
```sh
util/docker_cmd.sh qmk json2c amc_wylderbuilds/amc.json -o amc_wylderbuilds/km.c
```

Compile uf2
```sh
util/docker_build.sh handwired/wylderbuilds/5x6:amc
```

Enter bootloader and flash
```sh
picotool load -v handwired_wylderbuilds_5x6_amc.uf2
picotool reboot
```

