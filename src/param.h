/*
 * param
 * Simple object container for effect parameters (ints, floats etc)
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#ifndef BITSHIFT_PARAM_H
#define BITSHIFT_PARAM_H

class BitshiftParam
{
  public:
    BitshiftParam(int intValue);
    BitshiftParam(float floatValue);

    void set(int intValue);
    void set(float floatValue);

  private:
    enum { IS_INT, IS_FLOAT, IS_CHAR } type;
    union {
      int intValue;
      float floatValue;
      char charValue;
    } value;
};

#endif
