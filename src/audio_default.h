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

#ifndef BITSHIFT_AUDIO_DEFAULT_H
#define BITSHIFT_AUDIO_DEFAULT_H

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "audio.h"
#include "preset.h"

class BitshiftAudioDefault: public BitshiftAudio
{
  public:
    BitshiftAudioDefault(BitshiftPreset** presets, int presetsTotal);
    ~BitshiftAudioDefault() {}

    virtual void setup();
    virtual void update();

    virtual int setActivePreset(int presetId);
    virtual int nextPreset();
    virtual int prevPreset();

    virtual char const* presetName() const;
    virtual char const* paramName(int paramId) const;
    virtual char const* analogParamName(int analogId) const;
    virtual char const* menuItemParamName(int itemId) const;

    virtual void paramValueString(char* str, int paramId) const;
    virtual void analogParamValueString(char* str, int analogId) const;
    virtual void menuItemParamValueString(char* str, int itemId) const;

    virtual int paramsTotal() const;
    virtual int analogParamsTotal() const;
    virtual int menuItemParamsTotal() const;

    virtual void setParam(int paramId, int value);
    virtual void setParam(int paramId, float value);
    virtual void setAnalogParam(int analogId, float value);
    virtual void setMenuItemParam(int itemId, int value);

  private:
    BitshiftPreset** presets;
    int presetsTotal;
    int activePreset;

    AudioInputI2S audioIn;
    AudioOutputI2S audioOut;
    AudioConnection inToOut;
    AudioControlSGTL5000 audioAdaptor;
};

#endif
