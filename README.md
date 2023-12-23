# Use an Xbox One Controller with Pico-W

This library allows you to connect an Xbox One Controller **(with older firmware versions without Bluetooth Low Energy, if you have a newer controller or updated firmware please use [this repo instead](https://github.com/intGus/picow_ble_controller))** to a Raspberry Pico W via Bluetooth Classic. It provides a simple interface to read button states and analog stick values from the controller.

This project is a fork of [usedbytes/picow_ds4](https://github.com/usedbytes/picow_ds4) made for PS4 controllers. 

## Prerequisites

Before using this library, make sure you have the following:

- Raspberry Pico W board
- Xbox One Controller with **Bluetooth Classic**
- [Pico SDK](https://www.raspberrypi.com/documentation/pico-sdk/) installed

## Getting Started

The MAC address is hardcoded in `/src/bt_hid.c` in line 66, you can get the MAC address of your controller using a computer or a cellphone with Bluetooth.

After you update the MAC address, follow the steps below to get started with the library:

1. Clone this repository `git clone https://github.com/intGus/picow_xbox.git`
2. Use `cd picow_xbox` to navigate inside the repository
3. Create the build directory `mkdir build`
4. Open the build directory `cd build`
5. Execute `cmake -DPICO_BOARD=pico_w -DPICO_SDK_PATH=/your/path/to/pico-sdk ../` make sure to
   replace with the appropriate path to your pico-sdk directory or remove if you are using an environmental variable
6. Execute `make`
7. Drag and drop or copy the `picow_xbox.uf2` file into the pico in BOOTSEL mode

The `.uf2` file will be `/build/src/picow_xbox.uf2`

On first boot, make sure the controller is in "pairing" mode (turn on the controller, then press the Pair button <sup>**)))**</sup>
on top of the controller for 3 seconds and release).

Once paired, it should reconnect when the controller is powered on.

## Usage

The `main.c` file serves as an example on how to use the library. It prints to the serial monitor parsed information about the buttons since buttons and d-pad are not parsed in the bt_hid file.

Each button is assigned a unique binary value that represents its state. You can find which button
is pressed performing the bitwise AND operation or combinations of buttons with OR as you see in the example.

You can uncomment lines 170 to 177 from `bt_hid_c` file to see the parsed data from the controller
with the raw data of buttons and d-pad.

## Roadmap

* Parse the buttons and d-pad state from the bt_hid.c file.
* Bring back the support to PS4 controllers and parse data accordingly.
* Remove any unused code and merge back to usedbyte's repo.

## Contributing

Pull requests are welcome. The idea is to merge this back to usedbytes repo to support both Xbox and PS4 controllers with one library.

## Acknowledgements
* [usedbytes/picow_ds4](https://github.com/usedbytes/picow_ds4)
* [bluekitchen/btstack](https://github.com/bluekitchen/btstack)https://github.com/bluekitchen/btstack
