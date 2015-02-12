/**
* \defgroup SenseMeThermistor Thermistor Driver 
* 
* @{
*/

/**
* \file 
* 		Thermistor driver
* \author
* 		
*/

#ifndef __SENSEMETHERMISTOR_H__
#define __SENSEMETHERMISTOR_H__

#include <Arduino.h>
#include <SenseMe.h>

enum temperatureUnits {
  CELSIUS,
  KELVIN,
  FAHRENHEIT
};

class SenseMeThermistorClass 
{
	private:

	public:
		SenseMeThermistorClass();
		void     begin();
		void     end();
		float    temperature(temperatureUnits units=CELSIUS);
		float    temperature(temperatureUnits units, float B, float T0, float R0, float R_Balance);
		uint16_t temperatureRaw();
};

extern SenseMeThermistorClass SenseMeThermistor;

#endif

/** @} */
