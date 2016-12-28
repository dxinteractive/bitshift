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
static const int VOLUME = 5;

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
      //value = pow(2, value * 44100.0 - 1.0);
      value = value * 44100.0;
      break;
    case DEPTH:
      //setParam(paramId, value);
      break;
    case VOLUME:
      break;
    default:
      return;
  }
  setParam(paramId, value);
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
