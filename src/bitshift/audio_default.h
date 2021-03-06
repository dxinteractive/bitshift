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

#ifndef BITSHIFT_AUDIO_DEFAULT_H
#define BITSHIFT_AUDIO_DEFAULT_H

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "audio.h"
#include "preset.h"
#include "router.h"
#include "visualizationdata.h"

class BitshiftAudioDefault: public BitshiftAudio
{
  public:
    BitshiftAudioDefault(
      AudioStream& audioIn,
      int audioInChannel,
      BitshiftPreset** presets,
      int presetsTotal,
      AudioStream& audioOut,
      int audioOutChannel
    );
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
    virtual char const** menuItemParamOptions(int itemId) const;

    virtual int menuItemParamValueInt(int itemId) const;

    virtual void paramValueString(char* str, int paramId) const;
    virtual void analogParamValueString(char* str, int analogId) const;
    virtual void menuItemParamValueString(char* str, int itemId) const;

    virtual int tapAssignment(int tapId) const;
    virtual int expAssignment(int expId) const;

    virtual int paramsTotal() const;
    virtual int analogParamsTotal() const;
    virtual int menuItemParamsTotal() const;
    virtual int menuItemParamOptionsTotal(int itemId) const;

    virtual void setParam(int paramId, int value);
    virtual void setParam(int paramId, float value);
    virtual void setAnalogParam(int analogId, float value);
    virtual void setMenuItemParam(int itemId, int value);
    virtual void setExpParam(int expId, float value);
    virtual void setExpAssignment(int expId, int analogId);
    virtual void setTapAssignment(int tapId, int tapOptionId);
    virtual void eventTap(int tapId, int value);

    // virtual BitshiftVisualizationData const* paramVisualizationData(int paramId);
    // virtual BitshiftVisualizationData const* analogParamVisualizationData(int analogId);
    // virtual BitshiftVisualizationData const* menuItemParamVisualizationData(int itemId);

  private:
    BitshiftPreset** presets;
    int presetsTotal;
    int activePreset;

    BitshiftRouter router;
    AudioControlSGTL5000 audioAdaptor;
};

#endif
