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

class BitshiftAudio
{
  public:
    BitshiftAudio(BitshiftPreset** presets, int presetsTotal);
    ~BitshiftAudio();

    void setup();
    void update();

    char const* presetName();
    char const** presetParamNames();

    int getPresetParam(int id);
    float getPresetParamAnalog(int id);
    void setPresetParam(int id, int value);
    void setPresetParamAnalog(int id, float value);

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
