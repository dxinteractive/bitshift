/*
 * effect
 * Abstract base class for effects, which are configured sets of Teensy Audio components
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_EFFECT_H
#define BITSHIFT_EFFECT_H

#include <Audio.h>

class BitshiftEffect
{
  public:
    static void audioNoInterrupts();
    static void audioInterrupts();

    BitshiftEffect() {}
    virtual ~BitshiftEffect() {}

    virtual void setup() {}

    virtual AudioStream* audioIn() { return NULL; }
    virtual AudioStream* audioOut() { return NULL; }
    virtual int audioInChannel() const { return 0; }
    virtual int audioOutChannel() const { return 0; }

    virtual void audioEnable() {}
    virtual void audioDisable() {}

  protected:
    static int noInterruptsCount;

    int clamp(int value, int low, int high);
    float clamp(float value, float low, float high);
};

#endif
