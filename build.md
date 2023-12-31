# ExploSnake Build Instructions

### Test points:
| Net        | Location                 |
|------------|--------------------------|
| 5v         | Pin 2 (lower left) of J1 |
| D5-A       | Pin 3 (bottom) of U4     |
| VBUS_RAW   | The right pad of F1      |
| VBUS_FUSED | The left pad of F1       |
| VBUS       | Pin 1 (far left) of J2   |
| GND        | Pin 1 (right) of J2      |

### Component locations
See the interactive BOM for component locations. Assemble in the order listed below, not the order on the ibom.
Additionally note that not all components on the ibom will be populated.
[https://orangeben.dev/bom/explosnake.html](https://orangeben.dev/bom/explosnake.html)

## Step 1 - Assemble the PCB
1. Generate the iBOM and open it
1. Go through the list and collect all of your parts. Leave them in their cut tape or bags for now
1. Get the PCB
1. Clean the PCB
    1. File down the rabbit bites on the edges until they are flush with the edge of the board
    1. Wash the board with soap and water, dry it. Try not to touch component locations after this (although its not a big problem if you do)
    1. OPTIONAL: Wash the board with IPA.
1. Install U1 by reflow if possible or by hand
1. Install Y1 by reflow if possible or by hand if you do not plan to ultrasonic the board later
1. Install all R,C
1. Install D1-4 (Pin 1 is the end with less gold on it)
1. Use a DMM to confirm that VBUS_RAW, VBUS_FUSED are not shorted to ground or anything else nearby
1. Install F1
1. Install the USB_C connector
1. Test the USBC power supply
    1. Connect a USBC power supply capable of 20V
    1. Confirm that VBUS_FUSED is 20V
    1. Connect a USBC power supply not capable of 20V (e.g. a USB A-C cable)
    1. Confirm that D3 is the only LED that is lit
    1. Confirm that VBUS_FUSED is 5V
    1. Unplug the power supply
1. Install U4
1. Install Q1-4
1. Test the USBC Power supply some more
    1. Connect a USBC power supply capable of 20V
    1. Confirm that VBUS is 20V
    1. Confirm that D5-A net is at 5V
    1. Confirm that D4 is the only LED lit 
    1. Connect a USBC power supply not capable of 20V (e.g. a USB A-C cable)
    1. Confirm that D3 is the only LED that is lit
    1. Confirm that VBUS is 0V
    1. Confirm that 5V net is at 5V
    1. Unplug the power supply
1. Install D5. The bar is on the pin 1 side
1. Test the 5v reg
    1. Connect a USBC power supply capable of 20V
    1. Confirm that VBUS is 20V
    1. Confirm that 5V is roughly 4.7V
    1. Confirm that D4 and D1 are both lit 
    1. Connect a USBC port to your computer
    1. Confirm that D3 and D1 are both lit
    1. Confirm that VBUS is roughly 0V
    1. Confirm that 5V net is at 5V
    1. Unplug the power supply  
1. Install U2 and U3
1. Install Y1
    1. Match the direction of the text to the silkscreen
    1. Install by reflow if possible or by hand if you have not already installed it
1. Install Q5
1. Install all switches
1. Clean the board

## Step 2 - Burn the bootloader
1. Aquire an Atmel programmer. This can be a dedicated device, or another Arduino running the ICSP firmware.
    1. Open the Arduino IDE
    1. 



1. Test the uC
    1. Connect the USBC cable to a computer
    1. Confirm that D1 and D3 are lit
    1. Confirm that the computer can see the atmega32u4