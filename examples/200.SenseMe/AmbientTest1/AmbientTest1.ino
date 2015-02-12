/****************************************************************
 * ReadSHT2x
 *  An example sketch that reads the sensor and prints the
 *  relative humidity to the PC's serial port
 *
 *  Tested with:
 *    - SHT21-Breakout Humidity sensor from Modern Device
 *    - SHT2x-Breakout Humidity sensor from MisensO Electronics
 ***************************************************************/

#include <Wire.h>
#include <SHT2x.h>
#include <SenseMeLight.h>

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  SenseMeLight.begin();
}

void loop()
{
  uint16_t l;
  Serial.print("Humidity(%RH): ");
  Serial.print(SHT2x.GetHumidity());
  Serial.print("     Temperature(C): ");
  Serial.print(SHT2x.GetTemperature());
  
  Serial.print("     Light Value: ");
  l=SenseMeLight.lightLevel();
  Serial.println(l);
  
  delay(1000);
}

