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
#include "effect_volume.h"
#include <Audio.h>

BitshiftEffectTremolo::BitshiftEffectTremolo():
  BitshiftEffect(),
  patchLfoToSignalMixer(lfo, 0, signalMixer, 0),
  patchOffsetToSignalMixer(offset, 0, signalMixer, 1),
  patchSignalMixerToMultiplier(signalMixer, 0, multiplier, 1)
{
  lfo.begin(1.0, 1.0, WAVEFORM_SINE);
  offset.amplitude(1.0);
}

float BitshiftEffectTremolo::speed(float hz)
{
  lfo.frequency(hz);
  return hz;
}

float BitshiftEffectTremolo::depth(float depth)
{
  // nothing yet
  depth = clamp(depth, 0.0, 1.0);
  signalMixer.gain(0, depth * 0.5);
  signalMixer.gain(1, 1.0 - (depth * 0.5));
  return depth;
}

int BitshiftEffectTremolo::shape(int shape)
{
  // nothing here yet
  return shape;
}

int BitshiftEffectTremolo::division(int division)
{
  // nothing here yet
  return division;
}

float BitshiftEffectTremolo::volume(float volume)
{
  return volume;
}
