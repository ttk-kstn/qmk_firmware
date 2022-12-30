# MXantor

Based on Beekeeb's Piantor keyboard.

Make example for this keyboard (after setting up your build environment):

    qmk compile -kb mxantor -km default

Flashing example for this keyboard:

    qmk flash -kb mxantor -km default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Physical reset button**: Hold the `BOOTSEL` button on the PCB while plugin in the usb cable.
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
