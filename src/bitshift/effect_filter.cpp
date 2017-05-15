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

#include "effect_filter.h"
#include "effect.h"
#include "effect_volume.h"
#include <Audio.h>

char const* BitshiftEffectFilter::OPTIONS_TYPE[] = {
  "Low pass",
  "Band pass",
  "High pass"
};

void BitshiftEffectFilter::setup()
{
  volumeEffect.setup();
}

float BitshiftEffectFilter::frequency(float hz)
{
  hz = clamp(hz, 64.0, 16000.0);
  filter.frequency(hz);
  return hz;
}

float BitshiftEffectFilter::resonance(float resonance)
{
  resonance = clamp(resonance, 0.8, 5.0);
  filter.resonance(resonance);
  return resonance;
}

int BitshiftEffectFilter::type(int type)
{
  type = clamp(type, 0, 2);
  BitshiftEffect::audioNoInterrupts();
  mixer.gain(0, 0.0);
  mixer.gain(1, 0.0);
  mixer.gain(2, 0.0);
  mixer.gain(type, 1.0);
  BitshiftEffect::audioInterrupts();
  return type;
}

float BitshiftEffectFilter::volume(float volume)
{
  return volumeEffect.volume(volume);
}
