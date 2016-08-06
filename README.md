# Plantalytics Microcontrollers

## License

Copyright (c) 2016 Sapphire Becker, Katy Brimm, Scott Ewing, Matt Fraser, Kelly Ledford, Michael Limb, Steven Ngo, Eric Turley.

This project is licensed under the MIT License. Please see the file LICENSE in this distribution for license terms.

## How to Use

Get your hardware:
* **Micro controller** (Motenino USB RFM95 with LORA 915mhz Trasnsceiver)

Install the Arduino IDE:
* **Arduino IDE** (version 1.6.9 or greater)
  * https://www.arduino.cc/en/Main/Software
* Under tools tab, make sure the board is "Arduino/Genuino Uno".
  
Install the following in your Arduino/libraries directory:
* **IMIC Master Library** 
  * https://github.com/matthijskooijman/arduino-lmic
* **Radiohead Library** 
  * http://lowpowerlab.com/RadioHead_LowPowerLab.zip
* **DHT Sensor Library**
  * https://github.com/adafruit/DHT-sensor-library

Plug the micro controller into the computer, and set the device address at line 48. When compiled, the program will be pushed to the micro-controller and execute immediately!

## Note:

* rf95_node folder contains the arduino file code for a node.
* test folder is to test the connection of LoRa Transceivers between mircocontrollers. Use rf95_node(as node) and rf95_server(as hub) to test LoRa connection at 915mhz.
