#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
//Author: VS

char incomingByte;  // incoming data
int  LED = 13;      // LED pin

String content = "";
char character;

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
 
void setup() 
{
  Serial1.begin(9600); // initialization
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  //Serial.println("Press 1 to LED ON or 0 to LED OFF...");
  matrix.begin(0x70);  // pass in the address
  matrix.clear();
  matrix.writeDisplay();
}
 
void loop() 
{
  //Serial.println("Bluetooth");
  //Serial1.println("HC-05");
  while(Serial1.available()) 
  {
      character = Serial1.read();
      content.concat(character);
  }
  //Serial.println(content);
  
  
  if (content.length() >= 1) 
  {
    Serial.println(content);
    //int led = content.toInt();  // use atoi to convert the string to an int
    if (content[0] >=65 && content[0] <=122) {
          matrix.setTextSize(1);
          matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
          matrix.setTextColor(LED_ON);
          for (int8_t x=0; x>=-36; x--) {
            matrix.clear();
            matrix.setCursor(x,0);
            matrix.print(content);
            matrix.writeDisplay();
            delay(100);
          }
    }

    content = "";
    delay(50); 
  }
}
