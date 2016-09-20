/*
 * display
 * Base class for displays, which are often screens but can be any kind of user feedback control
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-. 
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : : 
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_; 
 */

#ifndef BITSHIFT_DISPLAY_H
#define BITSHIFT_DISPLAY_H

class BitshiftDisplay
{
  public:
    BitshiftDisplay();
    virtual ~BitshiftDisplay();

    virtual void render() = 0;
    
  private:
};

#endif
