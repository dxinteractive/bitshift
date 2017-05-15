/*
 * effect_volume
 * Audio effect for volume
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "effect_volume.h"
#include "effect.h"
#include <Audio.h>

void BitshiftEffectVolume::setup()
{
  volume(1.0);
}

float BitshiftEffectVolume::volume(float volume)
{
  volume = clamp(volume, 0.0, 3.0);
  mixer.gain(0, volume);
  return volume;
}
