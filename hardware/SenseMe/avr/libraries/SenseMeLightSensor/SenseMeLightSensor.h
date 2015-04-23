/**
* \defgroup SenseMeLightSensor Driver for SenseMe Light Sensor
* 
* @{
*/

/**
* \file 
* 		SenseMe Light sensor driver
* \author
* 		Venus Shum/support@SenseMe.org
*/

#ifndef __SENSEMELIGHTSENSOR_H__
#define __SENSEMELIGHTSENSOR_H__

#include <stdio.h>
#include <Arduino.h>
#include <SenseMe.h>




/***********************************************************************************************\
* Public prototypes
\***********************************************************************************************/

class SenseMeLightSensorClass 
{
	private:
	
	public:
		SenseMeLightSensorClass();
		void    begin();
		void    end();
		uint16_t lightLevel();

};

extern SenseMeLightSensorClass SenseMeLightSensor;

#endif

/** @} */
