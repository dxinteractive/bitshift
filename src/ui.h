/*
 * ui
 * Base class for managing a stack of UI states, handling input, and updating audio objects and display in response to input
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#ifndef BITSHIFT_UI_H
#define BITSHIFT_UI_H

#include "StackArray.h"
#include "uistate.h"
#include "audio.h"
#include "input.h"
#include "display.h"

class BitshiftUI
{
  friend class BitshiftUIState;
  public:
    BitshiftUI(
    	BitshiftAudio& audio,
    	BitshiftInput& input,
    	BitshiftDisplay& display
    );
    ~BitshiftUI();

    void pushState(BitshiftUIState* newState);
    void popState();
    void update();

    void event(int id);
    //void setValue(int id, int value); is this for analog?

  protected:
  	BitshiftAudio* audio;
    BitshiftInput* input;
    BitshiftDisplay* display;

  private:
    StackArray <BitshiftUIState*> stateStack;
};

#endif
