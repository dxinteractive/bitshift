/*
 * props
 * Base class for props objects, which are basic data containers to give to rendering methods
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#ifndef BITSHIFT_PROPS_H
#define BITSHIFT_PROPS_H

class BitshiftProps
{
  public:
    BitshiftProps() {}
    virtual ~BitshiftProps() {}
};

class BitshiftPropsParam: public BitshiftProps
{
  public:
    char const* paramName;
};

class BitshiftPropsPreset: public BitshiftProps
{
  public:
    char const* presetName;
    char const* analogParamNames[4];
};

#endif
