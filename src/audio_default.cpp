/*
 * audio_default
 * Class responsible for all audio management
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "audio.h"
#include "audio_default.h"
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "preset.h"

BitshiftAudioDefault::BitshiftAudioDefault(
  AudioStream& audioIn,
  int audioInChannel,
  BitshiftPreset** presets,
  int presetsTotal,
  AudioStream& audioOut,
  int audioOutChannel
):
  BitshiftAudio(),
  presets(presets),
  presetsTotal(presetsTotal),
  router(
    audioIn,
    audioInChannel,
    presets,
    presetsTotal,
    audioOut,
    audioOutChannel
  )
{
}

void BitshiftAudioDefault::setup()
{
  // todo: pass into constructor
  AudioMemory(180);
  // todo: move this out and apply via a default config
  audioAdaptor.enable();
  audioAdaptor.inputSelect(AUDIO_INPUT_LINEIN);
  audioAdaptor.micGain(0);
  audioAdaptor.muteHeadphone();
  // disable adc hp as it causes noise to kick in when no input audio is detected
  audioAdaptor.adcHighPassFilterDisable();
  // good combination for minimum ADC noise when used with non-active guitar as input
  // large line in sensitivity, bring down dac and volume so overall gain is close to unity
  audioAdaptor.lineInLevel(15);
  audioAdaptor.lineOutLevel(31);
  audioAdaptor.dacVolume(0.9);

  setActivePreset(0);
}

void BitshiftAudioDefault::update()
{
}

int BitshiftAudioDefault::setActivePreset(int presetId)
{
  if(presetId >= presetsTotal || presetId < 0)
    presetId = 0;

  activePreset = presetId;
  router.setActivePreset(activePreset);
  return activePreset;
}

int BitshiftAudioDefault::nextPreset()
{
  int newPresetId = activePreset + 1;
  if(newPresetId >= presetsTotal)
    newPresetId = 0;

  return setActivePreset(newPresetId);
}

int BitshiftAudioDefault::prevPreset()
{
  int newPresetId = activePreset - 1;
  if(newPresetId < 0)
    newPresetId = presetsTotal - 1;

  return setActivePreset(newPresetId);
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

char const** BitshiftAudioDefault::menuItemParamOptions(int itemId) const
{
  return presets[activePreset]->menuItemParamOptions(itemId);
}

int BitshiftAudioDefault::menuItemParamValueInt(int itemId) const
{
  return presets[activePreset]->menuItemParamValueInt(itemId);
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

int BitshiftAudioDefault::menuItemParamOptionsTotal(int itemId) const
{
  return presets[activePreset]->menuItemParamOptionsTotal(itemId);
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
