/*
 * input_default
 * Default set of input methods for bitshift, using AnalogMultiButton and ResponsiveAnalogRead
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */


#ifndef BITSHIFT_INPUT_DEFAULT_H
#define BITSHIFT_INPUT_DEFAULT_H

#include "input.h"
#include "AnalogMultiButton.h"
#include "ResponsiveAnalogRead.h"

class BitshiftInputDefault: public BitshiftInput
{
  public:
    static const int MAX_ANALOG = 10;
    static const int ANALOG_RESOLUTION = 1023;

    BitshiftInputDefault(
      const int analogPins[],
      int analogTotal,
      int buttonsPin,
      int buttonsTotal,
      const int buttonsValues[],
      const int buttonsAssign[]
    );
    ~BitshiftInputDefault() {}

    virtual void update();

  private:
    int analogTotal;
    int buttonsTotal;
    AnalogMultiButton buttons;
    ResponsiveAnalogRead* analogInputs[BitshiftInputDefault::MAX_ANALOG];
    int analogInputToRead;
    int buttonsAssign[AnalogMultiButton::MAX_BUTTONS];
};

#endif
