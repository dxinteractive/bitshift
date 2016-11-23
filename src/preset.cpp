/*
 * preset
 * Base class for presets, complete effects that can be used one at a time
 * consisting of configurations of audio effects, audio routing and controllers
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#include "preset.h"

BitshiftPreset::~BitshiftPreset()
{
  clearAnalogMap();
  clearMenuItemMap();
  //deletePresets(paramsTotal());
}

// void BitshiftPreset::deletePresets(int totalPresets)
// {
//   for(int i = 0; i < totalPresets; i++)
//     delete[] state[i];

//   delete[] state;
// }

char const* BitshiftPreset::paramName(int paramId) const
{
  if(paramId >= thisParamsTotal || paramId < 0)
    return "";

  return thisParamNames[paramId];
}

char const* BitshiftPreset::analogParamName(int analogId) const
{
  return paramName(paramIdByAnalogId(analogId));
}

char const* BitshiftPreset::menuItemParamName(int itemId) const
{
  return paramName(paramIdByMenuItemId(itemId));
}

void BitshiftPreset::analogParamValueString(char* str, int analogId) const
{
  paramValueString(str, paramIdByAnalogId(analogId));
}

void BitshiftPreset::menuItemParamValueString(char* str, int itemId) const
{
  paramValueString(str, paramIdByMenuItemId(itemId));
}

int BitshiftPreset::paramIdByAnalogId(int analogId) const
{
  if(analogId >= analogMapSize || analogId < 0)
    return -1;

  return analogMap[analogId];
}

int BitshiftPreset::paramIdByMenuItemId(int itemId) const
{
  if(itemId >= menuItemMapSize || itemId < 0)
    return -1;

  return menuItemMap[itemId];
}

void BitshiftPreset::setAnalogMap(int inputMap[], int size)
{
  clearAnalogMap();

  analogMap = new int[size];
  analogMapSize = size;
  for(int i = 0; i < size; i++)
    analogMap[i] = inputMap[i];
}

void BitshiftPreset::setMenuItemMap(int inputMap[], int size)
{
  clearMenuItemMap();

  menuItemMap = new int[size];
  menuItemMapSize = size;
  for(int i = 0; i < size; i++)
    menuItemMap[i] = inputMap[i];
}

void BitshiftPreset::clearAnalogMap()
{
  delete [] analogMap;
  analogMapSize = 0;
}

void BitshiftPreset::clearMenuItemMap()
{
  delete [] menuItemMap;
  menuItemMapSize = 0;
}
