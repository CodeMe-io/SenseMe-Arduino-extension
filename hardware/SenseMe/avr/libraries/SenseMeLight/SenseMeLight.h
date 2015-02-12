/**
* \defgroup SenseMeLight Driver for SenseMe Light Sensor
* 
* @{
*/

/**
* \file 
* 		SenseMe Light sensor driver
* \author
* 		SenseMe team: support@SenseMe.org
*/

#ifndef __SENSEMELIGHT_H__
#define __SENSEMELIGHT_H__

#include <stdio.h>
#include <Arduino.h>
#include <SenseMe.h>




/***********************************************************************************************\
* Public prototypes
\***********************************************************************************************/

class SenseMeLightClass 
{
	private:
	
	public:
		SenseMeLightClass();
		void    begin();
		void    end();
		uint16_t lightLevel();

};

extern SenseMeLightClass SenseMeLight;

#endif

/** @} */
