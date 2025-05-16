10 sec bootup:

good 0.21.7
bad  0.22.0
bad  0.22.14

macos:
```sh
util/docker_build.sh clean ; util/docker_build.sh kinesis/kint41:amc
teensy_loader_cli -w -v --mcu=TEENSY41 kinesis_kint41_amc.hex
```
