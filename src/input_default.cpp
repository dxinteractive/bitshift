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

#include "input_default.h"
#include "input.h"
#include "AnalogMultiButton.h"
#include "ResponsiveAnalogRead.h"
#include "input_consts.h"

BitshiftInputDefault::BitshiftInputDefault(
  const int analogPins[],
  int analogTotal,
  int buttonsPin,
  int buttonsTotal,
  const int buttonsValues[],
  const int buttonsAssign[]
):
  BitshiftInput(),
  analogTotal(analogTotal),
  buttons(buttonsPin, buttonsTotal, buttonsValues)
{
  for(int i = 0; i < analogTotal; i++)
  {
    ResponsiveAnalogRead* read = new ResponsiveAnalogRead(analogPins[i], true);
    read->setActivityThreshold(10.0);
    analogInputs[i] = read;
  }

  for(int i = 0; i < buttonsTotal; i++)
    this->buttonsAssign[i] = buttonsAssign[i];
}

void BitshiftInputDefault::update()
{
  // each update, perform one read, cycling through each analog input each time
  analogInputToRead++;
  if(analogInputToRead > analogTotal)
    analogInputToRead = 0;

  // read buttons
  if(analogInputToRead == analogTotal)
  {
    buttons.update();
    if(buttons.onPress(buttonsAssign[BUTTON_UP]))
      event(BUTTON_UP, BUTTON_PRESS);

    if(buttons.onPress(buttonsAssign[BUTTON_DOWN]))
      event(BUTTON_DOWN, BUTTON_PRESS);

    if(buttons.onPress(buttonsAssign[BUTTON_BACK]))
      event(BUTTON_BACK, BUTTON_PRESS);

    if(buttons.onPress(buttonsAssign[BUTTON_SELECT]))
      event(BUTTON_SELECT, BUTTON_PRESS);

    if(buttons.onRelease(buttonsAssign[BUTTON_UP]))
      event(BUTTON_UP, BUTTON_RELEASE);

    if(buttons.onRelease(buttonsAssign[BUTTON_DOWN]))
      event(BUTTON_DOWN, BUTTON_RELEASE);

    if(buttons.onRelease(buttonsAssign[BUTTON_BACK]))
      event(BUTTON_BACK, BUTTON_RELEASE);

    if(buttons.onRelease(buttonsAssign[BUTTON_SELECT]))
      event(BUTTON_SELECT, BUTTON_RELEASE);

    if(buttons.onPressAfter(buttonsAssign[BUTTON_UP], 500, 500))
      event(BUTTON_UP, BUTTON_REPEAT);

    if(buttons.onPressAfter(buttonsAssign[BUTTON_DOWN], 500, 500))
      event(BUTTON_DOWN, BUTTON_REPEAT);

    if(buttons.onPressAfter(buttonsAssign[BUTTON_BACK], 500, 500))
      event(BUTTON_BACK, BUTTON_REPEAT);

    if(buttons.onPressAfter(buttonsAssign[BUTTON_SELECT], 500, 500))
      event(BUTTON_SELECT, BUTTON_REPEAT);

    return;
  }

  // read analog input
  analogInputs[analogInputToRead]->update();
  if(analogInputs[analogInputToRead]->hasChanged())
  {
    float value = (float)analogInputs[analogInputToRead]->getValue() / (float)BitshiftInputDefault::ANALOG_RESOLUTION;
    eventAnalog(analogInputToRead, value);
  }
}
