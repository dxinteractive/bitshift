/*
 * effect_tremolo
 * Audio effect for tremolo effect (modulations in volume)
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#ifndef BITSHIFT_EFFECT_TREMOLO_H
#define BITSHIFT_EFFECT_TREMOLO_H

#include "effect.h"
#include <Audio.h>

class BitshiftEffectTremolo: public BitshiftEffect
{
  public:
    BitshiftEffectTremolo():
      BitshiftEffect() {};
    ~BitshiftEffectTremolo() {}

    virtual AudioStream const* audioIn() const { return &fade; }
    virtual AudioStream const* audioOut() const { return &fade; }

    float speed(float hz) { return hz; }
    float depth(float depth) { return depth; }
    int shape(int shape) { return shape; }
    int division(int division) { return division; }
    float volume(float volume) { return volume; }

  private:
    AudioEffectFade fade;
};

#endif
