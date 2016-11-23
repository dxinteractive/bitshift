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

class BitshiftUI // move this to the 'default' version
{
  friend class BitshiftUIState;
  public:
    BitshiftUI(
    	BitshiftAudio& audio,
    	BitshiftInput& input,
    	BitshiftDisplay& display,
      int visibleButtonsTotal,
      int visibleAnalogsTotal
    );
    ~BitshiftUI();

    void update(unsigned long ms);
    void render();

    void initialState(BitshiftUIState* initialState);
    void pushState(BitshiftUIState* newState);
    void popState(bool render = true);

    void eventButton(int id, int value);
    void eventAnalog(int id, float value);

  protected:
  	BitshiftAudio* audio;
    BitshiftInput* input;
    BitshiftDisplay* display;
    const int visibleButtonsTotal;
    const int visibleAnalogsTotal;

  private:
    StackArray <BitshiftUIState*> stateStack;
};

#endif
