/*
 * bitshift
 * Main import for Deeep Bitshift digital guitar pedal UI library
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_H
#define BITSHIFT_H

#include "audio.h"
#include "ui.h"
#include "preset.h"
#include "input_consts.h"

// include specific concrete classes so they are linked and can be used from outside this library
#include "audio_default.h"
#include "ui_default.h"
#include "input_default.h"
#include "display_SSD1306.h"
#include "uistate_splash.h"

 // presets for testing - move these out to their own repo once ready
#include "preset_tremolo.h"
#include "preset_bitcrusher.h"

class Bitshift
{
  public:
  	Bitshift(BitshiftAudio& audio, BitshiftUI& ui):
  		audio(&audio),
  		ui(&ui) {}

    void setup();
    void update(unsigned long ms);

  private:
  	BitshiftAudio* audio;
  	BitshiftUI* ui;
};

#endif
