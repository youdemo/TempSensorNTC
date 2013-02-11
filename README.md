TempSensorNTC
=============

NTC Thermistors from VISHAY, calculating the temperature with the extended Steinhart and Hart formula.

Background
==========

I use the NTC from VISHAY NTC-0.2 10K:

* 0,25 W
* 2,54 mm
* temperature -25...+125 °C
* +/- 5%
* 10K at 25 °C

The datasheet (on page 73) explains how to calculate the temperature from the resistor value
of the NTC:

* First select the B25/85-VALUE from the table on page 70. (In my case the row is 10 000, 3977 K, 0.75%, 4103, 6103, 3103 ).
* Then find the values for A1, B1, C1, D1 from table on page 73. (in my case the row is 9, 3977....)
* After that measure the input voltage.
* Now you have everything to calculate the temperature.


<pre><code>
#define A 3.354016E-03
#define B 2.569850E-04
#define C 2.62013E-06
#define D 6.38309E-07

/**
 * 10.000 ohm, R25+/-5%: brown, black, orange
 */
#define RREF 10000.0

/**
 * The voltage supply, measured
 */
#define VIN 4.92
</code></pre>

