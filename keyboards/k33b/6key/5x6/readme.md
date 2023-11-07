Source provided by the fantastic folks at https://k33b.com

Modify amc.json at https://config.qmk.fm

Generate km.c
```sh
util/docker_cmd.sh qmk json2c amc_dactyl_k33b/amc.json -o amc_dactyl_k33b/km.c
```

Compile uf2
```sh
util/docker_build.sh k33b/6key/5x6:amc
```

Enter bootloader and flash
```sh
picotool load -v k33b_6key_5x6_amc.uf2
picotool reboot
```

