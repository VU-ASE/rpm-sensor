# Flashing

In case of replacements or updates to the firmware, the speed controllers need to be flashed with custom firmware to work. For this, you will need to connect the flash pins of the board
to the Microchip [PICkit 5-in-1 debugger](https://www.microchip.com/en-us/development-tool/pg164150).

After connecting the flashing wires, follow these steps:

1. Power on the Rover, so that the boards gets power
2. Plug the PICkit debugger into your computer over USB
3. Open the MPLAB IDE and press the green "play" icon

![Screenshot of the MPLAB IDE, showing the "play" icon to flash](https://github.com/user-attachments/assets/9c728360-95b8-42c9-9124-41f7fdb1ffa1)

This will compile your code and flash it to the board. If all goes well, your code should start executing immediately after flashing.
