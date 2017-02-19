/*
 * effect_lfo
 * General purpose low frequency oscillator
 * Copyright (c) 201y Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "effect_lfo.h"
#include "effect.h"
#include <Audio.h>

char const* BitshiftEffectLfo::OPTIONS_SHAPE[] = {
  "Sine",
  "Triangle",
  "Square"
};

BitshiftEffectLfo::BitshiftEffectLfo():
  BitshiftEffect(),
  patchLfoToSignalMixer(lfo, 0, signalMixer, 0),
  patchOffsetToSignalMixer(offset, 0, signalMixer, 1)
{
  lfo.begin(1.0, 1.0, WAVEFORM_SINE);
  offset.amplitude(1.0);
}

float BitshiftEffectLfo::speed(float hz)
{
  lfo.frequency(hz);
  _hz = hz;
  return hz;
}

float BitshiftEffectLfo::phase(float angle)
{
  lfo.phase(angle);
  _angle = angle;
  return angle;
}

int BitshiftEffectLfo::shape(int shape)
{
  // use arbitary waveform
  return 0;
}

float BitshiftEffectLfo::mod(float mod)
{
  // use arbitary waveform
  return 0.0;
}

float BitshiftEffectLfo::shapeAndMod(float value)
{
  BitshiftEffect::audioNoInterrupts();
  // set shape
  // set mod
  BitshiftEffect::audioInterrupts();
  return 0.0;
}

//BitshiftEffectLfo::int division(int division)
//{
//
//}

float BitshiftEffectLfo::min(float min)
{
  _min = clamp(min, -1.0, 1.0);
  return _min;
}

float BitshiftEffectLfo::max(float max)
{
  _max = clamp(max, -1.0, 1.0);
  return _max;
}

void BitshiftEffectLfo::updateMinMax()
{
  BitshiftEffect::audioNoInterrupts();
  lfo.amplitude(_max - _min);
  offset.amplitude(_max * 0.5 + _min * 0.5);
  BitshiftEffect::audioInterrupts();
}
