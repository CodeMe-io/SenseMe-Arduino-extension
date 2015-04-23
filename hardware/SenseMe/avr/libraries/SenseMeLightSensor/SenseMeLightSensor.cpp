/**
* \addtogroup SenseMeLight
*
* This is the driver code for Light on the SenseMe
* In v2.1 this magnetometer is a Avago ADPS-9008
*
* @{
*/

/**
* \file 
* 		SenseMe Light Sensor driver
* \author
* 		codeme.io
*/


#include "pins_arduino.h"
#include "SenseMeLightSensor.h"


/*---------------------------------------------------------------------------*/
/**
* \brief Constructor
* 
* C++ constructor for this class. Empty.
*/
SenseMeLightSensorClass::SenseMeLightSensorClass()
{
}

/*---------------------------------------------------------------------------*/
/**
* \brief begin function - must be called before using other functions
*
* Does nothing in this case
*/
void SenseMeLightSensorClass::begin() 
{	
	pinMode(LIGHTSENSOR, INPUT);
}

/*---------------------------------------------------------------------------*/
/**
* \brief end function - switch off the light sensor
*
* Does nothing in this case
*/
void SenseMeLightSensorClass::end() 
{	
}

/*---------------------------------------------------------------------------*/
/**
* \brief lightLevel function - returns light level (10 bit value)
*
* This function returns the light level. Since the input is an analogue one
* and the ADC gives a 10 bit value, it returns a 16 bit integer.
*  
*/
uint16_t SenseMeLightSensorClass::lightLevel() 
{	
	return analogRead(LIGHTSENSOR);
}

/*---------------------------------------------------------------------------*/
/*
 * Preinstantiate Objects
 */ 
SenseMeLightSensorClass SenseMeLightSensor = SenseMeLightSensorClass();

/** @} */
