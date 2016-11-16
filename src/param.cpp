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

#include "param.h"

BitshiftParam::BitshiftParam(int intValue)
{
  set(intValue);
}

BitshiftParam::BitshiftParam(float floatValue)
{
  set(floatValue);
}

void BitshiftParam::set(int intValue)
{
  value.intValue = intValue;
  type = IS_INT;
}

void BitshiftParam::set(float floatValue)
{
  value.floatValue = floatValue;
  type = IS_FLOAT;
}

