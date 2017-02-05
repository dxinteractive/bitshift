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

#ifndef BITSHIFT_EFFECT_BITCRUSHER_H
#define BITSHIFT_EFFECT_BITCRUSHER_H

#include "effect.h"

class BitshiftEffectBitcrusher: public BitshiftEffect
{
  public:
    BitshiftEffectBitcrusher():
      BitshiftEffect() {};
    ~BitshiftEffectBitcrusher() {}

    float rate(float hz) { return hz; }
    int depth(int depth) { return depth; }
    float volume(float volume) { return volume; }
};

#endif
