https://github.com/bullwinkle3000/vial-qmk at 6a91508acd

Clean required as some generated artifacts like `info_config.h` are not regenerated.

Bootloader: fn-equals
Default: left half bottom left
Gaming:  left halp bottom right

Left and right default:
```sh
rm -rf .build ; util/docker_build.sh handwired/wylderbuilds/5x6:default
sleep 5 ; picotool load -v handwired_wylderbuilds_5x6_default.uf2 ; picotool reboot
```

Left or right macos:
```sh
rm -rf .build ; util/docker_build.sh handwired/wylderbuilds/5x6:macos
sleep 5 ; picotool load -v handwired_wylderbuilds_5x6_macos.uf2 ; picotool reboot
```
