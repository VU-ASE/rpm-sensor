# Overview

![One of the rear wheels with zebra pattern and optical sensor](https://github.com/user-attachments/assets/34ceb202-5ce8-464c-b584-6551939f2f34)

This repository contains the embedded RPM sensor code that can be flashed to the Microchip [PIC18F06Q41](https://www.microchip.com/en-us/product/pic18f06q41) device. Its code is meant to be opened in the [MPLAB X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide), of which version 6.25 was used during development.

This embedded program relies on two optical sensors being installed on both rear wheels of the ASE rovers. On each wheel, a zebra pattern should be mounted. This program will then record the time between two black stripes in clock ticks, which will be reported over I2C, to be read by the [`rpm` service](https://ase.vu.nl/docs/category/rpm) that runs on the Debix.

## Rationale

Even though the [embedded ESC](http://localhost:3000/docs/category/esc) consumes RPM data using a magnetic encoder in its internal loop, reporting these values back to the Debix proved error-prone and inaccurate. We noticed that students still wanted to measure RPM and speed data of the Rover (e.g. for position tracking). By adding two optical RPM sensors, we have created a way to reliably read RPM and speed values at a high resolution.

## Tuning

This embedded program works by keeping track of the time between "pulses" of the optical sensor. These pulses are generated when the optical sensor sees a black stripe. The board (PIC18F06Q41) has a built-in Digital to Analog Converter (DAC) that can output a reference voltage between 0 and 3.3V. The optical sensor will pull down its voltage when it detects a black stripe, so that the board's built-in comparator detects this as a rising edge (from white to black stripe). Every rising edge, the current time will be captured and the timer will be reset, for both wheels individually.

- The DAC output voltage can be tuned in the embedded code (between 0 (0V) and 255 (3.3V))
- The voltage that the optical sensor will pull down to can be tuned using a potentiometer in hardware
