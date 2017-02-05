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
#include "uistate_preset.h"

class BitshiftUIDefault: public BitshiftUI
{
  friend class BitshiftUIState;
  public:
    BitshiftUIDefault(
      BitshiftAudio& audio,
      BitshiftInput& input,
      BitshiftDisplay& display,
      BitshiftUIState* initialState,
      int analogVisible,
      int buttonsVisible
    );
    ~BitshiftUIDefault() {}
};

#endif
