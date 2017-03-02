/*
 * preset_tremolo
 * Controller for tremolo effect (modulations in volume)
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
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
    float shapeAndMod;
    int division;
    float volume;
};

class BitshiftPresetTremolo: public BitshiftPreset
{
  public:
    BitshiftPresetTremolo();
    virtual ~BitshiftPresetTremolo() {}

    virtual void initialParams();

    virtual int paramValueInt(int paramId) const;
    virtual void paramValueString(char* str, int paramId) const;

    virtual void setParam(int paramId, int value);
    virtual void setParam(int paramId, float value);
    virtual void setAnalogParam(int analogId, float value);
    virtual void setMenuItemParam(int itemId, int value);

  private:
    static const int PARAMS_TOTAL = 5;
    static char const* NAME;
    static char const* PARAM_NAMES[PARAMS_TOTAL];

    BitshiftEffectTremolo tremolo;
    BitshiftParamsetTremolo params;
};

#endif
