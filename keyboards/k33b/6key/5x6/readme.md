Source provided by the fantastic folks at https://k33b.com

Clean required as some generated artifacts like `info_config.h` are not regenerated.

Bootloader: fn-equals
Default: left half bottom left
Gaming:  left halp bottom right

Left or right default:
```sh
rm -rf .build ; util/docker_build.sh k33b/6key/5x6:default
sleep 5 ; picotool load -v k33b_6key_5x6_default.uf2 ; picotool reboot
```

Left or right tapdance:
```sh
rm -rf .build ; util/docker_build.sh k33b/6key/5x6:tapdance
sleep 5 ; picotool load -v k33b_6key_5x6_tapdance.uf2 ; picotool reboot
```

Left or right macos:
```sh
rm -rf .build ; util/docker_build.sh k33b/6key/5x6:macos
sleep 5 ; picotool load -v k33b_6key_5x6_macos.uf2 ; picotool reboot
```

Left or right gaming:
```sh
rm -rf .build ; util/docker_build.sh k33b/6key/5x6:gaming
sleep 5 ; picotool load -v k33b_6key_5x6_gaming.uf2 ; picotool reboot
```
