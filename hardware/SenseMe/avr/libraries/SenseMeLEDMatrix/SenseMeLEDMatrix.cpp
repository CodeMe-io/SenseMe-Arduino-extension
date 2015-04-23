#include <SenseMeLEDMatrix.h>

SenseMeLEDMatrixClass::SenseMeLEDMatrixClass(void) : Adafruit_8x8matrix() {
}

void SenseMeLEDMatrixClass::begin(void) {
  i2c_addr = 0x70;

  Wire.begin();

  Wire.beginTransmission(i2c_addr);
  Wire.write(0x21);  // turn on oscillator
  Wire.endTransmission();
  blinkRate(HT16K33_BLINK_OFF);
  
  setBrightness(15); // max brightness
}

SenseMeLEDMatrixClass SenseMeLEDMatrix = SenseMeLEDMatrixClass();