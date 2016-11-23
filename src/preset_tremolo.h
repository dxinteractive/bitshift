/*
 * preset_tremolo
 * Controller for tremolo effect (modulations in volume)
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
#include "paramset.h"
#include "effect_tremolo.h"

class BitshiftParamsetTremolo: public BitshiftParamset
{
  public:
    float speed;
    float depth;
    int shape;
    int division;
    float bias;
    float volume;
};

class BitshiftPresetTremolo: public BitshiftPreset
{
  public:
    BitshiftPresetTremolo();
    virtual ~BitshiftPresetTremolo() {}

    virtual void paramValueString(char* str, int paramId) const;

    virtual void setParam(int paramId, int value);
    virtual void setParam(int paramId, float value);
    virtual void setAnalogParam(int analogId, float value);
    virtual void setMenuItemParam(int itemId, int value);

  private:
    static BitshiftEffectTremolo tremolo;
    static const int PARAMS_TOTAL = 6;
    static char const* NAME;
    static char const* PARAM_NAMES[PARAMS_TOTAL];

    BitshiftParamsetTremolo params;
};

#endif
