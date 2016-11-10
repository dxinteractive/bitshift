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

    virtual const int totalParams();
    virtual char const* name();
    virtual char const** paramNames();

    virtual int getParam(int id);
    virtual float getParamAnalog(int id);
    virtual void setParam(int id, int value);
    virtual void setParamAnalog(int id, float value);

  private:
    static const int _totalParams;
    static char const* _name;
    static char const* _paramNames[];
    float temp;
};

#endif
