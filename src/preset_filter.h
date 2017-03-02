/*
 * preset_filter
 * Filter effect with low pass, band pass and high pass options
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_PRESET_FILTER_H
#define BITSHIFT_PRESET_FILTER_H

#include "preset.h"
#include "paramset.h"
#include "effect_filter.h"

class BitshiftParamsetFilter: public BitshiftParamset
{
  public:
    float frequency;
    float resonance;
    int type;
    float volume;
};

class BitshiftPresetFilter: public BitshiftPreset
{
  public:
    BitshiftPresetFilter();
    virtual ~BitshiftPresetFilter() {}

    virtual void initialParams();

    virtual int paramValueInt(int paramId) const;
    virtual void paramValueString(char* str, int paramId) const;

    virtual void setParam(int paramId, int value);
    virtual void setParam(int paramId, float value);
    virtual void setAnalogParam(int analogId, float value);
    virtual void setMenuItemParam(int itemId, int value);

  private:
    static const int PARAMS_TOTAL = 4;
    static char const* NAME;
    static char const* PARAM_NAMES[PARAMS_TOTAL];

    BitshiftEffectFilter filter;
    BitshiftParamsetFilter params;
};

#endif
