/*
 * uistate_preset
 * UI state for displaying preset parameters, designed to be the default view
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
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

    virtual void render();
    virtual void eventButton(int id, int value);
    virtual void eventAnalog(int id, float value);

  protected:
    void analogOffset();
  	int analogParamOffset = 0;
};

#endif
