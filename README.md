# usps8266

> ESP8266-based snailmail alert system
 
## Receiver BOM

1.  Project enclosure (1)
2.  Veroboard, stripboard, etc. (1)
3.  LED (1)
4.  Resistor for aforementioned LED (1)
5.  ENC28J60 Ethernet Module (1)
6.  ATmega328p-based device -- whatever has enough GPIO pins to talk to a ENC28J60 (1)
7.  2.1mm center-positive DC jack (1)
8.  M/F DuPont wires (1)
9.  Hookup wire for the DC jack (1)
10. Wall wart with enough juice to power both the ENC28J60 & the dev board and not fry either.  You probably want a 9V 1A (1)
11. And whatever glue, tape, screws or chewing gum to secure the boards in the enclosure

## Monitor BOM

1.  ESP8266 module.  I used an ESP-07 w/ adapter plate (1)
2.  USB-to-TTL module (CP2102 works best; YMMV) [Probably not a PL2303 if you're using a Mac](https://github.com/igrr/esptool-ck/issues/9). (1)
3.  Reed Switch Pair (like [this](http://www.srielectronics.in/images/products/magmatic.jpg)) (1)
4.  10kΩ resistors (5)
5.  Handful of hookup/breadboard/dupont wire
6.  "OFF (ON)" momentary switch; one for "mailbox reset" functionality, the other for resetting the ESP8266 (2)
7.  Solar panel
8.  Rechargeable AA batteries (2)
9.  Appropriate enclosure (1)
10. (Optional) External WiFi antenna (1)
