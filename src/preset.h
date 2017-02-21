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

class BitshiftPreset
{
  public:
    BitshiftPreset();
    virtual ~BitshiftPreset();

    void audioEnable();
    void audioDisable();

    AudioStream* audioIn();
    AudioStream* audioOut();
    int audioInChannel() const;
    int audioOutChannel() const;

    inline char const* name() const { return thisName; }
    char const* paramName(int paramId) const;
    char const* analogParamName(int analogId) const;
    char const* menuItemParamName(int itemId) const;
    char const** menuItemParamOptions(int itemId) const;

    virtual int paramValueInt(int paramId) const { return -1; }
    int menuItemParamValueInt(int paramId) const;

    virtual void paramValueString(char* str, int paramId) const {}
    void analogParamValueString(char* str, int analogId) const;
    void menuItemParamValueString(char* str, int itemId) const;

    inline int paramsTotal() const { return thisParamsTotal; }
    inline int analogParamsTotal() const { return analogMapSize; }
    inline int menuItemParamsTotal() const { return menuItemMapSize; }
    int menuItemParamOptionsTotal(int itemId) const;

    virtual void setParam(int paramId, int value) {}
    virtual void setParam(int paramId, float value) {}
    virtual void setAnalogParam(int analogId, float value) {}
    virtual void setMenuItemParam(int itemId, int value) {}

    int paramIdByAnalogId(int analogId) const;
    int paramIdByMenuItemId(int itemId) const;
    char const** optionsByMenuItemId(int itemId) const;
    int optionsTotalByMenuItemId(int itemId) const;

  protected:
    void setEffect(BitshiftEffect* effect);
    void setAnalogMap(int inputMap[], int size);
    void setMenuItemMap(int inputMap[], int size, char const** inputOptions[] = NULL, int inputOptionsTotals[] = NULL);

    int intRange(float value, int min, int max);
    float floatRange(float value, float min, float max, bool inclusive = true);

    AudioEffectFade send;
    AudioConnection* patchSendToEffect;

    char const* thisName;
    char const** thisParamNames;
    int thisParamsTotal;
    int analogMapSize;
    int* analogMap;
    int menuItemMapSize;
    int* menuItemMap;
    char const*** menuItemOptions;
    int* menuItemOptionsTotal;

    static const int OPTIONS_BOOLEAN_TOTAL = 2;
    static char const* OPTIONS_BOOLEAN[OPTIONS_BOOLEAN_TOTAL];

  private:
    void clearAnalogMap();
    void clearMenuItemMap();

    BitshiftEffect* effect;
};

#endif
