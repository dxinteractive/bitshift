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
    BitshiftEffectTremolo():
      BitshiftEffect(),
      patchLfoToFilter(*(lfo.audioOut()), 0, filter, 0),
      patchFilterToMultiplier(filter, 0, multiplier, 1) {}
    ~BitshiftEffectTremolo() {}

    virtual void setup();

    virtual AudioStream* audioIn() { return &multiplier; }
    virtual AudioStream* audioOut() { return &multiplier; }

    float speed(float hz);
    float depth(float depth);
    int shapeAndMod(float value);
    int division(int division);
    float volume(float volume);

  private:
    void updateMinMax();

    BitshiftEffectLfo lfo; // lfo to privide modulation signal
    AudioFilterStateVariable filter; // filter on modulation signal to prevent audible popping on extreme signal swings
    AudioEffectMultiply multiplier; // mutiplier to control the volume of the audio signal with the lfo

    AudioConnection patchLfoToFilter;
    AudioConnection patchFilterToMultiplier;

    float _volume = 1.0;
    float _depth = 1.0;
};

#endif
