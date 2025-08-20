# Development

This repository is used to maintain and reflash the RPM sensors when necessary. You can use VSCode to update the *main.c* file, but you will need the [MPLAB X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide) to flash
it to the board.

## Generated Code (MCC)

The main code is quite compact and is based on auto-generated files from the MPLAB X MCC generator. If you want to modify auto-generated code, you should open the MCC tab in
MPLAB X.

![Screenshot of MPLAB X to open MCC](https://github.com/user-attachments/assets/45e228b8-012f-45ef-85d4-f1096e53c0f4)

You can then, for example, modify the DAC output voltage by double clicking the DAC component in the device overview: 

![Screenshot of MPLAB X to edit DAC](https://github.com/user-attachments/assets/53806bd8-482f-48f3-a7d6-3bbf369a9132)

Then, you can modify the desired properties and click "generate" afterwards:

![Screenshot of MPLAB X to edit DAC properties and generate code afterwards](https://github.com/user-attachments/assets/ef1be923-3332-4ff5-b726-9899d2262999)

This will generate the correct C header files and source files in the */mcc_generated_files* directory. You can import these in the *main.c* file.

## I2C Properties

The current code exposes an I2C client (previously called "slave") on address **0x14**. Similar to the DAC settings above, this value can be changed using MCC. 

An I2C host (previously called "master") can read registers from this client. There are 255 registers available, of which only the first 18 registers are used. The registers
are populated according to the following schema:

```
 Register 0       Register 1        Register 2       Register 3      
┌────────────────┬────────────────┬────────────────┬────────────────┐
│ 0xba           │ 0xbe           │ Timer Capt. L  │ Timer Capt. L  │
│ Control value  │ Control value  │ 1/4            │ 2/4            │
└────────────────┴────────────────┴────────────────┴────────────────┘
                                                                     
 Register 4       Register 5        Register 6       Register 7      
┌────────────────┬────────────────┬────────────────┬────────────────┐
│ Timer Capt. L  │ Timer Capt. L  │ Timer Capt. R  │ Timer Capt. R  │
│ 3/4            │ 4/4            │ 1/4            │ 2/4            │
└────────────────┴────────────────┴────────────────┴────────────────┘
                                                                     
 Register 8       Register 9        Register 10      Register 11     
┌────────────────┬────────────────┬────────────────┬────────────────┐
│ Timer Capt. R  │ Timer Capt. R  │ Timeout Cnt. L │ Timeout Cnt. L │
│ 3/4            │ 4/4            │ 1/2            │ 2/2            │
└────────────────┴────────────────┴────────────────┴────────────────┘
                                                                     
 Register 12      Register 13       Register 14      Register 15     
┌────────────────┬────────────────┬────────────────┬────────────────┐
│ Timeout Cnt. R │ Timeout Cnt. R │ Sequence No. L │ Sequence No. L │
│ 1/2            │ 2/2            │ 1/2            │ 1/2            │
└────────────────┴────────────────┴────────────────┴────────────────┘
                                                                     
 Register 16      Register 17       Register 18 .... Register 255    
┌────────────────┬────────────────┬─────────────────────────────────┐
│ Sequence No. R │ Sequence No. R │              0x0                │
│ 1/2            │ 2/2            │             Unused              │
└────────────────┴────────────────┴─────────────────────────────────┘
```

When you read the I2C registers, you should use a contiguous batch read and you should always check the first control bytes to be 0xbabe. It is recommended to check out the 
[`rpm` service](https://ase.vu.nl/docs/category/rpm) to check how this is done.

As can be seen in the schema above, for each of the rear wheels, the following properties are available:

- **Timer capture**: this reports the number of ticks between two black stripes. The board runs a 64 MHz clock with a 1:8 prescaler, so you can use the following formula to convert the number of ticks to time in milliseconds: `((1 / 8000) * 1000.0 * TICKS)`
  - The prescaler can be configured in MCC. Also see main.c
- **Timeout capture**: this reports the number of times that the timer "wrapped around" (aka timed out). This is useful if the Rover drives very slowly. The timer wraps around after 5 ms so you should add this to your total time computation
  - The timeout can be configured in MCC. Also see main.c
- **Sequence number**: this number will increase every time a rising edge is detected (and will wrap around). You can use this as a control mechanism to ensure that the optical sensor works correctly. You can also use it to dismiss stale readings (if you read the same sequence number more than once).

## Rationale

Unfortunately, we cannot set up the MPLAB IDE in a Devcontainer.
