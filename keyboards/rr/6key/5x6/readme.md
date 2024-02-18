Generate km.c
```sh
util/docker_cmd.sh qmk json2c amc_dactyl_5x6_rr/keymaps/default/keymap.json -o amc_dactyl_5x6_rr/keymaps/default/km.c
util/docker_cmd.sh qmk json2c amc_dactyl_5x6_rr/keymaps/gaming/keymap.json -o amc_dactyl_5x6_rr/keymaps/gaming/km.c
```

Left default, bootloader fn-equals:
```sh
util/docker_build.sh rr/6key/5x6:default
picotool load -v rr_6key_5x6_default.uf2
```

Right default, bootloader fn-equals:
`#define MASTER_RIGHT`
```sh
util/docker_build.sh rr/6key/5x6:default
picotool load -v rr_6key_5x6_default.uf2
```

Left gaming, bootloader fn(bottom)-equals:
```sh
util/docker_build.sh rr/6key/5x6:gaming
picotool load -v rr_6key_5x6_gaming.uf2
```

Right gaming, bootloader fn(bottom)-equals:
`#define MASTER_RIGHT`
```sh
util/docker_build.sh rr/6key/5x6:gaming
picotool load -v rr_6key_5x6_gaming.uf2
```
