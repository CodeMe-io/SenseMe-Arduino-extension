#include <SenseMeThermistor.h>
#include <Wire.h>
#include <SenseMeAccelerometer.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"


// Temperature LEDs
//
// In this sketch, the colour of the LEDs changes on a linear scale
// from blue (cold) to red (hot) via mixtures of the two colours in
// proportion to the temperature. The temperatures that define blue
// and red are given in the #defines below. Temperatures outside the
// range, are capped so those lower than TBLUE are rendered as blue
// and those higher than TRED are red.
//
// The sketch illustrates the use of both thermistor and LEDs.
//

// Define the temperatures of blue and red.
#define TBLUE 25
#define TRED  35
#define TRANGE (TRED - TBLUE)

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

boolean setNum = false;

static const uint8_t PROGMEM
  smile_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 },
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
    B00111100 };
    
void setup()
{
  Serial.begin(115200);
  SenseMeThermistor.begin();
  
  matrix.begin(0x70);  // pass in the address
  SenseMeAccelerometer.begin();
  matrix.clear();
  randomSeed(analogRead(0));
  setNum = false;
}



void loop()
{   
    float xyz[3];
    SenseMeAccelerometer.xyz(xyz);
    
    Serial.print("Accelerometer x=");
    Serial.print(xyz[0]);
     Serial.print(", y=");
    Serial.print(xyz[1]);
     Serial.print(", z=");
    Serial.println(xyz[2]);
    
    if (xyz[0] > 0.2 || xyz[0] < -0.2) {
      //mode 1
      tempLight();
      setNum = false;
    }
    else if (xyz[1] > 0.2 || xyz[1] < -0.2) {
      //mode 2
      demoMatrix();
      setNum = false;
    }
    else if (xyz[2] > 0.2 || xyz[2] < -0.2) {
     //mode 3
     if (setNum==false) {
         long ran = random(3);
         luckyFace(ran);
         setNum = true;
         Serial.println(ran);
     }
    }
    
    //tempLight();
    
    delay(50);

}



