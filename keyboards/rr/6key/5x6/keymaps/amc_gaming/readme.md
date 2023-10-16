Left only

Modify amc.json at https://config.qmk.fm

Generate km.c
```sh
util/docker_cmd.sh qmk json2c amc_gaming_dactyl_rr/amc_gaming.json -o amc_gaming_dactyl_rr/km.c
```

Compile uf2
```sh
util/docker_build.sh rr/6key/5x6:amc_gaming
```

Enter bootloader and flash left:
```sh
picotool load -v rr_6key_5x6_amc_gaming.uf2
picotool reboot
```

