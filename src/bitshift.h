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

 // include specifics so they are linked
 #include "displays/display_SSD1306.h"

class Bitshift
{
  public:
  	Bitshift();
  	~Bitshift();

    void setup();
    void update();
    
  private:
  	BitshiftAudio audio;
  	BitshiftUI ui;
};

#endif
