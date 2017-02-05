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

#ifndef BITSHIFT_EFFECT_H
#define BITSHIFT_EFFECT_H

#include <Audio.h>

class BitshiftEffect
{
  public:
    BitshiftEffect() {}
    virtual ~BitshiftEffect() {}

    virtual AudioStream* audioIn() { return NULL; }
    virtual AudioStream* audioOut() { return NULL; }
    virtual int audioInChannel() const { return 0; }
    virtual int audioOutChannel() const { return 0; }
};

#endif
