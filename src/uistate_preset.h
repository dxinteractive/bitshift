/*
 * uistate_preset
 * UI state for displaying and altering preset parameters
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */


#ifndef BITSHIFT_UISTATE_PRESET_H
#define BITSHIFT_UISTATE_PRESET_H

#include "uistate.h"

class BitshiftUIStatePreset: public BitshiftUIState
{
  public:
    BitshiftUIStatePreset(int a):
      BitshiftUIState(),
      a(a) {}
    ~BitshiftUIStatePreset() {}

    // set total number of analog inputs
    // get total number of params from audio

    virtual void render();
    virtual void onEvent(int id, int value);
    virtual void onEvent(int id, float value);

  protected:
    int a;
  	int paramOffset;
};

#endif
