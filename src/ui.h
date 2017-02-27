/*
 * ui
 * Base class for managing a UI (mainly updating audio objects and display in response to input)
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_UI_H
#define BITSHIFT_UI_H

#include "audio.h"
#include "input.h"
#include "display.h"

class BitshiftUI
{
  public:
    BitshiftUI(
    	BitshiftAudio& audio,
    	BitshiftInput& input,
    	BitshiftDisplay& display
    );
    virtual ~BitshiftUI() {}

    virtual void update(unsigned long ms) = 0;
    virtual void render() = 0;
    virtual void eventButton(int id, int value) = 0;
    virtual void eventAnalog(int id, float value) = 0;

  	BitshiftAudio* audio;
    BitshiftInput* input;
    BitshiftDisplay* display;
};

#endif
