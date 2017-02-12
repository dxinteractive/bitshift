/*
 * preset
 * Base class for presets, complete effects that can be used one at a time
 * consisting of configurations of audio effects, audio routing and controllers
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "preset.h"
#include <Audio.h>

char const* BitshiftPreset::OPTIONS_BOOLEAN[] = {
  "Off",
  "On"
};

BitshiftPreset::BitshiftPreset()
{
  // start every preset muted
  send.fadeOut(1);
}

BitshiftPreset::~BitshiftPreset()
{
  clearAnalogMap();
  clearMenuItemMap();
  delete patchSendToEffect;
}

void BitshiftPreset::setEffect(BitshiftEffect* effect) {
  this->effect = effect;
  this->patchSendToEffect = new AudioConnection(
    send,
    0,
    *(effect->audioIn()),
    effect->audioInChannel()
  );
}

void BitshiftPreset::audioEnable() {
  send.fadeIn(10);
}

void BitshiftPreset::audioDisable() {
  send.fadeOut(10);
}

AudioStream* BitshiftPreset::audioIn() {
  return &send;
}

AudioStream* BitshiftPreset::audioOut() {
  return effect ? effect->audioOut() : NULL;
}

int BitshiftPreset::audioInChannel() const {
  return effect ? effect->audioInChannel() : 0;
}

int BitshiftPreset::audioOutChannel() const {
  return effect ? effect->audioOutChannel() : 0;
}

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

char const** BitshiftPreset::menuItemParamOptions(int itemId) const
{
  return optionsByMenuItemId(itemId);
}

int BitshiftPreset::menuItemParamValueInt(int itemId) const
{
  return paramValueInt(paramIdByMenuItemId(itemId));
}

void BitshiftPreset::analogParamValueString(char* str, int analogId) const
{
  paramValueString(str, paramIdByAnalogId(analogId));
}

void BitshiftPreset::menuItemParamValueString(char* str, int itemId) const
{
  paramValueString(str, paramIdByMenuItemId(itemId));
}

int BitshiftPreset::menuItemParamOptionsTotal(int itemId) const
{
  return optionsTotalByMenuItemId(itemId);
}

int BitshiftPreset::paramIdByAnalogId(int analogId) const
{
  if(analogId >= analogMapSize || analogId < 0)
    return -1;

  return analogMap[analogId];
}

int BitshiftPreset::paramIdByMenuItemId(int itemId) const
{
  if(!menuItemMap || itemId >= menuItemMapSize || itemId < 0)
    return -1;

  return menuItemMap[itemId];
}

char const** BitshiftPreset::optionsByMenuItemId(int itemId) const
{
  if(!menuItemOptions || itemId >= menuItemMapSize || itemId < 0)
    return NULL;

  return menuItemOptions[itemId];
}

int BitshiftPreset::optionsTotalByMenuItemId(int itemId) const
{
  if(!menuItemOptionsTotal || itemId >= menuItemMapSize || itemId < 0)
    return -1;

  return menuItemOptionsTotal[itemId];
}

void BitshiftPreset::setAnalogMap(int inputMap[], int size)
{
  clearAnalogMap();

  analogMap = new int[size];
  analogMapSize = size;
  for(int i = 0; i < size; i++)
    analogMap[i] = inputMap[i];
}

void BitshiftPreset::setMenuItemMap(
  int inputMap[],
  int size,
  char const** inputOptions[],
  int inputOptionsTotals[]
)
{
  clearMenuItemMap();

  menuItemMap = new int[size];
  menuItemMapSize = size;
  for(int i = 0; i < size; i++)
    menuItemMap[i] = inputMap[i];

  if(inputOptions)
  {
    menuItemOptions = new char const**[size];
    menuItemOptionsTotal = new int[size];
    for(int i = 0; i < size; i++)
    {
      menuItemOptions[i] = inputOptions[i];
      menuItemOptionsTotal[i] = inputOptionsTotals[i];
    }
  }
}

void BitshiftPreset::clearAnalogMap()
{
  delete [] analogMap;
  analogMapSize = 0;
}

void BitshiftPreset::clearMenuItemMap()
{
  delete [] menuItemMap;
  delete [] menuItemOptions;
  delete [] menuItemOptionsTotal;
  menuItemMapSize = 0;
}

int BitshiftPreset::intRange(float value, int min, int max)
{
  int intValue = int(value * (max - min + 1)) + min;
  if(intValue > max)
    intValue = max;

  return intValue;
}
