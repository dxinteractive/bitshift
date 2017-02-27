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
\

void BitshiftPreset::initBase(
  BitshiftEffect* effect,
  BitshiftParamset* paramset,
  char const* name,
  char const** paramNames,
  int paramsTotal
) {
  this->effect = effect;
  this->paramset = paramset;
  this->patchSendToEffect = new AudioConnection(
    send,
    0,
    *(effect->audioIn()),
    effect->audioInChannel()
  );

  this->_name = name;
  this->_paramNames = paramNames;
  this->_paramsTotal = paramsTotal;
}

void BitshiftPreset::setup()
{
  if(!effect) return;
  effect->setup();
}

void BitshiftPreset::audioEnable() {
  effect->audioEnable();
  send.fadeIn(10);
}

void BitshiftPreset::audioDisable() {
  effect->audioDisable(); // todo, do we need to delay this?
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
  if(paramId >= _paramsTotal || paramId < 0)
    return "";

  return _paramNames[paramId];
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

int BitshiftPreset::expAssignment(int expId) const
{
  if(!paramset || expId < 0 || expId >= EXPASSIGN_MAX)
    return -1;

  return paramset->expAssignment[expId];
}

int BitshiftPreset::tapAssignment(int tapId) const
{
  if(!paramset || tapId < 0 || tapId >= TAPASSIGN_MAX)
    return -1;

  return paramset->tapAssignment[tapId];
}

int BitshiftPreset::menuItemParamOptionsTotal(int itemId) const
{
  return optionsTotalByMenuItemId(itemId);
}

void BitshiftPreset::setExpAssignment(int expId, int analogId)
{
  if(!paramset
    || expId < 0
    || expId >= EXPASSIGN_MAX
    || analogId < -1
    || analogId >= _analogMapSize
  ) return;

  paramset->expAssignment[expId] = analogId;
}

int BitshiftPreset::paramIdByAnalogId(int analogId) const
{
  if(analogId >= _analogMapSize || analogId < 0)
    return -1;

  return _analogMap[analogId];
}

int BitshiftPreset::paramIdByMenuItemId(int itemId) const
{
  if(!_menuItemMap || itemId >= _menuItemMapSize || itemId < 0)
    return -1;

  return _menuItemMap[itemId];
}

char const** BitshiftPreset::optionsByMenuItemId(int itemId) const
{
  if(!_menuItemOptions || itemId >= _menuItemMapSize || itemId < 0)
    return NULL;

  return _menuItemOptions[itemId];
}

int BitshiftPreset::optionsTotalByMenuItemId(int itemId) const
{
  if(!_menuItemOptionsTotal || itemId >= _menuItemMapSize || itemId < 0)
    return -1;

  return _menuItemOptionsTotal[itemId];
}

void BitshiftPreset::setAnalogMap(int inputMap[], int size)
{
  clearAnalogMap();

  _analogMap = new int[size];
  _analogMapSize = size;
  for(int i = 0; i < size; i++)
    _analogMap[i] = inputMap[i];
}

void BitshiftPreset::setMenuItemMap(
  int inputMap[],
  int size,
  char const** inputOptions[],
  int inputOptionsTotals[]
)
{
  clearMenuItemMap();

  _menuItemMap = new int[size];
  _menuItemMapSize = size;
  for(int i = 0; i < size; i++)
    _menuItemMap[i] = inputMap[i];

  if(inputOptions)
  {
    _menuItemOptions = new char const**[size];
    _menuItemOptionsTotal = new int[size];
    for(int i = 0; i < size; i++)
    {
      _menuItemOptions[i] = inputOptions[i];
      _menuItemOptionsTotal[i] = inputOptionsTotals[i];
    }
  }
}

void BitshiftPreset::clearAnalogMap()
{
  delete [] _analogMap;
  _analogMapSize = 0;
}

void BitshiftPreset::clearMenuItemMap()
{
  delete [] _menuItemMap;
  delete [] _menuItemOptions;
  delete [] _menuItemOptionsTotal;
  _menuItemMapSize = 0;
}

//
// helpers for derived classes to set param values
//

int BitshiftPreset::intRange(float value, int min, int max)
{
  int intValue = int(value * (max - min + 1)) + min;
  if(intValue > max)
    intValue = max;

  return intValue;
}

float BitshiftPreset::floatRange(float value, float min, float max, bool inclusive)
{
  value = ((1.0 - value) * min) + (value * max);
  if(!inclusive && value == max)
    value -= 0.00001; // todo: actually look up and use smallest possible decrement for a float...

  return value;
}
