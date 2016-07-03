# Plantalytics Microcontrollers

Microcontroller: Motenino USB RFm95 with LoRa 915mhz Transceiver

Using Arduino 1.6.9 IDE in C++

## License

Copyright (c) 2016 Sapphire Becker, Katy Brimm, Scott Ewing, Matt Fraser, Kelly Ledford, Michael Limb, Steven Ngo, Eric Turley.

This project is licensed under the MIT License. Please see the file LICENSE in this distribution for license terms.


## Set-up
Need the following:
* **Arduino IDE** (1.0.x or greater)
	* https://www.arduino.cc/en/Main/Software
* **Radiohead Library**
	* http://lowpowerlab.com/RadioHead_LowPowerLab.zip

Setting up the IDE

1.) Under tools tab, make sure the board is "Arduino/Genuino Uno".

2.) Install Radiohead library by downloading the ZIP file and in IDE Sketch > Include Library > Add .ZIP Library

## Note:
* rf95_node folder contains the arduino file code for a node.

* test folder is to test the connection of LoRa Transceivers between mircocontrollers. Use rf95_node(as node) and rf95_server(as hub) to test LoRa connection at 915mhz.
