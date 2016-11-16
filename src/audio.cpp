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
  BitshiftPreset* preset = presets[activePreset];
  return preset ? preset->name() : "";
}

char const* BitshiftAudio::paramName(int paramId) const
{
  BitshiftPreset* preset = presets[activePreset];
  return preset ? preset->paramName(paramId) : "";
}

char const* BitshiftAudio::analogParamName(int analogId) const
{
  BitshiftPreset* preset = presets[activePreset];
  return preset ? preset->analogParamName(analogId) : "";
}

char const* BitshiftAudio::menuItemParamName(int itemId) const
{
  BitshiftPreset* preset = presets[activePreset];
  return preset ? preset->menuItemParamName(itemId) : "";
}

int BitshiftAudio::paramsTotal() const
{
  BitshiftPreset* preset = presets[activePreset];
  return preset ? preset->paramsTotal() : 0;
}

int BitshiftAudio::analogParamsTotal() const
{
  BitshiftPreset* preset = presets[activePreset];
  return preset ? preset->analogParamsTotal() : 0;
}


int BitshiftAudio::menuItemParamsTotal() const
{
  BitshiftPreset* preset = presets[activePreset];
  return preset ? preset->menuItemParamsTotal() : 0;
}


void BitshiftAudio::setParam(int id, int value)
{
  BitshiftPreset* preset = presets[activePreset];
  if(preset)
    preset->setParam(id, value);
}

void BitshiftAudio::setParam(int id, float value)
{
  BitshiftPreset* preset = presets[activePreset];
  if(preset)
    preset->setParam(id, value);
}

void BitshiftAudio::setAnalogParam(int analogId, float value)
{
  BitshiftPreset* preset = presets[activePreset];
  if(preset)
    preset->setAnalogParam(analogId, value);
}

void BitshiftAudio::setMenuItemParam(int itemId, int value)
{
  BitshiftPreset* preset = presets[activePreset];
  if(preset)
    preset->setMenuItemParam(itemId, value);
}
