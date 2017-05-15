/*
 * Arduino / Teensy dev project file for Deeep Bitshift digital guitar pedal
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
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
#include "bitshift/bitshift.h"
//#include <bitshift-presets.h>

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

// set pins and consts for your specific setup
// input - analog
const int ANALOGS_TOTAL = 5;
const int ANALOGS_PINS[ANALOGS_TOTAL] = {A2, A3, A6, A7, A11};
const int ANALOGS_ASSIGN[ANALOGS_TOTAL] = {
  ANALOG_VISIBLE,
  ANALOG_VISIBLE + 1,
  ANALOG_VISIBLE + 2,
  ANALOG_VISIBLE + 3,
  ANALOG_EXP
};

// ^ this signifies that the first 4 analog inputs (0)
// should display their parameter changes on the UI (use with knobs).

// The 5th one (1) will affect params after being assigned
// and will not cause any UI changes. To be used with inputs
// like expression pedals and control voltages.

// input - buttons
const int BUTTONS_PIN = A10;
const int BUTTONS_TOTAL = 7;
// ^ this signifies that the first 4 buttons should display
// their parameter changes on the UI.
// In a standard setup these buttons are up, down, back and select.
// Any button_assign values higher that that
// will not cause any UI changes.

// analog readings when each button is pressed, in ascending order
const int BUTTONS_VALUES[BUTTONS_TOTAL] = {
  0,
  182,
  353,
  508,
  605,
  764,
  855
};

// buttons corresponding to each of the BUTTON_VALUES
const int BUTTONS_ASSIGN[BUTTONS_TOTAL] = {
  BUTTON_DOWN, // 0
  BUTTON_BACK, // 182
  BUTTON_TAP + 1, // 353
  BUTTON_TAP + 2, // 508
  BUTTON_SELECT, // 605
  BUTTON_UP, // 764
  BUTTON_TAP // 855
};

BitshiftInputDefault input(
  ANALOGS_PINS,
  ANALOGS_TOTAL,
  BUTTONS_PIN,
  BUTTONS_TOTAL,
  BUTTONS_VALUES,
  BUTTONS_ASSIGN
);

// audio
// Always instanciate audio objects in the order
// that the audio signal will flow through them

// audio input
AudioInputI2S audioIn;

// audio presets
const int PRESETS_TOTAL = 3;
BitshiftPresetTremolo tremolo;
BitshiftPresetBitcrusher bitcrusher;
BitshiftPresetFilter filter;
BitshiftPreset* presets[PRESETS_TOTAL] = {
  &tremolo,
  &bitcrusher,
  &filter
};

// audio output
AudioOutputI2S audioOut;

// audio object
BitshiftAudioDefault audio(
  audioIn,
  0,
  presets,
  PRESETS_TOTAL,
  audioOut,
  0
);

// ui
BitshiftUIStatePreset* baseUIState = new BitshiftUIStatePreset(
  ANALOGS_ASSIGN,
  ANALOGS_TOTAL
);

BitshiftUIDefault ui(
  audio,
  input,
  display,
  new BitshiftUIStateSplash(baseUIState)
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
}

