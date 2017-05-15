/*
 * effect_filter
 * Audio effect for filter with low pass, band pass and high pass options
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_EFFECT_FILTER_H
#define BITSHIFT_EFFECT_FILTER_H

#include "effect.h"
#include "effect_volume.h"

class BitshiftEffectFilter: public BitshiftEffect
{
  public:
    static const int OPTIONS_TYPE_TOTAL = 3;
    static char const* OPTIONS_TYPE[OPTIONS_TYPE_TOTAL];

    BitshiftEffectFilter():
      BitshiftEffect(),
      patchLowPassToMixer(filter, 0, mixer, 0),
      patchBandPassToMixer(filter, 1, mixer, 1),
      patchHighPassToMixer(filter, 2, mixer, 2),
      patchFilterToVolume(mixer, *(volumeEffect.audioIn())) {}
    ~BitshiftEffectFilter() {}

    virtual void setup();

    virtual AudioStream* audioIn() { return &filter; }
    virtual AudioStream* audioOut() { return volumeEffect.audioOut(); }

    float frequency(float hz);
    float resonance(float q);
    int type(int type);
    float volume(float volume);

  private:
    AudioFilterStateVariable filter;
    AudioMixer4 mixer;
    BitshiftEffectVolume volumeEffect;

    AudioConnection patchLowPassToMixer;
    AudioConnection patchBandPassToMixer;
    AudioConnection patchHighPassToMixer;
    AudioConnection patchFilterToVolume;
};

#endif
