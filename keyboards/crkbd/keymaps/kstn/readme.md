
### Flashing firmware

EE_HANDS is #define'ed in config.h so that USB connector on either side can
be used. Use the following commands to flash left and right halves.

qmk flash -kb crkbd/rev1 -km kstn -bl avrdude-split-left

qmk flash -kb crkbd/rev1 -km kstn -bl avrdude-split-right
