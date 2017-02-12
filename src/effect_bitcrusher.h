/*
 * effect_bitcrusher
 * Audio effect for bitcrusher effect (digital distorion by reduction of sample rate and/or depth)
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_EFFECT_BITCRUSHER_H
#define BITSHIFT_EFFECT_BITCRUSHER_H

#include "effect.h"
#include "effect_volume.h"
#include <Audio.h>

class BitshiftEffectBitcrusher: public BitshiftEffect
{
  public:
    BitshiftEffectBitcrusher();
    ~BitshiftEffectBitcrusher() {}

    virtual AudioStream* audioIn() { return &bitcrusher; }
    virtual AudioStream* audioOut() { return volumeEffect.audioOut(); }

    float rate(float hz);
    int depth(int depth);
    float volume(float volume);

  private:
    AudioEffectBitcrusher bitcrusher;
    BitshiftEffectVolume volumeEffect;
    AudioConnection patchBitcrusherToVolume;
};

#endif
