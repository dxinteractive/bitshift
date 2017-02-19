/*
 * effect_tremolo
 * Audio effect for tremolo effect (modulations in volume)
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_EFFECT_TREMOLO_H
#define BITSHIFT_EFFECT_TREMOLO_H

#include "effect.h"
#include "effect_lfo.h"

class BitshiftEffectTremolo: public BitshiftEffect
{
  public:
    BitshiftEffectTremolo();
    ~BitshiftEffectTremolo() {}

    virtual AudioStream* audioIn() { return &multiplier; }
    virtual AudioStream* audioOut() { return &multiplier; }

    float speed(float hz);
    float depth(float depth);
    int shape(int shape);
    int division(int division);
    float volume(float volume);

  private:
    void updateMinMax();

    BitshiftEffectLfo lfo;
    AudioEffectMultiply multiplier;

    AudioConnection patchLfoToMultiplier;

    float _volume = 1.0;
    float _depth = 1.0;
};

#endif
