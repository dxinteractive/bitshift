/*
 * bitshift
 * Main import for Deeep Bitshift digital guitar pedal UI library
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#ifndef BITSHIFT_H
#define BITSHIFT_H

#include "audio.h"
#include "ui.h"
#include "input_consts.h"

// include specific concrete classes so they are linked and can be used from outside this library
#include "ui_default.h"
#include "input_default.h"
#include "display_SSD1306.h"
#include "preset_tremolo.h"

class Bitshift
{
  public:
  	Bitshift(BitshiftAudio& audio, BitshiftUI& ui):
  		audio(&audio),
  		ui(&ui) {}

    void setup();
    void update();

  private:
  	BitshiftAudio* audio;
  	BitshiftUI* ui;
};

#endif
