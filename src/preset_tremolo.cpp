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
#include "paramset.h"
#include "effect_lfo.h"

static const int SPEED = 0;
static const int DEPTH = 1;
static const int SHAPEANDMOD = 2;
static const int DIVISION = 3;
static const int VOLUME = 4;

char const* BitshiftPresetTremolo::NAME = "Tremolo";
char const* BitshiftPresetTremolo::PARAM_NAMES[] = {
  "Speed",
  "Depth",
  "Shape",
  "Division",
  "Volume"
};

BitshiftPresetTremolo::BitshiftPresetTremolo():
  BitshiftPreset()
{
  setEffect(&tremolo);

  params.speed = 1.0;
  params.depth = 0.5;
  params.shapeAndMod = 0.5;
  params.division = 0;
  params.volume = 0.8;

  thisName = NAME;
  thisParamsTotal = PARAMS_TOTAL;
  thisParamNames = PARAM_NAMES;

  const int ANALOG_MAP_SIZE = 5;
  int analogMap[ANALOG_MAP_SIZE] = {0,1,2,3,4};
  setAnalogMap(analogMap, ANALOG_MAP_SIZE);

  const int MENU_ITEM_MAP_SIZE = 1;
  int menuItemMap[MENU_ITEM_MAP_SIZE] = {3};
  char const** menuItemOptions[MENU_ITEM_MAP_SIZE] = {
    BitshiftPreset::OPTIONS_BOOLEAN
  };

  int menuItemOptionsTotals[MENU_ITEM_MAP_SIZE] = {
    BitshiftPreset::OPTIONS_BOOLEAN_TOTAL
  };

  setMenuItemMap(menuItemMap, MENU_ITEM_MAP_SIZE, menuItemOptions, menuItemOptionsTotals);
}

int BitshiftPresetTremolo::paramValueInt(int paramId) const
{
  switch(paramId)
  {
    case DIVISION:
      return 0; // temp (todo)
  }
  return -1;
}

void BitshiftPresetTremolo::paramValueString(char* str, int paramId) const
{
  switch(paramId)
  {
    case SPEED:
      sprintf(str, "%0.1fHz", params.speed);
      return;

    case DEPTH:
      sprintf(str, "%0.0f%%", params.depth * 100.0);
      return;

    case SHAPEANDMOD:
      sprintf(str, BitshiftEffectLfo::OPTIONS_SHAPE[(int)params.shapeAndMod]);
      return;

    case DIVISION:
      sprintf(str, "...");
      return;

    case VOLUME:
      sprintf(str, "%0.0f%%", params.volume * 100.0);
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

    case SHAPEANDMOD:
    {
      // 0.0 - 5.0
      setParam(paramId, floatRange(value, 0.0, 5.0, false));
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

    case SHAPEANDMOD:
      params.shapeAndMod = tremolo.shapeAndMod(value);
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
    case DIVISION:
      params.division = tremolo.division(value);
      return;
  }
}
