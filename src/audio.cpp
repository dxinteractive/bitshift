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

char const* BitshiftAudio::presetName()
{
  BitshiftPreset* preset = presets[activePreset];
  return preset ? preset->name() : "";
}

char const** BitshiftAudio::presetParamNames()
{
  BitshiftPreset* preset = presets[activePreset];
  return preset ? preset->paramNames() : 0;
}

int BitshiftAudio::getPresetParam(int id)
{
  BitshiftPreset* preset = presets[activePreset];
  return preset ? preset->getParam(id) : 0;
}

float BitshiftAudio::getPresetParamAnalog(int id)
{
  BitshiftPreset* preset = presets[activePreset];
  return preset ? preset->getParamAnalog(id) : 0.0;
}

void BitshiftAudio::setPresetParam(int id, int value)
{
  BitshiftPreset* preset = presets[activePreset];
  if(preset)
    preset->setParam(id, value);
}

void BitshiftAudio::setPresetParamAnalog(int id, float value)
{
  BitshiftPreset* preset = presets[activePreset];
  if(preset)
    preset->setParamAnalog(id, value);
}
