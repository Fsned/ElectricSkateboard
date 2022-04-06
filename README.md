# ElectricSkateboard

This is my repo to contain all my files while making my own electric skateboard.

## BatteryIndicator
This is the part to indicate the current battery charge remaining on each battery, without the battery is connected to the skateboard.
This is done by reading the battery information from the BMS via UART, to a Xiao RP2040 MCU, and displaying it on a 10-LED RGB strip.
The LED-strip should be visible from the outside.
Stuff i make myself:
- PCB to connect everything
- Software to read UART and control the LED's accordingly

## Batterycase
This is the case, containing the batterypack, the BMS and the battery-indicator. This should eventually have some fancy
slide-in male connector, to latch on and connect to the motor controller.

## MC case
This is the case containing the motor controller and remote receiver, communicating with the remote.
This should have a slide-in female part, to easily connect to the batterycase.
