/*
 * uistate
 * Base class for UI states, reads user input and can update audio and display differently depending on active state behaviour
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_UISTATE_H
#define BITSHIFT_UISTATE_H

// forward declarations
class BitshiftUIDefault;
class BitshiftAudio;
class BitshiftDisplay;

class BitshiftUIState
{
  public:
    BitshiftUIState() {}
    virtual ~BitshiftUIState() {}

    void init(BitshiftUIDefault* const ui);
    void init(BitshiftUIDefault* const ui, BitshiftUIState* const lowerState);
    virtual void init() {}
    // ^ this init call can be overriden by derived classes and is called after init(ui) is called

    void pushState(BitshiftUIState* newState);
    void popState(bool render = true);

    virtual void update(unsigned long ms) {}
    virtual void updateTimeout(unsigned long ms);
    virtual void render() = 0;

    virtual void eventButton(int id, int value) = 0;
    virtual void eventAnalog(int id, float value) = 0;

    void passDownEventButton(int id, int value);
    void passDownEventAnalog(int id, float value);

    void setTimeout(int duration = 1500);

  protected:
    BitshiftAudio* audio;
    BitshiftDisplay* display;
    BitshiftUIDefault* ui;
    BitshiftUIState* lowerState;

  private:
    unsigned long timeout = 0;
};

#endif
