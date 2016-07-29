# Plantalytics Microcontrollers

## License

Copyright (c) 2016 Sapphire Becker, Katy Brimm, Scott Ewing, Matt Fraser, Kelly Ledford, Michael Limb, Steven Ngo, Eric Turley.

This project is licensed under the MIT License. Please see the file LICENSE in this distribution for license terms.

## How to Run

* **Arduino IDE** (version 1.6.9 or greater)
  * https://www.arduino.cc/en/Main/Software
* **IMIC Master Library** 
  * https://github.com/matthijskooijman/arduino-lmic
* **Radiohead Library** 
  * http://lowpowerlab.com/RadioHead_LowPowerLab.zip
* **Micro controller** (Motenino USB RFM95 with LORA 915mhz Trasnsceiver)

Install the libraries in Arduino IDE using provided files or using provided links for more up to date libraries(recommanded). 

Plug the micro controller into the computer, code should compile and transfer into the micro controller.

Setting up the IDE

1.) Under tools tab, make sure the board is "Arduino/Genuino Uno".

2.) Install Radiohead library by downloading the ZIP file and in IDE Sketch > Include Library > Add .ZIP Library

## Note:

* rf95_node folder contains the arduino file code for a node.
* test folder is to test the connection of LoRa Transceivers between mircocontrollers. Use rf95_node(as node) and rf95_server(as hub) to test LoRa connection at 915mhz.