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

// forward declare ui
class BitshiftUI;

class BitshiftInput
{
  public:
    BitshiftInput() {}
    virtual ~BitshiftInput() {}

    inline void init(BitshiftUI* const ui) { this->ui = ui; }
    void eventButton(int id, int value);
    void eventAnalog(int id, float value);
    virtual void update() = 0;

  protected:
    BitshiftUI *ui;
};

#endif
