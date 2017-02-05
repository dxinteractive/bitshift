/*
 * uistate_message
 * UI state for displaying a message
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#ifndef BITSHIFT_UISTATE_MESSAGE_H
#define BITSHIFT_UISTATE_MESSAGE_H

#include "uistate.h"

class BitshiftUIStateMessage: public BitshiftUIState
{
  public:
    BitshiftUIStateMessage(const char* message):
      BitshiftUIState(),
      message(message) {}
    ~BitshiftUIStateMessage() {}

    virtual void render();
    virtual void eventButton(int id, int value);
    virtual void eventAnalog(int id, float value);

  private:
    const char* message;
};

#endif
