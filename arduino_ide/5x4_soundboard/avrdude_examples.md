
##avrdude command-line examples (programmer: mySmartUSB light)

###fuse-settings for 8MHz internal clock

avrdude -v -patmega328p -cstk500v2 -b115200 -P/dev/ttyUSB0 -e -Ulock:w:0x3F:m -Uefuse:w:0x05:m -Uhfuse:w:0xDA:m -Ulfuse:w:0xE2:m

###write 'arduino' bootloader for 8MHz internal clock (not needed for this project)

avrdude -v -patmega328p -cstk500v2 -b115200 -P/dev/ttyUSB0 -Uflash:w:ATmegaBOOT_168_atmega328_pro_8MHz.hex:i -Ulock:w:0x0F:m

###write intel-hex to flash

avrdude -v -patmega328p -cstk500v2 -b115200 -P/dev/ttyUSB0 -Uflash:w:5x4_soundboard.hex:i
