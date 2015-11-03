#include "SenseMeMagnetometer.h"
#include "Wire.h"
#include <Arduino.h>


// Magnetometer demo
//
// Print the field strength values
//
float val = 0.0;

void setup()
{ 
  delay(10000);
  SenseMeMagnetometer.begin();
}

void loop()
{ float magneticField[3];

  // Read magnetic field strength. The values range from -20000
  // to +20000 counts and are based on internal calibration
  // values
  //
  SenseMeMagnetometer.xyz(magneticField);
  
  float x = magneticField[0];
  float y = magneticField[1];
  float z = magneticField[2];
  //Serial.print("Magnetic field strength: x = ");
  Serial.print(x);
  Serial.print(" counts y = ");
  Serial.print(y);
  Serial.print(" counts z = ");
  Serial.println(z);
  delay(1000);
}
