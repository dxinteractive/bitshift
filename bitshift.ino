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

// SSD1306 oled display
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// include bitshift libraries
#include <bitshift.h>
//#include <bitshift-presets.h>



// set pins and consts for your specific setup
// input
const int ANALOG_TOTAL = 5;
const int ANALOG_PINS[ANALOG_TOTAL] = {A2, A3, A6, A7, A11};
const int BUTTONS_PIN = A10;
const int BUTTONS_TOTAL = 7;
const int BUTTONS_VALUES[BUTTONS_TOTAL] = {0, 182, 353, 508, 605, 764, 855};
// ^ analog readings when each button is pressed, in ascending order

const int BUTTONS_ASSIGN[BUTTONS_TOTAL] = {5, 0, 1, 4, 6, 2, 3};
// ^ index of BUTTON_VALUES corresponding to each button in the following order:
// up, down, back, select, tap, tap 2, tap 3
// e.g. "up" is to be triggered when BUTTON_VALUES index 5 (~764) is read

BitshiftInputDefault input(
  ANALOG_TOTAL,
  ANALOG_PINS,
  BUTTONS_PIN,
  BUTTONS_TOTAL,
  BUTTONS_VALUES,
  BUTTONS_ASSIGN
);

// display
const int PIN_SCREEN_SID = 4;
const int PIN_SCREEN_SCLK = 3;
const int PIN_SCREEN_DC = 2;
const int PIN_SCREEN_RST = 1;
const int PIN_SCREEN_CS = 0;

BitshiftDisplaySSD1306 display(
  PIN_SCREEN_SID,
  PIN_SCREEN_SCLK,
  PIN_SCREEN_DC,
  PIN_SCREEN_RST,
  PIN_SCREEN_CS
);

// audio
BitshiftAudio audio;

// ui
BitshiftUIDefault ui(audio, input, display);

// bitshift
Bitshift bitshift(audio, ui);

void setup() {
  Serial.begin(9600);
  //while(!Serial) delay(1000);
  
  bitshift.setup();
}


void loop() {
  bitshift.update();
  delay(10);
}

