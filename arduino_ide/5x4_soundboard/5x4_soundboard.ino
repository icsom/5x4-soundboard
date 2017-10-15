/*
  Keypad 
  5x4 tact-switch matrix
*/
#include <Keypad.h>

const byte ROWS = 5; //four rows
const byte COLS = 4; //four columns
char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'},
  {'G','H','I','J'}
};
byte rowPins[ROWS] = {4, 5, 6, 7, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 10, 11, 12}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(2, 3); // RX, TX for the communication with DFPlayer mini arduino TX <--- 1K Ohm rsisortor ---> RX DFPLayer
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);
unsigned long timer = millis();
int vol=30;



void setup() { 

  mySoftwareSerial.begin(9600);
  Serial.begin(9600);
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.setTimeOut(500); 
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  myDFPlayer.volume(vol);
}

void loop()
{
  char customKey = customKeypad.getKey();
   
  if (customKey){

    switch (customKey) {
        case '0':
            myDFPlayer.play(1);
          break;
        case '1':
            myDFPlayer.play(2);
          break;
        case '2':
            myDFPlayer.play(3);
          break;
        case '3':
            myDFPlayer.play(4);
          break;
        case '4':
            myDFPlayer.play(5);
          break;
        case '5':
            myDFPlayer.play(6);
          break;
        case '6':
            myDFPlayer.play(7);
          break;
        case '7':
            myDFPlayer.play(8);
          break;
        case '8':
            myDFPlayer.play(9);
          break;
        case '9':
            myDFPlayer.play(10);
          break;
        case 'A': 
            myDFPlayer.play(11);
          break;
        case 'B':
            myDFPlayer.play(12);
          break;
        case 'C':
            myDFPlayer.play(13);
          break;
        case 'D':
            myDFPlayer.play(14);
          break;
        case 'E':
            myDFPlayer.play(15);
          break;
        case 'F':
            myDFPlayer.play(16);
          break;
        case 'G':;
            myDFPlayer.previous();
          break;
        case 'H':
            myDFPlayer.next();
          break;
        case 'I':
            if(vol > 0) {vol--;}
          break;
        case 'J':
            if(vol < 30) {vol++;}
          break;
      }
      myDFPlayer.volume(vol);
  }
}

