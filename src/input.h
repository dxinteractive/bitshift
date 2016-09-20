/*
 * input
 * Base class for input providers
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-. 
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : : 
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_; 
 */

#ifndef BITSHIFT_INPUT_H
#define BITSHIFT_INPUT_H

class BitshiftInput
{
  public:
    BitshiftInput() {}
    virtual ~BitshiftInput() {}

    virtual void update() = 0;
    
  private:
};

#endif
