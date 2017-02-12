/*
 * uistate_splash
 * UI state for displaying the splash screen when the bitshift first turns on
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#ifndef BITSHIFT_UISTATE_SPLASH_H
#define BITSHIFT_UISTATE_SPLASH_H

#include "uistate.h"

class BitshiftUIStateSplash: public BitshiftUIState
{
  public:
    BitshiftUIStateSplash(BitshiftUIState* nextState):
      BitshiftUIState(),
      nextState(nextState) {}
    ~BitshiftUIStateSplash() {}

    virtual void eventButton(int id, int value) {}
    virtual void eventAnalog(int id, float value) {}
    virtual void update(unsigned long ms);
    virtual void render();

  private:
    BitshiftUIState* nextState;
    unsigned long ms = 0;
    unsigned long msFirst = 0;
};

#endif
