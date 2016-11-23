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

#ifndef BITSHIFT_AUDIO_H
#define BITSHIFT_AUDIO_H

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "preset.h"

class BitshiftAudio // make extend from base class
{
  public:
    BitshiftAudio(BitshiftPreset** presets, int presetsTotal);
    ~BitshiftAudio();

    void setup();
    void update();

    void nextPreset();
    void prevPreset();

    char const* presetName() const;
    char const* paramName(int paramId) const;
    char const* analogParamName(int analogId) const;
    char const* menuItemParamName(int itemId) const;

    void paramValueString(char* str, int paramId) const;
    void analogParamValueString(char* str, int analogId) const;
    void menuItemParamValueString(char* str, int itemId) const;

    int paramsTotal() const;
    int analogParamsTotal() const;
    int menuItemParamsTotal() const;

    void setParam(int paramId, int value);
    void setParam(int paramId, float value);
    void setAnalogParam(int analogId, float value);
    void setMenuItemParam(int itemId, int value);

  private:
    BitshiftPreset** presets;
    int presetsTotal;
    int activePreset;

    AudioInputI2S audioIn; // move these out to .ino?
    AudioOutputI2S audioOut;
    AudioConnection inToOut;
    AudioControlSGTL5000 audioAdaptor;
};

#endif
