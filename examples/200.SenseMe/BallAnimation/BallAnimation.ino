
#include <SenseMeLEDMatrix.h>
/* A simple animation showing a dot bouncing up and down*/

// for version 1 cubes 
// #include <SenseMeMatrixOne.h> 

#include <Wire.h>

static const uint8_t PROGMEM
  BM1[] =
  { B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00010000 },
BM2[] =
  { B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00010000,
    B00000000 },
BM3[] =
  { B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00010000,
    B00000000,
    B00000000 },
BM4[] =
  { B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00010000,
    B00000000,
    B00000000,
    B00000000 };


    
void setup() {
  // put your setup code here, to run once:
  SenseMeLEDMatrix.begin();  
  SenseMeLEDMatrix.clear();
  SenseMeLEDMatrix.writeDisplay();
}

#define DELAYTIME 100	//


void loop() {
  // put your main code here, to run repeatedly:
  drawMap((unsigned char *)&BM1);
  delay(DELAYTIME);
  drawMap((unsigned char *)&BM2);
  delay(DELAYTIME);
  drawMap((unsigned char *)&BM3);
  delay(DELAYTIME);
  drawMap((unsigned char *)&BM4);
  delay(DELAYTIME);
  
  drawMap((unsigned char *)&BM4);
  delay(DELAYTIME);
  drawMap((unsigned char *)&BM3);
  delay(DELAYTIME);
  drawMap((unsigned char *)&BM2);
  delay(DELAYTIME);
  drawMap((unsigned char *)&BM1);
  delay(DELAYTIME);
  
}

void drawMap(unsigned char* myBitMap) {
  // Wipe out previous 
  SenseMeLEDMatrix.clear();
  SenseMeLEDMatrix.writeDisplay();
  SenseMeLEDMatrix.drawBitmap(0, 0, myBitMap, 8, 8, LED_ON);
  SenseMeLEDMatrix.writeDisplay();


}


