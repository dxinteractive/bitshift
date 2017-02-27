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
#include "input_consts.h"

class BitshiftUIStatePreset: public BitshiftUIState
{
  public:
    BitshiftUIStatePreset(
      const int* analogsAssign,
      int analogsTotal
    );
    ~BitshiftUIStatePreset() {}

    virtual void render();
    virtual void eventButton(int id, int value);
    virtual void eventAnalog(int id, float value);

  protected:
    void analogOffset();

    const int* analogsAssign;
    int analogsTotal;
    int analogTotalsByType[ANALOG_TYPES_TOTAL];

  	int analogParamOffset = 0;
};

#endif
