/*
 * preset_bitcrusher
 * Controller for bitcrusher effect (digital distorion by reduction of sample rate and/or depth)
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_PRESET_BITCRUSHER_H
#define BITSHIFT_PRESET_BITCRUSHER_H

#include "preset.h"
#include "paramset.h"
#include "effect_bitcrusher.h"

class BitshiftParamsetBitcrusher: public BitshiftParamset
{
  public:
    float rate;
    int depth;
    float volume;
};

class BitshiftPresetBitcrusher: public BitshiftPreset
{
  public:
    BitshiftPresetBitcrusher();
    virtual ~BitshiftPresetBitcrusher() {}

    virtual void initialParams();

    virtual void paramValueString(char* str, int paramId) const;

    virtual void setParam(int paramId, int value);
    virtual void setParam(int paramId, float value);
    virtual void setAnalogParam(int analogId, float value);

  private:
    static const int PARAMS_TOTAL = 3;
    static char const* NAME;
    static char const* PARAM_NAMES[PARAMS_TOTAL];

    BitshiftEffectBitcrusher bitcrusher;
    BitshiftParamsetBitcrusher params;
};

#endif
