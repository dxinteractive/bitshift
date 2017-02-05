/*
 * audio_default
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
#include "audio_default.h"
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "preset.h"

BitshiftAudioDefault::BitshiftAudioDefault(BitshiftPreset** presets, int presetsTotal):
  BitshiftAudio(),
  presets(presets),
  presetsTotal(presetsTotal),
  inToOut(audioIn, 0, audioOut, 0)
{
}

void BitshiftAudioDefault::setup()
{
  // "12" is arbitrary right now (todo, adjust for reasons)
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

void BitshiftAudioDefault::update()
{
}

void BitshiftAudioDefault::nextPreset()
{
  activePreset++;
  if(activePreset >= presetsTotal)
    activePreset = 0;
}

void BitshiftAudioDefault::prevPreset()
{
  activePreset--;
  if(activePreset < 0)
    activePreset = presetsTotal - 1;
}

char const* BitshiftAudioDefault::presetName() const
{
  return presets[activePreset]->name();
}

char const* BitshiftAudioDefault::paramName(int paramId) const
{
  return presets[activePreset]->paramName(paramId);
}

char const* BitshiftAudioDefault::analogParamName(int analogId) const
{
  return presets[activePreset]->analogParamName(analogId);
}

char const* BitshiftAudioDefault::menuItemParamName(int itemId) const
{
  return presets[activePreset]->menuItemParamName(itemId);
}

void BitshiftAudioDefault::paramValueString(char* str, int paramId) const
{
  presets[activePreset]->paramValueString(str, paramId);
}

void BitshiftAudioDefault::analogParamValueString(char* str, int paramId) const
{
  presets[activePreset]->analogParamValueString(str, paramId);
}

void BitshiftAudioDefault::menuItemParamValueString(char* str, int itemId) const
{
  presets[activePreset]->menuItemParamValueString(str, itemId);
}

int BitshiftAudioDefault::paramsTotal() const
{
  return presets[activePreset]->paramsTotal();
}

int BitshiftAudioDefault::analogParamsTotal() const
{
  return presets[activePreset]->analogParamsTotal();
}

int BitshiftAudioDefault::menuItemParamsTotal() const
{
  return presets[activePreset]->menuItemParamsTotal();
}

void BitshiftAudioDefault::setParam(int id, int value)
{
  presets[activePreset]->setParam(id, value);
}

void BitshiftAudioDefault::setParam(int id, float value)
{
  presets[activePreset]->setParam(id, value);
}

void BitshiftAudioDefault::setAnalogParam(int analogId, float value)
{
  presets[activePreset]->setAnalogParam(analogId, value);
}

void BitshiftAudioDefault::setMenuItemParam(int itemId, int value)
{
  presets[activePreset]->setMenuItemParam(itemId, value);
}
