/*
 * effect
 * Abstract base class for effects, which are configured sets of Teensy Audio components
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#include "effect.h"

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
