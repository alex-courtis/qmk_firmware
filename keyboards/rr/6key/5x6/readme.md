Bootloader: fn-equals
Default: left half bottom left
Gaming:  left halp bottom right

Left default:
```sh
util/docker_build.sh rr/6key/5x6:default
picotool load -v rr_6key_5x6_default.uf2
```

Right default:
`#define MASTER_RIGHT`
```sh
util/docker_build.sh rr/6key/5x6:default
picotool load -v rr_6key_5x6_default.uf2
```

Left tapdance:
```sh
util/docker_build.sh rr/6key/5x6:tapdance
picotool load -v rr_6key_5x6_tapdance.uf2
```

Right tapdance:
`#define MASTER_RIGHT`
```sh
util/docker_build.sh rr/6key/5x6:tapdance
picotool load -v rr_6key_5x6_tapdance.uf2
```

Left gaming:
```sh
util/docker_build.sh rr/6key/5x6:gaming
picotool load -v rr_6key_5x6_gaming.uf2
```

Right gaming:
`#define MASTER_RIGHT`
```sh
util/docker_build.sh rr/6key/5x6:gaming
picotool load -v rr_6key_5x6_gaming.uf2
```
