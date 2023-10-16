Modify amc.json at https://config.qmk.fm

Generate km.c
```sh
util/docker_cmd.sh qmk json2c amc_dactyl_rr/amc.json -o amc_dactyl_rr/km.c
```

Compile uf2
```sh
util/docker_build.sh rr/6key/5x6:amc
```

Enter bootloader - fn-equals - and flash left:
```sh
picotool load -v rr_6key_5x6_amc.uf2
picotool reboot
```

`#define MASTER_RIGHT` and flash right.

