Bootloader: fn-equals
Default: left half bottom left
Gaming:  left halp bottom right

Clean required as some generated artifacts like `info_config.h` are not regenerated.

Left default:
```sh
rm -rf .build ; util/docker_build.sh rr/6key/5x6:default
sleep 5 ; picotool load -v rr_6key_5x6_default.uf2 ; picotool reboot
```

Right default:
`#define MASTER_RIGHT`
```sh
rm -rf .build ; util/docker_build.sh rr/6key/5x6:default
sleep 5 ; picotool load -v rr_6key_5x6_default.uf2 ; picotool reboot
```

Left tapdance:
```sh
rm -rf .build ; util/docker_build.sh rr/6key/5x6:tapdance
sleep 5 ; picotool load -v rr_6key_5x6_tapdance.uf2 ; picotool reboot
```

Right tapdance:
`#define MASTER_RIGHT`
```sh
rm -rf .build ; util/docker_build.sh rr/6key/5x6:tapdance
sleep 5 ; picotool load -v rr_6key_5x6_tapdance.uf2 ; picotool reboot
```

Left gaming:
```sh
rm -rf .build ; util/docker_build.sh rr/6key/5x6:gaming
sleep 5 ; picotool load -v rr_6key_5x6_gaming.uf2 ; picotool reboot
```

Right gaming:
`#define MASTER_RIGHT`
```sh
rm -rf .build ; util/docker_build.sh rr/6key/5x6:gaming
sleep 5 ; picotool load -v rr_6key_5x6_gaming.uf2 ; picotool reboot
```
