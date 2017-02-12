/*
 * preset_tremolo
 * Tremolo effect (modulations in volume)
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "preset_tremolo.h"
#include <Arduino.h>
#include "paramset.h"

static const int SPEED = 0;
static const int DEPTH = 1;
static const int SHAPE = 2;
static const int DIVISION = 3;
static const int BIAS = 4;
static const int VOLUME = 5;

char const* BitshiftPresetTremolo::NAME = "Tremolo";
char const* BitshiftPresetTremolo::PARAM_NAMES[] = {
  "Speed",
  "Depth",
  "Shape",
  "Division",
  "Bias",
  "Volume"
};

char const* BitshiftPresetTremolo::OPTIONS_SHAPE[] = {
  "Sine",
  "Triangle",
  "Square"
};

BitshiftPresetTremolo::BitshiftPresetTremolo():
  BitshiftPreset()
{
  setEffect(&tremolo);

  params.speed = 1.0;
  params.depth = 0.5;
  params.shape = 0;
  params.division = 0;
  params.bias = 0.2;
  params.volume = 0.8;

  thisName = NAME;
  thisParamsTotal = PARAMS_TOTAL;
  thisParamNames = PARAM_NAMES;

  const int ANALOG_MAP_SIZE = 6;
  int analogMap[ANALOG_MAP_SIZE] = {0,1,2,3,4,5};
  setAnalogMap(analogMap, ANALOG_MAP_SIZE);

  const int MENU_ITEM_MAP_SIZE = 2;
  int menuItemMap[MENU_ITEM_MAP_SIZE] = {3,2};
  char const** menuItemOptions[MENU_ITEM_MAP_SIZE] = {
    OPTIONS_BOOLEAN,
    OPTIONS_SHAPE
  };

  setMenuItemMap(menuItemMap, MENU_ITEM_MAP_SIZE, menuItemOptions);
}

void BitshiftPresetTremolo::paramValueString(char* str, int paramId) const
{
  switch(paramId)
  {
    case SPEED:
      sprintf(str, "%0.1fHz", params.speed);
      break;
    case DEPTH:
      sprintf(str, "%0.0f%%", params.depth * 100.0);
      break;
    case SHAPE:
      sprintf(str, OPTIONS_SHAPE[params.shape]);
      break;
    case DIVISION:
      sprintf(str, "...");
      break;
    case BIAS:
      sprintf(str, "...");
      break;
    case VOLUME:
      sprintf(str, "%0.0f%%", params.volume * 100.0);
      break;
    default:
      return;
  }
}

void BitshiftPresetTremolo::setAnalogParam(int analogId, float value)
{
  int paramId = paramIdByAnalogId(analogId);
  switch(paramId)
  {
    case SPEED:
      {
        // exponential range from 0.125 (2^-3) to 64.0 (2^6)
        value = pow(2, value * 9.0 - 3.0);
        setParam(paramId, value);
        return;
      }

    case SHAPE:
    {
      // 0, 1 or 2
      setParam(paramId, intRange(value, 0, 2));
      return;
    }

    case DEPTH:
    case VOLUME:
      // default range from 0.0 to 0.1
      setParam(paramId, value);
      return;
  }
}

void BitshiftPresetTremolo::setMenuItemParam(int itemId, int value)
{
  int paramId = paramIdByMenuItemId(itemId);
  switch(paramId)
  {
    case SHAPE:
    case DIVISION:
      setParam(paramId, value);
      return;
  }
}

void BitshiftPresetTremolo::setParam(int paramId, float value)
{
  switch(paramId)
  {
    case SPEED:
      params.speed = tremolo.speed(value);
      return;

    case DEPTH:
      params.depth = tremolo.depth(value);
      return;

    case VOLUME:
      params.volume = tremolo.volume(value);
      return;

  }
}

void BitshiftPresetTremolo::setParam(int paramId, int value)
{
  switch(paramId)
  {
    case SHAPE:
      params.shape = tremolo.shape(value);
      return;

    case DIVISION:
      params.division = tremolo.division(value);
      return;
  }
}
