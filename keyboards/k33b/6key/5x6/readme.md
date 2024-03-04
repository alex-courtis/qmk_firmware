Source provided by the fantastic folks at https://k33b.com

Bootloader: fn-equals
Default: left half bottom left
Gaming:  left halp bottom right

Left or right default:
```sh
util/docker_build.sh k33b/6key/5x6:default
picotool load -v k33b_6key_5x6_default.uf2
```

Left or right tapdance:
```sh
util/docker_build.sh k33b/6key/5x6:tapdance
picotool load -v k33b_6key_5x6_tapdance.uf2
```

Left or right gaming:
```sh
util/docker_build.sh k33b/6key/5x6:gaming
picotool load -v k33b_6key_5x6_gaming.uf2
```
