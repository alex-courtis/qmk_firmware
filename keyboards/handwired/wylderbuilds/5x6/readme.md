https://github.com/bullwinkle3000/vial-qmk at 6a91508acd

Bootloader: fn-equals
Default: left half bottom left
Gaming:  left halp bottom right

Left and right default:
```sh
util/docker_build.sh handwired/wylderbuilds/5x6:default
picotool load -v handwired_wylderbuilds_5x6_default.uf2
```

Left or right gaming:
```sh
util/docker_build.sh handwired/wylderbuilds/5x6:gaming
picotool load -v handwired_wylderbuilds_5x6_gaming.uf2
```
