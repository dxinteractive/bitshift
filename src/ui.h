/*
 * ui
 * Controller class for managing a stack of UI states, handling input, and updating audio objects and display in response to input
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

#include <stack>
#include "uistate.h"
#include "display.h"

class BitshiftUI
{
  public:
    BitshiftUI();
    ~BitshiftUI();

    void pushState(BitshiftUIState* newState);
    void popState();
    void update();
    
  private:
    std::stack <BitshiftUIState*> stateStack;
};

#endif
