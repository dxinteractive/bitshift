/*
 * uistate_usage
 * UI state for displaying CPU and processor usage for analysis / debugging
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_UISTATE_USAGE_H
#define BITSHIFT_UISTATE_USAGE_H

#include "uistate.h"

class BitshiftUIStateUsage: public BitshiftUIState
{
  public:
    BitshiftUIStateUsage():
      BitshiftUIState() {}
    ~BitshiftUIStateUsage() {}

    virtual void update(unsigned long ms);
    virtual void render();
    virtual void eventButton(int id, int value);
    virtual void eventAnalog(int id, float value);

  private:
    unsigned long ms = 0;
};

#endif
