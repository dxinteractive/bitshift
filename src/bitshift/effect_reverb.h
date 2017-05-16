/*
 * effect_reverb
 * Reverb effect
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_EFFECT_REVERB_H
#define BITSHIFT_EFFECT_REVERB_H

#include "effect.h"
#include <Audio.h>

class BitshiftEffectReverb: public BitshiftEffect
{
  public:
    BitshiftEffectReverb():
      BitshiftEffect(),
      patchInputMixerToReverb(inputMixer, 0, reverb, 0),
      patchInputMixerToOutputMixer(inputMixer, 0, outputMixer, 0),
      patchReverbToOutputMixer(reverb, 0, outputMixer, 1) {}
    ~BitshiftEffectReverb() {}

    virtual void setup();

    virtual AudioStream* audioIn() { return &inputMixer; }
    virtual AudioStream* audioOut() { return &outputMixer; }

    float time(float seconds);
    float blend(float wet);

  private:
    AudioMixer4 inputMixer;
    AudioEffectReverb reverb;
    AudioMixer4 outputMixer;

    AudioConnection patchInputMixerToReverb;
    AudioConnection patchInputMixerToOutputMixer;
    AudioConnection patchReverbToOutputMixer;
};

#endif
