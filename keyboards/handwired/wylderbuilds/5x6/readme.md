https://github.com/bullwinkle3000/vial-qmk at 6a91508acd

Generate km.c
```sh
util/docker_cmd.sh qmk json2c amc_dactyl_5x6_wylderbuilds/keymaps/default/keymap.json -o amc_dactyl_5x6_wylderbuilds/keymaps/default/km.c
util/docker_cmd.sh qmk json2c amc_dactyl_5x6_wylderbuilds/keymaps/gaming/keymap.json -o amc_dactyl_5x6_wylderbuilds/keymaps/gaming/km.c
```

Left and right default, bootloader fn-equals:
```sh
util/docker_build.sh handwired/wylderbuilds/5x6:default
picotool load -v handwired_wylderbuilds_5x6_default.uf2
```

Left or right gaming, bootloader fn(bottom)-equals:
```sh
util/docker_build.sh handwired/wylderbuilds/5x6:gaming
picotool load -v handwired_wylderbuilds_5x6_gaming.uf2
```
