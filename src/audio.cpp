/*
 * audio
 * Class responsible for all audio management
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#include "audio.h"
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "preset.h"

BitshiftAudio::BitshiftAudio(BitshiftPreset** presets, int presetsTotal):
  presets(presets),
  presetsTotal(presetsTotal),
  inToOut(audioIn, 0, audioOut, 0)
{
}

BitshiftAudio::~BitshiftAudio()
{
}

void BitshiftAudio::setup()
{
  AudioMemory(12);
  audioAdaptor.enable();
  audioAdaptor.inputSelect(AUDIO_INPUT_LINEIN);
  audioAdaptor.micGain(0);
  audioAdaptor.muteHeadphone();
  // disable adc hp as it causes noise to kick in when no input audio is detected
  audioAdaptor.adcHighPassFilterDisable();
  // good combination for minimum ADC noise when used with non-active guitar as input
  // large line in sensitivity, bring down dac and volume so overall gain is close to unity
  audioAdaptor.lineInLevel(12);
  audioAdaptor.lineOutLevel(31);
  audioAdaptor.dacVolume(0.9);
}

void BitshiftAudio::update()
{
}

void BitshiftAudio::nextPreset()
{
  activePreset++;
  if(activePreset >= presetsTotal)
    activePreset = 0;
}

void BitshiftAudio::prevPreset()
{
  activePreset--;
  if(activePreset < 0)
    activePreset = presetsTotal - 1;
}

char const* BitshiftAudio::presetName() const
{
  return presets[activePreset]->name();
}

char const* BitshiftAudio::paramName(int paramId) const
{
  return presets[activePreset]->paramName(paramId);
}

char const* BitshiftAudio::analogParamName(int analogId) const
{
  return presets[activePreset]->analogParamName(analogId);
}

char const* BitshiftAudio::menuItemParamName(int itemId) const
{
  return presets[activePreset]->menuItemParamName(itemId);
}

void BitshiftAudio::paramValueString(char* str, int paramId) const
{
  presets[activePreset]->paramValueString(str, paramId);
}

void BitshiftAudio::analogParamValueString(char* str, int paramId) const
{
  presets[activePreset]->analogParamValueString(str, paramId);
}

void BitshiftAudio::menuItemParamValueString(char* str, int itemId) const
{
  presets[activePreset]->menuItemParamValueString(str, itemId);
}

int BitshiftAudio::paramsTotal() const
{
  return presets[activePreset]->paramsTotal();
}

int BitshiftAudio::analogParamsTotal() const
{
  return presets[activePreset]->analogParamsTotal();
}


int BitshiftAudio::menuItemParamsTotal() const
{
  return presets[activePreset]->menuItemParamsTotal();
}


void BitshiftAudio::setParam(int id, int value)
{
    presets[activePreset]->setParam(id, value);
}

void BitshiftAudio::setParam(int id, float value)
{
    presets[activePreset]->setParam(id, value);
}

void BitshiftAudio::setAnalogParam(int analogId, float value)
{
    presets[activePreset]->setAnalogParam(analogId, value);
}

void BitshiftAudio::setMenuItemParam(int itemId, int value)
{
    presets[activePreset]->setMenuItemParam(itemId, value);
}
