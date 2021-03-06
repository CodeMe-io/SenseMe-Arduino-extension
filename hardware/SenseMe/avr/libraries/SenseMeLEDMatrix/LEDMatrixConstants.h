#include <Arduino.h>

#ifndef _LEDMATRIXCONSTANTS_H_
#define _LEDMATRIXCONSTANTS_H_

const uint8_t PROGMEM
  smile_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100},
	
  neutral_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100 },
	
  frown_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100 },

  laugh_bmp[] =
  { B00111100,
    B01100110,
    B11011011,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 },
	
  yawn_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01011010,
    B00111100 },
	
  sleep_bmp[] =
  { B00000001,
    B00000011,
    B00011100,
    B00001000,
    B00011100,
    B11100000,
    B01000000,
    B11100000 },


  blue_bmp[] =
  { B00011000,
    B10010100,
    B01010010,
    B00110100,
    B00111000,
    B01010100,
    B10010010,
    B00011100 },

  thermo_bmp[] =
  { B00111000,
    B00101110,
    B00101000,
    B00101110,
    B00101000,
    B01000100,
    B01000100,
    B00111000 };

#endif