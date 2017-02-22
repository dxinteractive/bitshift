/*
 * uistate_inputs
 * UI state for displaying readings from inputs for analysis / debugging
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_UISTATE_INPUTS_H
#define BITSHIFT_UISTATE_INPUTS_H

#include "uistate.h"

class BitshiftUIStateInputs: public BitshiftUIState
{
  public:
    BitshiftUIStateInputs();
    ~BitshiftUIStateInputs() {}

    virtual void render();
    virtual void eventButton(int id, int value);
    virtual void eventAnalog(int id, float value);

  private:
    int buttonId = -1;
    float analogValues[10];
};

#endif
