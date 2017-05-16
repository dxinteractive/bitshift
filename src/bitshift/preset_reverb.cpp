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

#include "preset_reverb.h"
#include "paramset.h"
#include "effect_reverb.h"
#include "utils.h"

static const int TIME = 0;
static const int BLEND = 1;

char const* BitshiftPresetReverb::NAME = "Reverb";
char const* BitshiftPresetReverb::PARAM_NAMES[] = {
  "Time",
  "Blend"
};

BitshiftPresetReverb::BitshiftPresetReverb():
  BitshiftPreset()
{
  initBase(
    &reverb,
    &params,
    NAME,
    PARAM_NAMES,
    PARAMS_TOTAL
  );

  const int ANALOG_MAP_SIZE = 2;
  int analogMap[ANALOG_MAP_SIZE] = {0,1};
  setAnalogMap(analogMap, ANALOG_MAP_SIZE);
}

void BitshiftPresetReverb::initialParams()
{
  setParam(TIME, 0.2);
  setParam(BLEND, 0.6);
}

void BitshiftPresetReverb::paramValueString(char* str, int paramId) const
{
  switch(paramId)
  {
    case TIME:
      sprintf(str, "%dms", int(params.time * 1000));
      return;

    case BLEND:
      floatToString(params.blend * 100.0, 0, "%s%%", str);
      return;
  }
}

void BitshiftPresetReverb::setAnalogParam(int analogId, float value)
{
  int paramId = paramIdByAnalogId(analogId);
  switch(paramId)
  {
    case TIME:
    {
      // 0.0 - 1.0
      // exponential range from 0.125s (2^-3) to 8.0s (2^3)
      value = pow(2, value * 6.0 - 3.0);
      setParam(paramId, value);
      return;
    }

    case BLEND:
    {
      // 0.0 - 1.0
      setParam(paramId, value);
      return;
    }
  }
}

void BitshiftPresetReverb::setParam(int paramId, float value)
{
  switch(paramId)
  {
    case TIME:
      params.time = reverb.time(value);
      return;

    case BLEND:
      params.blend = reverb.blend(value);
      return;
  }
}
