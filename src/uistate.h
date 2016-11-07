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

// forward declarations
class BitshiftUI;
class BitshiftAudio;
class BitshiftDisplay;

class BitshiftUIState
{
  public:
    BitshiftUIState() {}
    virtual ~BitshiftUIState() {}

    void setUI(BitshiftUI* const ui);
    void pushState(BitshiftUIState* newState);
    void popState();
    virtual void render() = 0;
    virtual void onEvent(int id, int value) = 0;
    virtual void onEvent(int id, float value) = 0;

  protected:
    BitshiftAudio* audio;
    BitshiftDisplay* display;

  private:
    BitshiftUI* ui;
};

#endif
