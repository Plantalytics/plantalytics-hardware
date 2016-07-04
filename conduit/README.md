# Plantalytics Conduit

A random number generator to simulate the transmission of node data to a Cassandra database.

## Setup

Setting up the Conduit is 9/10ths of the battle. The first step is to configure the network settings.

Then:

    * Set DNS server:
        * Add `dns-nameservers 8.8.8.8 8.8.4.4` to /etc/network/interfaces
    * Set up Python based on the instructions from [Multitech](http://www.multitech.net/developer/software/mlinux/mlinux-software-development/python/), execute the following commands:
        * opkg update
        * opkg install python-pip
        * wget https://bootstrap.pypa.io/ez_setup.py --no-check-certificate
        * python ez_setup.py
        * pip install cassandra-driver
    * Install Git:
        * opkg install git

After taking these steps, it is possible to download and run the softare needed to connect the node data to the database!

## License

Copyright (c) 2016 Sapphire Becker, Katy Brimm, Scott Ewing, Matt Fraser, Kelly Ledford, Michael Limb, Steven Ngo, Eric Turley.

This project is licensed under the MIT License. Please see the file LICENSE in this distribution for license terms.