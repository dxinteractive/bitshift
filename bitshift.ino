/*
 * bitshift.ino
 * Arduino / Teensy dev project file for Deeep Bitshift digital guitar pedal
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
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
// input - analog
const int ANALOG_TOTAL = 5;
const int ANALOG_PINS[ANALOG_TOTAL] = {A2, A3, A6, A7, A11};
const int ANALOG_VISIBLE = 4;
// ^ this signifies that the first 4 analog inputs should display their parameter changes on the UI (use with knobs)
// Any analog pins after that will not cause any UI changes (use with expression pedals and control voltages)

// input - buttons
const int BUTTONS_PIN = A10;
const int BUTTONS_TOTAL = 7;
const int BUTTONS_VISIBLE = 4;
// ^ this signifies that the first 4 buttons should display their parameter changes on the UI (up, down, back and select)
// Any button assign values higher that that will not cause any UI changes and should usually not be affected by 

const int BUTTONS_VALUES[BUTTONS_TOTAL] = {
  0,
  182,
  353,
  508,
  605,
  764,
  855
};
// ^ analog readings when each button is pressed, in ascending order

const int BUTTONS_ASSIGN[BUTTONS_TOTAL] = {
  BUTTON_DOWN, // 0
  BUTTON_BACK, // 182
  BUTTONS_VISIBLE + 1, // 353 (tap 2)
  BUTTONS_VISIBLE + 2, // 508 (tap 3)
  BUTTON_SELECT, // 605
  BUTTON_UP, // 764
  BUTTONS_VISIBLE // 855 (tap 1)
};
// ^ buttons corresponding to each of the BUTTON_VALUES

BitshiftInputDefault input(
  ANALOG_PINS,
  ANALOG_TOTAL,
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

// input
AudioInputI2S audioIn;

// presets
const int PRESETS_TOTAL = 2;
BitshiftPresetTremolo tremolo;
BitshiftPresetBitcrusher bitcrusher;
BitshiftPreset* presets[PRESETS_TOTAL] = {
  &tremolo,
  &bitcrusher
};

// output
AudioOutputI2S audioOut;

// audio
BitshiftAudioDefault audio(
  audioIn,
  0,
  presets,
  PRESETS_TOTAL,
  audioOut,
  0
);

// ui
BitshiftUIDefault ui(
  audio,
  input,
  display,
  new BitshiftUIStatePreset(),
  BUTTONS_VISIBLE,
  ANALOG_VISIBLE
);

// bitshift
Bitshift bitshift(audio, ui);

void setup() {
  Serial.begin(9600);
  // while(!Serial) { delay(1000); }

  bitshift.setup();
}


void loop() {
  bitshift.update(millis());
  
  /*Serial.print("CPU: ");
  Serial.print(AudioProcessorUsage());
  Serial.print(",");
  Serial.print(AudioProcessorUsageMax());
  Serial.print("    ");
  Serial.print("Memory: ");
  Serial.print(AudioMemoryUsage());
  Serial.print(",");
  Serial.print(AudioMemoryUsageMax());
  Serial.println("");*/
}

