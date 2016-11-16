/*
 * preset
 * Base class for presets, complete effects that can be used one at a time
 * consisting of configurations of audio effects, audio routing and controllers
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#ifndef BITSHIFT_PRESET_H
#define BITSHIFT_PRESET_H

#include "param.h"

class BitshiftPreset
{
  public:
    BitshiftPreset() {}
    virtual ~BitshiftPreset();

    inline char const* name() const { return thisName; }
    char const* paramName(int paramId) const;
    char const* analogParamName(int analogId) const;
    char const* menuItemParamName(int itemId) const;

    inline const int paramsTotal() const { return thisParamsTotal; }
    inline const int analogParamsTotal() const { return analogMapSize; }
    inline const int menuItemParamsTotal() const { return menuItemMapSize; }

    virtual void setParam(int paramId, int value) {}
    virtual void setParam(int paramId, float value) {}
    virtual void setAnalogParam(int analogId, float value) {}
    virtual void setMenuItemParam(int itemId, int value) {}

    int paramIdByAnalogId(int analogId) const;
    int paramIdByMenuItemId(int itemId) const;

    void setAnalogMap(int inputMap[], int size);
    void setMenuItemMap(int inputMap[], int size);

    void clearAnalogMap();
    void clearMenuItemMap();

    void deletePresets(int totalPresets);

  protected:
    BitshiftParam** state;
    char const* thisName;
    char const** thisParamNames;
    int thisParamsTotal;
    int analogMapSize;
    int* analogMap;
    int menuItemMapSize;
    int* menuItemMap;
};

#endif
