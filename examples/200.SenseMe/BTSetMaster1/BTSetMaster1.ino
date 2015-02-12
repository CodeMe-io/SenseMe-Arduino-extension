//#include <SoftwareSerial.h>
#include <SHT2x.h>
#include <SenseMe.h>
#include "pitch.h"
#include <Wire.h>
int melody1[] = { NOTE_C5,  NOTE_C5,  NOTE_G5,  NOTE_G5,  NOTE_A5, NOTE_A5,  NOTE_G5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5} ;
int beats1[]  = { 4,4,4,4,4,4,2, 4, 4, 4, 4, 4, 4, 1 } ; 

// AT Commands demo
// This example shows how to use AT commands with Engduino
// extension Bluetooth module based on HC-05. The AT commands
// are used to change internal parameters of the BT module, like 
// name, role (master/slave), baudrate speed, etc.
//
// IMPORTANT: To enable AT commands KEY and RST jumpers on the 
// bottom side of BT extension board needs to be connected.
//
// This example will check for board version and change the default
// name from "HC-05" to the "EBT-123". All communication between 
// Engduino and BT extension board is forward to the PC serial 
// terminal.
//
// Engduino team: support@engduino.org
// Engduino site: http://www.engduino.org/

// Define I/O pin numbers.
int gLedPin = 9;
int gKeyPin = 5;
int gResetPin = 4;
uint8_t masterStage = 0;

int ATdelay = 100;
int retDelay = 1000;

//function declarations
void BtSetCmdMode(int);
void BtReset(void);
void BtSendCommand(String);

void setup() 
{
  // Initialize I/Os
  pinMode(gLedPin, OUTPUT);
  pinMode(gResetPin, OUTPUT);
  pinMode(gKeyPin, OUTPUT);
  digitalWrite(gResetPin, LOW);
  digitalWrite(gKeyPin, LOW);
  //Play a welcome tone
  //littleStar();
  
  delay(3000);

  Serial.begin(9600);
  Serial.println("AT Commands demo"); 
  
  
  BtReset();
  //BtGetDeviceAddr();
  //BtReset();
  
  
  BTSetMaster();
  
}

uint8_t OKstage = 0;
String ret = "";
char myChar = 65;
int count=0;
char * message = "...A message from cube B";
//String message = "...A message from cube B";
int msgPtr = 0;
void loop()
{
  if (Serial1.available())
  {
    // Forward everything to the PC terminal.
    char tmpChar = Serial1.read();
    ret.concat(tmpChar);
    Serial.print(tmpChar);

  }
  
  //use counter rather than delay for non-blocking codes
 
  count++;
  //int len = strlen(message);
  Serial1.print(message);
  Serial1.println("\r\n");
  delay(2000);
  
  int sensorReading = SHT2x.GetHumidity();
      Serial1.print("Humidity: ");
      Serial1.print(sensorReading);
      Serial1.println("\r\n");
  delay(1000);
  /*
  int len = message.length();
  if (count>=10000) {
    if (msgPtr < 10) {  //do it too often will crash
      msgPtr  ++;
    }
    else {
      
      msgPtr = 0;
    }
    */
    /*
    if (msgPtr < len) {
      myChar = message[msgPtr];
      //Serial1.print(myChar);
      Serial1.println(
      //Serial.println("sending character"+myChar);
      myChar++;
      count=0;
      msgPtr ++;
    }
    if (msgPtr == len) {
      int sensorReading = SHT2x.GetHumidity();
      Serial1.print("Humidity: ");
      Serial1.println(sensorReading);
      msgPtr ++;
    }
    else if (msgPtr < len+10) {
          msgPtr ++;
    }
    else {
      msgPtr = 0;
    }
  */
  
  
}


void littleStar(){
    // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 14; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/beats1[thisNote];
    tone(SPEAKER_PIN, melody1[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(SPEAKER_PIN);
  }
}







