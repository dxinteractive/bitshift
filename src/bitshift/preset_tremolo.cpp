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
#include "utils.h"
#include "visualizationdata.h"

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
  initBase(
    &tremolo,
    &params,
    NAME,
    PARAM_NAMES,
    PARAMS_TOTAL
  );

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

  setMenuItemMap(
    menuItemMap,
    MENU_ITEM_MAP_SIZE,
    menuItemOptions,
    menuItemOptionsTotals
  );
}

void BitshiftPresetTremolo::initialParams()
{
  setParam(SPEED, 3.0);
  setParam(DEPTH, 0.5);
  setParam(SHAPEANDMOD, 0.5);
  setParam(DIVISION, 0);
  setParam(VOLUME, 1.0);
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
      floatToString(params.speed, 1, "%sHz", str);
      return;

    case DEPTH:
      floatToString(params.depth * 100.0, 0, "%s%%", str);
      return;

    case SHAPEANDMOD:
      sprintf(str, BitshiftEffectLfo::OPTIONS_SHAPE[(int)params.shapeAndMod]);
      return;

    case DIVISION:
      sprintf(str, "...");
      return;

    case VOLUME:
      floatToString(params.volume * 100.0, 0, "%s%%", str);
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
      // linear range from 0.0 to 1.0
      setParam(paramId, value);
      return;

    case VOLUME:
      // squared range from 0.0 to 2.0
      setParam(paramId, value * value * 2.0);
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

// BitshiftVisualizationData const* BitshiftPresetTremolo::paramVisualizationData(int paramId)
// {
//   //if(paramId == SHAPEANDMOD)
//  // {
//     return tremolo.waveformVisualization();
//  // }

//   //return 0;
// }
