// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            10

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      1

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 10; // delay for half a second

void setup() {
  pinMode(PIN, OUTPUT);  
  digitalWrite(PIN, HIGH);
  pixels.begin(); // This initializes the NeoPixel library.
}

uint8_t brightness=0;

uint8_t color[3];

void loop() {
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  pulseColor(0,0,255);
  pulseColor(0,255,0);
  pulseColor(255,0,0);
  pulseColor(255,0,255);
}

void pulseColor(uint8_t r, uint8_t g, uint8_t b) {

  for(int i=0;i<255;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setBrightness(i),
    pixels.setPixelColor(0, pixels.Color(r,g,b)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
  }
  
  for(int i=255;i>=0;i--){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setBrightness(i),
    pixels.setPixelColor(0, pixels.Color(r,g,b)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
  }
  
}
