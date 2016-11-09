/*
 * preset_tremolo
 * Tremolo effect (modulations in volume)
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#ifndef BITSHIFT_PRESET_TREMOLO_H
#define BITSHIFT_PRESET_TREMOLO_H

#include "preset.h"

class BitshiftPresetTremolo: public BitshiftPreset
{
  public:
    BitshiftPresetTremolo():
      BitshiftPreset() {}
    ~BitshiftPresetTremolo() {}

    virtual char const* name();
    virtual void param(int id, int value);
    virtual void paramAnalog(int id, float value);

  private:
    static char const* _name;
};

#endif
