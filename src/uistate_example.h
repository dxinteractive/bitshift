/*
 * uistate_example
 * An example UI state for testing
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */


#ifndef BITSHIFT_UISTATE_EXAMPLE_H
#define BITSHIFT_UISTATE_EXAMPLE_H

#include "uistate.h"

class BitshiftUIStateExample: public BitshiftUIState
{
  public:
    BitshiftUIStateExample():
      BitshiftUIState() {}
    ~BitshiftUIStateExample() {}

    // set total number of analog inputs
    // get total number of params from audio

    virtual void onEvent(int id) { Serial.print("event "); Serial.println(id); }
};

#endif
