/*
 * uistate
 * Base class for UI states, reads user input and can update audio and display differently depending on active state behaviour
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-. 
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : : 
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_; 
 */

#ifndef BITSHIFT_UISTATE_H
#define BITSHIFT_UISTATE_H

// forward declare ui
class BitshiftUI;

class BitshiftUIState
{
  public:
    BitshiftUIState() {}
    virtual ~BitshiftUIState() {}

    inline void setUI(BitshiftUI* const ui) { this->ui = ui; }
    virtual void onEvent(int id) = 0;
    
  protected:
    BitshiftUI* ui;
};

#endif
