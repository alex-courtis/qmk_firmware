Left only

Modify amc.json at https://config.qmk.fm

Generate km.c
```sh
util/docker_cmd.sh qmk json2c amc_gaming_wylderbuilds/amc.json -o amc_gaming_wylderbuilds/km.c
```

Compile uf2
```sh
util/docker_build.sh handwired/wylderbuilds/5x6:amc_gaming
```

Enter bootloader - fn-equals - and flash left:
```sh
picotool load -v handwired_wylderbuilds_5x6_amc_gaming.uf2
picotool reboot
```

