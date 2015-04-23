#include <Adafruit_NeoPixel.h>
#include <SenseMe.h>
#include <SenseMeNeopixel.h>

#define LEDnum	0

SenseMeNeopixelClass::SenseMeNeopixelClass() : Adafruit_NeoPixel(1, PIXELPIN, NEO_GRB + NEO_KHZ800){
	setPixelColor(LEDnum, Color(0,0,0)); 
}

void SenseMeNeopixelClass::begin(){

}

void SenseMeNeopixelClass::setColor(uint8_t r, uint8_t g, uint8_t b){
	setPixelColor(LEDnum, r,g,b);
	show();
}

void SenseMeNeopixelClass::setColor(uint32_t c){
	setPixelColor(LEDnum, c);
	show();
}

void SenseMeNeopixelClass::setColor(uint8_t r, uint8_t g, uint8_t b,uint8_t brightness){
	setBrightness(brightness);
	setPixelColor(LEDnum, r,g,b);
	show();
}

SenseMeNeopixelClass SenseMeNeopixel = SenseMeNeopixelClass();
