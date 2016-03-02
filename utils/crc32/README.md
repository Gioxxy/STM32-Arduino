
# CRC32 Tool

For Windows, you need cygwin or msys.

In this document, we will use the file 'Duo_Blink-NO_CRC.ino.bin' as an eample to add crc32 checksum to the Arduino compiled firmware.

To check the file has CRC-32 or not:

	$ hexdump Duo_Blink-NO_CRC.ino.bin 

You will see there is an invalid CRC-32 code at the end (0x12345678):

	0000ba0 0007 0000 0ac1 080c 0000 0000 ffff ffff
To apply CRC-32 code, use the 'crc.sh' sell script:

	$ ./crc.sh Duo_Blink-NO_CRC.ino.bin

After that, the binary will have the crc-32 code at the end:

	0000ba0 0007 0000 0ac1 080c 0000 0000 ffff ffff