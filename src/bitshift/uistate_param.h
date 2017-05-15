/*
 * uistate_param
 * UI state for providing visual feedback while altering preset parameters
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */


#ifndef BITSHIFT_UISTATE_PARAM_H
#define BITSHIFT_UISTATE_PARAM_H

#include "uistate.h"

class BitshiftUIStateParam: public BitshiftUIState
{
  public:
    BitshiftUIStateParam(int analogId, int analogParamOffset, float value):
      BitshiftUIState(),
      analogId(analogId),
      analogParamOffset(analogParamOffset) {}
    ~BitshiftUIStateParam() {}

    virtual void update(unsigned long ms);
    virtual void render();
    virtual void eventButton(int id, int value);
    virtual void eventAnalog(int id, float value);

  private:
    int analogId;
    int analogParamOffset;
    unsigned long ms = 0;
};

#endif
