#include <SenseMeThermistor.h>
#include <Wire.h>
#include <SenseMeAccelerometer.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include <Adafruit_NeoPixel.h>

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

#define PIN            10  //pin for NeoPixel
#define NUMPIXELS      1  // How many NeoPixel are attached to the Arduino?
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

boolean setNum = false;

//Bluetooth
String content = "";
//char * content;
char character;
char incomingByte;  // incoming data

boolean DEBUG = false;
uint8_t brightness=0, dir=0;
uint8_t state=0, r=0, g=0, b=255;

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
    B00111000 },
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
  matrix.writeDisplay();
  randomSeed(analogRead(0));
  setNum = false;
  Serial1.begin(9600); // initialization
  //Serial.begin(9600);
  pixels.begin();
  pixels.setPixelColor(0, pixels.Color(0,0,0)); // Moderately bright green color.
  
}

long ran;

void loop()
{   
    float xyz[3];
    SenseMeAccelerometer.xyz(xyz);
    if (DEBUG) {
      Serial.print("Accelerometer x=");
      Serial.print(xyz[0]);
      Serial.print(", y=");
      Serial.print(xyz[1]);
      Serial.print(", z=");
      Serial.println(xyz[2]);
    }
    
    
    if (xyz[0] > 0.2 || xyz[0] < -0.2) {
      //mode 1
      matrix.setRotation(0);

        matrix.clear(); 
        matrix.drawBitmap(0, 0, thermo_bmp, 8, 8, LED_ON);
        matrix.writeDisplay();
        pulseColor(0,255,0);
        tempLight();
        //delay(1000);

      
      setNum = false;
    }
    else if (xyz[1] > 0.2 || xyz[1] < -0.2) {
      //mode 2
      //demoMatrix();
      matrix.setRotation(2);
      if (setNum==false) {
         ran = random(3);
         setNum = true;
         Serial.println(ran);
     }
     luckyFace(ran);
      //setNum = false;
    }
    else if (xyz[2] > 0.2 || xyz[2] < -0.2) {
     //mode 3
     /*
     if (setNum==false) {
         long ran = random(3);
         luckyFace(ran);
         setNum = true;
         Serial.println(ran);
     }
     */
     //matrix.clear();
     matrix.setRotation(3);  //Bluetooth symbol on the top, the matrix is now facing this way. 
     matrix.drawBitmap(0, 0, blue_bmp, 8, 8, LED_ON);
     matrix.writeDisplay();
     //delay(1000);
     pulseColor(0,0,255); 
      //matrix.clear();
     //matrix.writeDisplay();
     Bluetooth();
     setNum = false;
    }
    
    //tempLight();
    
    //
}


void setColor() {
    pixels.setBrightness(brightness),
    pixels.setPixelColor(0, pixels.Color(r,g,b)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    if (dir == 0)   {
        if (brightness<255) brightness++;
        else 
          dir = 1;
    }
    else {
        if (brightness > 0)
          brightness --;
        else {
          dir = 0;
          switch(state) {
            case 0:
              state = 1; r=0; g=255; b=0; break;
            case 1:
              state = 2; r=255; g=0; b=0; break;
            case 2:
              state = 3; r=255; g=255; b=255; break;
            case 3:
              state = 0; r=0; g=0; b=255; break;
          }
    }
    }
}


