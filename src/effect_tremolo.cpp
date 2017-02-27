/*
 * effect_tremolo
 * Audio effect for bitcrusher effect (digital distorion by reduction of sample rate and/or depth)
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "effect_tremolo.h"
#include "effect.h"
#include "effect_lfo.h"
#include "effect_volume.h"
#include <Audio.h>

void BitshiftEffectTremolo::setup()
{
  filter.frequency(100.0);
}

float BitshiftEffectTremolo::speed(float hz)
{
  return lfo.speed(hz);
}

float BitshiftEffectTremolo::depth(float depth)
{
  _depth = clamp(depth, 0.0, 1.0);
  updateMinMax();
  return _depth;
}

int BitshiftEffectTremolo::shapeAndMod(float value)
{
  return lfo.shapeAndMod(value);
}

int BitshiftEffectTremolo::division(int division)
{
  //lfo.division(division);
  return 0;
}

float BitshiftEffectTremolo::volume(float volume)
{
  _volume = clamp(volume, 0.0, 3.0);
  updateMinMax();
  return _volume;
}

void BitshiftEffectTremolo::updateMinMax()
{
  BitshiftEffect::audioNoInterrupts();
  lfo.min((1.0 - _depth) * _volume);
  lfo.max(_volume);
  BitshiftEffect::audioInterrupts();
}
