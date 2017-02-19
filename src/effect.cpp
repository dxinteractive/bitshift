/*
 * effect
 * Abstract base class for effects, which are configured sets of Teensy Audio components
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "effect.h"

int BitshiftEffect::noInterruptsCount = 0;

void BitshiftEffect::audioNoInterrupts()
{
  if(BitshiftEffect::noInterruptsCount == 0)
    AudioNoInterrupts();

  BitshiftEffect::noInterruptsCount++;
}

void BitshiftEffect::audioInterrupts()
{
  if(BitshiftEffect::noInterruptsCount == 0)
    return;

  BitshiftEffect::noInterruptsCount--;
  if(BitshiftEffect::noInterruptsCount == 0)
    AudioInterrupts();
}


int BitshiftEffect::clamp(int value, int low, int high)
{
  if(value < low)
    return low;

  if(value > high)
    return high;

  return value;
}

float BitshiftEffect::clamp(float value, float low, float high)
{
  if(value < low)
    return low;

  if(value > high)
    return high;

  return value;
}
