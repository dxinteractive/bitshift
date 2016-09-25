/*
 * ui_default
 * Default set of UI states for input handling and updating audio objects and display
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-. 
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : : 
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_; 
 */


#ifndef BITSHIFT_UI_DEFAULT_H
#define BITSHIFT_UI_DEFAULT_H

#include "ui.h"
#include "uistate.h"

class BitshiftUIDefault: public BitshiftUI
{
  public:
    BitshiftUIDefault(
      BitshiftAudio& audio,
      BitshiftInput& input,
      BitshiftDisplay& display
    ):
      BitshiftUI(audio, input, display, 0) {}
    ~BitshiftUIDefault() {}

    static const int UISTATE_PRESET = 0;
    static const int UISTATE_PARAM = 1;
    static const int UISTATE_MENU_MAIN = 1;

    virtual BitshiftUIState* createState(int id);
};

#endif
