Modify amc.json at https://config.qmk.fm

Generate km.c
```sh
util/docker_cmd.sh qmk json2c amc_rr/amc.json -o amc_rr/km.c
```

Compile uf2
```sh
util/docker_build.sh rr/6key/5x6:amc
```

Enter bootloader and flash
```sh
picotool load -v rr_6key_5x6_amc.uf2
picotool reboot
```

