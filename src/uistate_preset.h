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
    BitshiftUIStatePreset():
      BitshiftUIState() {}
    ~BitshiftUIStatePreset() {}

    // set total number of analog inputs
    // get total number of params from audio

    virtual void onEvent(int id);

  protected:
  	int paramOffset;
};

#endif