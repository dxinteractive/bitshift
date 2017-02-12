/*
 * effect_bitcrusher
 * Audio effect for bitcrusher effect (digital distorion by reduction of sample rate and/or depth)
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#include "effect_bitcrusher.h"
#include "effect.h"
#include "effect_volume.h"
#include <Audio.h>

BitshiftEffectBitcrusher::BitshiftEffectBitcrusher():
  BitshiftEffect(),
  patchBitcrusherToVolume(bitcrusher, *(volumeEffect.audioIn()))
{
}

float BitshiftEffectBitcrusher::rate(float hz)
{
  hz = clamp(hz, 250.0, 44100.0);
  bitcrusher.sampleRate(hz);
  return hz;
}

int BitshiftEffectBitcrusher::depth(int depth)
{
  depth = clamp(depth, 1, 16);
  bitcrusher.bits(depth);
  return depth;
}

float BitshiftEffectBitcrusher::volume(float volume)
{
  return volumeEffect.volume(volume);
}
