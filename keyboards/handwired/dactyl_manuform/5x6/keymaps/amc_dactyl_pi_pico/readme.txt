239a:80f4 Adafruit Pico
2e8a:0003 Raspberry Pi RP2 Boot

Device uses https://github.com/KMKfw/kmk_firmware and is not directly flashed; it runs some python on boot which loads the json configuration.

The mapping for the square cluster at the bottom left/right is rotated 90degrees anticlockwise / clockwise. See rotation.png

Define keys at https://config.qmk.fm/#/handwired/dactyl_manuform/5x6/LAYOUT_5x6 and save as keymap.json

Hold down top left / top right key for 5 seconds while reconnecting.

udisksctl mount -b /dev/sda1
cp keymap.json $(findmnt -n -o TARGET /dev/sda1)
udisksctl unmount -b /dev/sda1
sync

Reconnect

