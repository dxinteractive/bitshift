/*
 * preset
 * Base class for presets, complete effects that can be used one at a time
 * consisting of configurations of audio effects, audio routing and controllers
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#ifndef BITSHIFT_PRESET_H
#define BITSHIFT_PRESET_H

class BitshiftPreset
{
  public:
    BitshiftPreset() {}
    virtual ~BitshiftPreset() {}

    virtual char const* name() { return 0; }
    virtual void param(int id, int value) {}
    virtual void paramAnalog(int id, int value) {}
};

#endif
