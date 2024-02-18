Source provided by the fantastic folks at https://k33b.com

Generate km.c
```sh
util/docker_cmd.sh qmk json2c amc_dactyl_5x6_k33b/keymaps/default/keymap.json -o amc_dactyl_5x6_k33b/keymaps/default/km.c
util/docker_cmd.sh qmk json2c amc_dactyl_5x6_k33b/keymaps/gaming/keymap.json -o amc_dactyl_5x6_k33b/keymaps/gaming/km.c
```

Left or right default, bootloader fn-equals:
```sh
util/docker_build.sh k33b/6key/5x6:default
picotool load -v k33b_6key_5x6_default.uf2
```

Left or right gaming, bootloader fn(bottom)-equals:
```sh
util/docker_build.sh k33b/6key/5x6:gaming
picotool load -v k33b_6key_5x6_gaming.uf2
```
