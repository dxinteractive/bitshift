/*
 * preset_bitcrusher
 * Bitcrusher effect bitcrusher effect (digital distorion by reduction of sample rate and/or depth)
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "preset_bitcrusher.h"
#include <Arduino.h>
#include "paramset.h"
#include "utils.h"

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
  initBase(
    &bitcrusher,
    &params,
    NAME,
    PARAM_NAMES,
    PARAMS_TOTAL
  );

  const int ANALOG_MAP_SIZE = 3;
  int analogMap[ANALOG_MAP_SIZE] = {0,1,2};
  setAnalogMap(analogMap, ANALOG_MAP_SIZE);
}

void BitshiftPresetBitcrusher::initialParams()
{
  setParam(RATE, 11000.0);
  setParam(DEPTH, 16);
  setParam(VOLUME, 1.0);
}

void BitshiftPresetBitcrusher::paramValueString(char* str, int paramId) const
{
  switch(paramId)
  {
    case RATE:
      floatToString(params.rate, 0, "%sHz", str);
      return;

    case DEPTH:
      sprintf(str, "%dbit", params.depth);
      return;

    case VOLUME:
      floatToString(params.volume * 100.0, 0, "%s%%", str);
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
        setParam(paramId, intRange(value, 1, 16));
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
      params.rate = bitcrusher.rate(value);
      return;

    case VOLUME:
      params.volume = bitcrusher.volume(value);
      return;
  }
}

void BitshiftPresetBitcrusher::setParam(int paramId, int value)
{
  switch(paramId)
  {
    case DEPTH:
      params.depth = bitcrusher.depth(value);
      return;
  }
}
