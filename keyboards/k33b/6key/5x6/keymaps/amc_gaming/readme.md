Left only

Modify amc.json at https://config.qmk.fm

Generate km.c
```sh
util/docker_cmd.sh qmk json2c amc_gaming_dactyl_k33b/amc.json -o amc_gaming_dactyl_k33b/km.c
```

Compile uf2
```sh
util/docker_build.sh k33b/6key/5x6:amc_gaming
```

Enter bootloader - fn-equals - and flash left:
```sh
picotool load -v k33b_6key_5x6_amc_gaming.uf2
picotool reboot
```

