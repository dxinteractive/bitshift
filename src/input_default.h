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

        BitshiftInputDefault(
        	int analogTotal,
        	const int analogPins[],
        	int buttonsPin,
        	int buttonsTotal,
        	const int buttonsValues[],
        	const int buttonsAssign[]
        );
		~BitshiftInputDefault() {}

		virtual void update();
		
	private:
		int analogTotal;
		AnalogMultiButton buttons;
		int buttonsAssign[AnalogMultiButton::MAX_BUTTONS];
		ResponsiveAnalogRead* analogInputs[BitshiftInputDefault::MAX_ANALOG];
};

#endif
