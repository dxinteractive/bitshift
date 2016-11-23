/*
 * preset_tremolo
 * Tremolo effect (modulations in volume)
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
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

BitshiftPresetTremolo::BitshiftPresetTremolo():
  BitshiftPreset()
{
  params.speed = 1.0;
  params.depth = 0.5;
  params.shape = 3;
  params.division = 0;
  params.bias = 0.2;
  params.volume = 0.8;

  thisName = NAME;
  thisParamsTotal = PARAMS_TOTAL;
  thisParamNames = PARAM_NAMES;

  const int ANALOG_MAP_SIZE = 6;
  int analogMap[ANALOG_MAP_SIZE] = {0,1,2,3,4,5};
  setAnalogMap(analogMap, ANALOG_MAP_SIZE);

  const int MENU_ITEM_MAP_SIZE = 1;
  int menuItemMap[MENU_ITEM_MAP_SIZE] = {3};
  setMenuItemMap(menuItemMap, MENU_ITEM_MAP_SIZE);
}

void BitshiftPresetTremolo::paramValueString(char* str, int paramId) const
{
  int fingers = 5;
  sprintf(str, "Poo %d", fingers);
}

void BitshiftPresetTremolo::setAnalogParam(int analogId, float value)
{
  int paramId = paramIdByAnalogId(analogId);
  switch(paramId)
  {
    case SPEED:
      //value = setParam(paramId, value);
      break;
    case DEPTH:
      //value = setParam(paramId, value);
      break;
    case BIAS:
      //value = setParam(paramId, value);
      break;
    case VOLUME:
      //value = setParam(paramId, value);
      break;
    default:
      return;
  }
  setParam(paramId, value);
}

void BitshiftPresetTremolo::setMenuItemParam(int itemId, int value)
{
  int paramId = paramIdByMenuItemId(itemId);
  switch(paramId)
  {
    case SHAPE:
    case DIVISION:
      break;
    default:
      return;
  }
  setParam(paramId, value);
}

void BitshiftPresetTremolo::setParam(int paramId, float value)
{
  if(paramId >= paramsTotal() || paramId < 0) return;

  switch(paramId)
  {
    case SPEED:
      BitshiftPresetTremolo::tremolo.speed(value);
      params.speed = value;
      return;
    case DEPTH:
      BitshiftPresetTremolo::tremolo.depth(value);
      params.depth = value;
      return;
    case VOLUME:
      BitshiftPresetTremolo::tremolo.volume(value);
      params.volume = value;
      return;
  }
}

void BitshiftPresetTremolo::setParam(int paramId, int value)
{
  if(paramId >= paramsTotal() || paramId < 0) return;

  switch(paramId)
  {
    case SHAPE:
      BitshiftPresetTremolo::tremolo.shape(value);
      params.shape = value;
      return;
    case DIVISION:
      BitshiftPresetTremolo::tremolo.division(value);
      params.division = value;
      return;
  }
}
