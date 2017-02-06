/*
 * effect_tremolo
 * Audio effect for tremolo effect (modulations in volume)
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#ifndef BITSHIFT_EFFECT_TREMOLO_H
#define BITSHIFT_EFFECT_TREMOLO_H

#include "effect.h"
#include <Audio.h>

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
    AudioSynthWaveform lfo;
    AudioSynthWaveformDc offset;
    AudioMixer4 signalMixer;
    AudioEffectMultiply multiplier;

    AudioConnection patchLfoToSignalMixer;
    AudioConnection patchOffsetToSignalMixer;
    AudioConnection patchSignalMixerToMultiplier;
};

#endif
