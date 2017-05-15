/*
 * preset
 * Base class for presets, complete effects that can be used one at a time
 * consisting of configurations of audio effects, audio routing and controllers
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_PRESET_H
#define BITSHIFT_PRESET_H

#include <Audio.h>
#include "effect.h"
#include "paramset.h"
#include "visualizationdata.h"

class BitshiftPreset
{
  public:
    BitshiftPreset();
    virtual ~BitshiftPreset();

    void setup();
    virtual void initialParams() {}

    void audioEnable();
    void audioDisable();

    AudioStream* audioIn();
    AudioStream* audioOut();
    int audioInChannel() const;
    int audioOutChannel() const;

    inline char const* name() const { return _name; }
    char const* paramName(int paramId) const;
    char const* analogParamName(int analogId) const;
    char const* menuItemParamName(int itemId) const;
    char const** menuItemParamOptions(int itemId) const;

    virtual int paramValueInt(int paramId) const { return -1; }
    int menuItemParamValueInt(int paramId) const;

    virtual void paramValueString(char* str, int paramId) const {}
    void analogParamValueString(char* str, int analogId) const;
    void menuItemParamValueString(char* str, int itemId) const;

    int expAssignment(int expId) const;
    int tapAssignment(int tapId) const;

    inline int paramsTotal() const { return _paramsTotal; }
    inline int analogParamsTotal() const { return _analogMapSize; }
    inline int menuItemParamsTotal() const { return _menuItemMapSize; }
    int menuItemParamOptionsTotal(int itemId) const;

    virtual void setParam(int paramId, int value) {}
    virtual void setParam(int paramId, float value) {}
    virtual void setAnalogParam(int analogId, float value) {}
    virtual void setMenuItemParam(int itemId, int value) {}
    virtual void eventTap(int tapId, int value) {}
    void setExpParam(int expId, float value);
    void setExpAssignment(int expId, int analogId);
    void setTapAssignment(int tapId, int tapOptionId);

    // virtual BitshiftVisualizationData const* paramVisualizationData(int paramId) { return 0; }
    // BitshiftVisualizationData const* analogParamVisualizationData(int analogId);
    // BitshiftVisualizationData const* menuItemParamVisualizationData(int itemId);

    int paramIdByAnalogId(int analogId) const;
    int paramIdByMenuItemId(int itemId) const;
    char const** optionsByMenuItemId(int itemId) const;
    int optionsTotalByMenuItemId(int itemId) const;

  protected:
    void initBase(
      BitshiftEffect* effect,
      BitshiftParamset* paramset,
      char const* name,
      char const** paramNames,
      int paramsTotal
    );

    void setAnalogMap(
      int inputMap[],
      int size
    );

    void setMenuItemMap(
      int inputMap[],
      int size,
      char const** inputOptions[] = NULL,
      int inputOptionsTotals[] = NULL
    );

    int intRange(float value, int min, int max);
    float floatRange(float value, float min, float max, bool inclusive = true);

    static const int OPTIONS_BOOLEAN_TOTAL = 2;
    static char const* OPTIONS_BOOLEAN[OPTIONS_BOOLEAN_TOTAL];

  private:
    void clearAnalogMap();
    void clearMenuItemMap();

    AudioEffectFade send;
    AudioConnection* patchSendToEffect;

    BitshiftEffect* effect;
    BitshiftParamset* paramset;

    char const* _name;
    char const** _paramNames;
    int _paramsTotal;

    int _analogMapSize;
    int* _analogMap;

    int _menuItemMapSize;
    int* _menuItemMap;
    char const*** _menuItemOptions;
    int* _menuItemOptionsTotal;
};

#endif
