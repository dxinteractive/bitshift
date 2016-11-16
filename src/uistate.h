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

    virtual void update(unsigned long ms);
    virtual void render() = 0;
    virtual void event(int id, int value) = 0;
    virtual void eventAnalog(int id, float value) = 0;

    void setTimeout();

  protected:
    BitshiftAudio* audio;
    BitshiftDisplay* display;
    BitshiftUI* ui;

  private:
    unsigned long timeout = 0;
};

#endif
