# Smart-Popcorn-Machine

## Background:

The thermostat on our Olde Midway popcorn machine broke causing it to overheat and shut off quickly. We had the idea to control the temperature using a thermocouple and a microcontroller.

## Materials:
* Olde Midway popcorn machine
* Microcontroller, we chose an Arduino Uno r3
* Thermocouple, we chose a type k thermocouple
* Thermocouple amplifier MAX6675/MAX31855, we chose the MAX6675
* Relay, we chose the SRD-05VDC-SL-C as it can handle high voltage and amperage
* A breadboard
* Dupont cables

## Problems:

* Having the Uno r3 connected to an AC power source may cause issues with the thermocouple welded to the bottom of the kettle as the kettle is grounded which can cause ground loops and electrical noise leading to inaccurate readings
  ## Short-Term Fix:
  Run the Arduino off of a battery pack
  ## Long-Term Fix:
  Galvanically isolate the circuit to prevent electrical noise and ground loops.
  
## Making the circuit and starting it up

  * Connect the breadboard's positive rail to the Uno's 5V pin and the negative rail to the Uno's ground pin.
  * Connect the VCC and GND pins of the MAX6675s and the relay to the positive and negative rails respectively.
  * In my case I used two thermocouples although just one can be used.
  *   MAX6675 #1: Connect the SO pin to d4, the CS pin to d5, and the SCK pin to d6 and attach the thermocouple; be sure to connect the polarities to their correct terminals otherwise the temperature reported will have an inverse relationship with the actual temperature
  *   MAX6675 #2: Connect the SO pin to d8, the CS pin to d9, and the SCK pin to d10 and attach the thermocouple; be sure to connect the polarities to their correct terminals otherwise the temperature reported will have an inverse relationship with the actual temperature
  *   Connect the relay control pin to d7
## Attaching the circuit
  * Remove the kettle assembly from the machine
  * Remove the kettle from the shell
  * Remove the main thermostat from the kettle
  * Attach the two cables connected to the thermostat to the threaded pole that the thermostat was on and tighten with a nut and washer
  * Attach the thermocouple heads to the kettle underside by welding it or clamping it under the emergency shutoff thermostat assembly
  * Route the thermocouples wire with the other wires. Be careful not to have loops or kinks in the wire
  * Put the kettle back in its shell
  * Put the assembly back in the machine
  * Route the circuit into the chamber above the kettle this is where the circuity will go
  * The kettle will connect to a power outlet on the ceiling of the main chamber; in the top chamber find where the kettle connects to the outlet(it will likely be two separate wires connected by a wire nut) put one end in the NO(normally open) and C(common)  terminals of the  relay
  * Upload the code to the Uno
  * I recommend 3 short squirts of oil, a half cup of kernels, and 1/4 teaspoon of salt
  * Turn the machine on
  * When the popping starts empty the kettle
  * Enjoy
