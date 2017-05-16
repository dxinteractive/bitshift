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

#include "effect_reverb.h"
#include "effect.h"
#include <Audio.h>

void BitshiftEffectReverb::setup()
{
  // reverb does not play nice with high levels
  // so bring the whole thing down
  // and boost it back up on the way out
  inputMixer.gain(0, 0.25);
}

float BitshiftEffectReverb::time(float seconds)
{
  seconds = clamp(seconds, 0.0, 8.0);
  reverb.reverbTime(seconds);
  return seconds;
}

float BitshiftEffectReverb::blend(float amount)
{
  amount = clamp(amount, 0.0, 1.0);
  BitshiftEffect::audioNoInterrupts();
  outputMixer.gain(0, (1.0 - amount) * 4.0);
  outputMixer.gain(1, amount * 8.0);
  BitshiftEffect::audioInterrupts();
  return amount;
}
