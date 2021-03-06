/**
* \defgroup SenseMeButton Driver for SenseMe Button
* 
* @{
*/

/**
* \file 
* 		SenseMe Button driver
* \author
* 		Venus Shum
*/

#ifndef __SenseMeBUTTON_H__
#define __SenseMeBUTTON_H__

#include <Arduino.h>
#include <SenseMe.h>

#define DEBOUNCE_DELAY 50

// Needed to ensure correct linkage between C++ and C linkage of ISR
//extern "C" void INT6_vect(void) __attribute__ ((signal));


class SenseMeButtonClass 
{
	private:
		/*
		 * Timings on this need to be stored as longs, simply because millis(),
		 * which we use for timing, returns a long and we would otherwise encounter
		 * problems with wrapping
		 */
		long lastChangeTime;   // The last time the button input changed
		bool buttonState; 		// Whether the button is currently pressed
		bool fallingEdge;		// Whether we're looking for a falling or rising edge in the ISR
		bool wasPressedState;	// Whether the button has been pressed since we last checked
		bool wasReleasedState;	// Whether the button has been released since we last checked
		long debounceDelayTime;			// How long we will wait until saying the switch is settled
		bool lastState;

	public:
		SenseMeButtonClass();
		//bool buttonInterrupted;
		void begin(long debounceDelay=DEBOUNCE_DELAY);
		void end();
		void reset();
		bool isPressed();
		void waitUntilPressed();
		void waitUntilReleased();
		bool wasPressed();
		bool wasReleased();
		static void timercallback();
};

extern SenseMeButtonClass SenseMeButton;


#endif

/** @} */
