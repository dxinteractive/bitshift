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
#include "input.h"
#include "ui.h"

// include specific concrete classes so they are linked and can be used from outside this library
#include "display_SSD1306.h"
#include "input_default.h"

class Bitshift
{
  public:
  	Bitshift();
  	~Bitshift();

    void setup();
    void update();
    
  private:
  	BitshiftAudio audio;
  	//BitshiftInput input;
  	BitshiftUI ui;
};

#endif
