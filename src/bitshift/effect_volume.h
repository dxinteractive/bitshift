/*
 * effect_volume
 * Audio effect for volume
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_EFFECT_VOLUME_H
#define BITSHIFT_EFFECT_VOLUME_H

#include "effect.h"
#include <Audio.h>

class BitshiftEffectVolume: public BitshiftEffect
{
  public:
    BitshiftEffectVolume():
      BitshiftEffect() {}
    ~BitshiftEffectVolume() {}

    virtual void setup();

    virtual AudioStream* audioIn() { return &mixer; }
    virtual AudioStream* audioOut() { return &mixer; }

    float volume(float volume);

  private:
    AudioMixer4 mixer;
};

#endif
