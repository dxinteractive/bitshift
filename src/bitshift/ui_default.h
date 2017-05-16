/*
 * ui_default
 * Default UI comprised of a stack of UI states
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */


#ifndef BITSHIFT_UI_DEFAULT_H
#define BITSHIFT_UI_DEFAULT_H

#include <StackArray.h>
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
      BitshiftUIState* initialState
    );
    ~BitshiftUIDefault();

    virtual void update(unsigned long ms);
    virtual void render();
    virtual void eventButton(int id, int value);
    virtual void eventAnalog(int id, float value);

    void initialState(BitshiftUIState* initialState);
    void pushState(BitshiftUIState* newState);
    void popState(bool render = true);

  private:
    StackArray <BitshiftUIState*> stateStack;
};

#endif
