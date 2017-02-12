/*
 * props
 * Base class for props objects, which are basic data containers to give to rendering methods
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_PROPS_H
#define BITSHIFT_PROPS_H

class BitshiftProps
{
  public:
    BitshiftProps() {}
    virtual ~BitshiftProps() {}
};

class BitshiftPropsMenu: public BitshiftProps
{
  public:
    int itemsTotal;
    int cursor;
    char const* heading;
    char const* itemLabels[20]; // todo dont hardcode this
};

class BitshiftPropsMessage: public BitshiftProps
{
  public:
    char const* message;
};

class BitshiftPropsParam: public BitshiftProps
{
  public:
    char const* paramName;
    char const* paramValueString;
};

class BitshiftPropsPreset: public BitshiftProps
{
  public:
    char const* presetName;
    char const* analogParamNames[10]; // todo dont hardcode this
};

class BitshiftPropsSplash: public BitshiftProps {
  public:
    int frame;
};

class BitshiftPropsUsage: public BitshiftProps
{
  public:
    int processorUsage;
    int processorUsageMax;
    int memoryUsage;
    int memoryUsageMax;
    unsigned long ms;
};


#endif
