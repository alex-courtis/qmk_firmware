Generate km.c
```sh
util/docker_cmd.sh qmk json2c amc_dactyl_6x6_ohkeycaps/keymaps/default/keymap.json -o amc_dactyl_6x6_ohkeycaps/keymaps/default/km.c
util/docker_cmd.sh qmk json2c amc_dactyl_6x6_ohkeycaps/keymaps/gaming/keymap.json -o amc_dactyl_6x6_ohkeycaps/keymaps/gaming/km.c
```

Left default:
```sh
util/docker_build.sh handwired/dactyl_manuform/6x6:default:flash
```

Right default:
`#define MASTER_RIGHT`
```sh
util/docker_build.sh handwired/dactyl_manuform/6x6:default:flash
```

Left gaming:
```sh
util/docker_build.sh handwired/dactyl_manuform/6x6:gaming:flash
```

Right gaming:
`#define MASTER_RIGHT`
```sh
util/docker_build.sh handwired/dactyl_manuform/6x6:gaming:flash
```
