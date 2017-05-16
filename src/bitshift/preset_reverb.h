/*
 * preset_reverb
 * Reverb effect
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_PRESET_REVERB_H
#define BITSHIFT_PRESET_REVERB_H

#include "preset.h"
#include "paramset.h"
#include "effect_reverb.h"

class BitshiftParamsetReverb: public BitshiftParamset
{
  public:
    float time;
    float blend;
};

class BitshiftPresetReverb: public BitshiftPreset
{
  public:
    BitshiftPresetReverb();
    virtual ~BitshiftPresetReverb() {}

    virtual void initialParams();

    virtual void paramValueString(char* str, int paramId) const;

    virtual void setParam(int paramId, float value);
    virtual void setAnalogParam(int analogId, float value);

  private:
    static const int PARAMS_TOTAL = 2;
    static char const* NAME;
    static char const* PARAM_NAMES[PARAMS_TOTAL];

    BitshiftEffectReverb reverb;
    BitshiftParamsetReverb params;
};

#endif
