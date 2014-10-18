WiringPi-RGB-Plate-Bootstrap
============================
Full initialization of display, LED backlight and buttons for a C program that operates [Adafruit's RGB LCD kit for Raspberry Pi](http://www.adafruit.com/products/1110) using [WiringPi LCD library](http://wiringpi.com/dev-lib/lcd-library/).

Examples of custom character graphics and reading button state included.

Compile: gcc -Wall -o wiring_plate wiring_plate.c -lwiringPi -lwiringPiDev
