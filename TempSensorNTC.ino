/**
 * NTC Thermistors, VISHAY, 
 *
 * This example code is in the public domain.
 *
 *
 *
 */
#define ANALOG_PIN A0

/**
 * constants from the datasheet: page 73. In this case I use the 10.000 ohm, R25+/-5%: brown, black, orange
 */
#define A 3.354016E-03
#define B 2.569850E-04
#define C 2.62013E-06
#define D 6.38309E-07

/**
 * 10.000 ohm, R25+/-5%: brown, black, orange
 */
#define RREF 10000.0

/**
 * The voltage supply, measured (at least 5V)
 */
#define VIN 4.92

/**
 * 
 */
double termistor( int rawADC ) {

  double vout  = (rawADC * VIN) / 1024.0;                // measured V 
  double r     = VIN * RREF / vout - RREF;               // resistor of the ntc
  double result= log( r / RREF );                        // calculating 
  result       = 1.0 / ( A + ((B + C*result) + D*result*result)*result );   // 

  // Convert Kelvin to Celcius
  return result - 273.15;
}

void setup() { Serial.begin(9600); }

void loop() {
  
  // read the analog in value:
  int sensorValue= analogRead( ANALOG_PIN );            

  // print the results to the serial monitor:
  Serial.print( "sensor = " );
  Serial.print( sensorValue );
  Serial.print( "\t output = ");
  Serial.println( termistor( sensorValue ) );

  delay(5000);                     
}
