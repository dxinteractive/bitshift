/*
 * display
 * Base class for displays, which are often screens but can be any kind of user feedback control
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_DISPLAY_H
#define BITSHIFT_DISPLAY_H

#include "props.h"

class BitshiftDisplay
{
  public:
    BitshiftDisplay() {}
    virtual ~BitshiftDisplay() {}

    virtual void render(BitshiftPropsMenu &props) = 0;
    virtual void render(BitshiftPropsMessage &props) = 0;
    virtual void render(BitshiftPropsPreset &props) = 0;
    virtual void render(BitshiftPropsParam &props) = 0;
    virtual void render(BitshiftPropsSplash &props) = 0;
    virtual void render(BitshiftPropsUsage &props) = 0;

  private:
};

#endif
