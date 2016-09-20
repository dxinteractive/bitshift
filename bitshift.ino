/*
 * bitshift.ino
 * Arduino / Teensy dev project file for Deeep Bitshift digital guitar pedal
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift-ui
 * 
 * .-.    _  .-.      .-.    _  .--. .-. 
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : : 
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_; 
 */

/* 
 * 3rd party includes
 * all includes used in the Bitshift library's
 * .cpp and .h files must be listed here
 * for the Arduino IDE to compile 
 */

// audio
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// stl
// https://forum.pjrc.com/threads/23467-Using-std-vector?p=69787&viewfull=1#post69787
#include <stack>

// SSD1306 oled display
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// include bitshift libraries
#include <bitshift.h>
//#include <bitshift-effects.h>

// set pins and consts for your specific setup
const int PIN_SCREEN_SID = 4;
const int PIN_SCREEN_SCLK = 3;
const int PIN_SCREEN_DC = 2;
const int PIN_SCREEN_RST = 1;
const int PIN_SCREEN_CS = 0;

BitshiftDisplaySSD1306 display(PIN_SCREEN_SID, PIN_SCREEN_SCLK, PIN_SCREEN_DC, PIN_SCREEN_RST, PIN_SCREEN_CS);
Bitshift bitshift;

void setup() {
  Serial.begin(9600);
  //while(!Serial) delay(1000);
  
  bitshift.setup();
}


void loop() {
  bitshift.update();
}

