/*
 * audio
 * Abstract base class responsible for all audio management
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_AUDIO_H
#define BITSHIFT_AUDIO_H

class BitshiftAudio
{
  public:
    BitshiftAudio() {}
    virtual ~BitshiftAudio() {}

    virtual void setup() = 0;
    virtual void update() = 0;

    virtual int setActivePreset(int presetId) = 0;
    virtual int nextPreset() = 0;
    virtual int prevPreset() = 0;

    virtual char const* presetName() const = 0;
    virtual char const* paramName(int paramId) const = 0;
    virtual char const* analogParamName(int analogId) const = 0;
    virtual char const* menuItemParamName(int itemId) const = 0;
    virtual char const** menuItemParamOptions(int itemId) const = 0;

    virtual void paramValueString(char* str, int paramId) const = 0;
    virtual void analogParamValueString(char* str, int analogId) const = 0;
    virtual void menuItemParamValueString(char* str, int itemId) const = 0;

    virtual int paramsTotal() const = 0;
    virtual int analogParamsTotal() const = 0;
    virtual int menuItemParamsTotal() const = 0;

    virtual void setParam(int paramId, int value) = 0;
    virtual void setParam(int paramId, float value) = 0;
    virtual void setAnalogParam(int analogId, float value) = 0;
    virtual void setMenuItemParam(int itemId, int value) = 0;
};

#endif
