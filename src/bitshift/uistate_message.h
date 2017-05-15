/*
 * uistate_message
 * UI state for displaying a message
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_UISTATE_MESSAGE_H
#define BITSHIFT_UISTATE_MESSAGE_H

#include "uistate.h"

class BitshiftUIStateMessage: public BitshiftUIState
{
  public:
    BitshiftUIStateMessage(char const* message):
      BitshiftUIState(),
      message(message) {}
    ~BitshiftUIStateMessage() {}

    virtual void render();
    virtual void eventButton(int id, int value);
    virtual void eventAnalog(int id, float value);

  private:
    char const* message;
};

#endif
