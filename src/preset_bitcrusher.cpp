/*
 * preset_bitcrusher
 * Bitcrusher effect bitcrusher effect (digital distorion by reduction of sample rate and/or depth)
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#include "preset_bitcrusher.h"
#include <Arduino.h>
#include "paramset.h"

static const int RATE = 0;
static const int DEPTH = 1;
static const int VOLUME = 2;

char const* BitshiftPresetBitcrusher::NAME = "Bitcrusher";
char const* BitshiftPresetBitcrusher::PARAM_NAMES[] = {
  "Rate",
  "Depth",
  "Volume"
};

BitshiftPresetBitcrusher::BitshiftPresetBitcrusher():
  BitshiftPreset()
{
  params.rate = 44100.0;
  params.depth = 16;
  params.volume = 0.8;

  thisName = NAME;
  thisParamsTotal = PARAMS_TOTAL;
  thisParamNames = PARAM_NAMES;

  const int ANALOG_MAP_SIZE = 3;
  int analogMap[ANALOG_MAP_SIZE] = {0,1,2};
  setAnalogMap(analogMap, ANALOG_MAP_SIZE);
}

void BitshiftPresetBitcrusher::paramValueString(char* str, int paramId) const
{
  switch(paramId)
  {
    case RATE:
      sprintf(str, "%0.0fHz", params.rate);
      break;
    case DEPTH:
      sprintf(str, "%dbit", params.depth);
      break;
    case VOLUME:
      sprintf(str, "%0.0f%%", params.volume * 100.0);
      break;
    default:
      return;
  }
}

void BitshiftPresetBitcrusher::setAnalogParam(int analogId, float value)
{
  int paramId = paramIdByAnalogId(analogId);
  switch(paramId)
  {
    case RATE:
      {
        // exponential range from 256.0 (2^8) to 44100.0 (2^15.5 capped at 44100.0)
        value = pow(2, 8 + (value * 7.5));
        if(value > 44100.0)
          value = 44100.0;
        setParam(paramId, value);
        return;
      }

    case DEPTH:
      {
        // range from 1 to 16
        int intValue = int(value * 16.0) + 1;
        if(intValue > 16)
          intValue = 16;
        setParam(paramId, intValue);
        return;
      }

    case VOLUME:
      // default range of 0.0 to 1.0
      setParam(paramId, value);
      return;
  }
}

void BitshiftPresetBitcrusher::setParam(int paramId, float value)
{
  switch(paramId)
  {
    case RATE:
      params.rate = BitshiftPresetBitcrusher::bitcrusher.rate(value);
      return;
    case VOLUME:
      params.volume = BitshiftPresetBitcrusher::bitcrusher.volume(value);
      return;
  }
}

void BitshiftPresetBitcrusher::setParam(int paramId, int value)
{
  switch(paramId)
  {
    case DEPTH:
      params.depth = BitshiftPresetBitcrusher::bitcrusher.depth(value);
      return;
  }
}
