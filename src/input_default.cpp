/*
 * input_default
 * Default set of input methods for bitshift, using AnalogMultiButton and ResponsiveAnalogRead
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
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
  buttonsTotal(buttonsTotal),
  buttons(buttonsPin, buttonsTotal, buttonsValues)
{
  for(int i = 0; i < analogTotal; i++)
  {
    ResponsiveAnalogRead* read = new ResponsiveAnalogRead(analogPins[i], true);
    read->setActivityThreshold(30.0);
    analogInputs[i] = read;
  }

  for(int i = 0; i < buttonsTotal; i++)
    this->buttonsAssign[i] = buttonsAssign[i];
}

void BitshiftInputDefault::update(unsigned long ms)
{
  // delay events a little so ADCs can settle down
  if(msFirst == 0)
    msFirst = ms;

  if(!events && ms - msFirst > 500)
    events = true;

  // each update, perform one read, cycling through each analog input each time
  analogInputToRead++;

  if(analogInputToRead > analogTotal)
    analogInputToRead = 0;

  // read buttons
  if(analogInputToRead == analogTotal)
  {
    buttons.update();
    if(events)
    {
      for(int i = 0; i < buttonsTotal; i++)
      {
        if(buttons.onPress(i))
          eventButton(buttonsAssign[i], BUTTONEVENT_PRESS);

        if(buttons.onRelease(i))
          eventButton(buttonsAssign[i], BUTTONEVENT_RELEASE);

        if(buttons.onPressAfter(i, 500, 500))
          eventButton(buttonsAssign[i], BUTTONEVENT_REPEAT);

        if(buttons.onReleaseBefore(i, 1000))
          eventButton(buttonsAssign[i], BUTTONEVENT_TAP);

        if(buttons.onPressAfter(i, 1000))
          eventButton(buttonsAssign[i], BUTTONEVENT_HOLD);
      }
    }
    return;
  }

  // read analog input
  analogInputs[analogInputToRead]->update();
  if(events && analogInputs[analogInputToRead]->hasChanged())
  {
    float value = (float)analogInputs[analogInputToRead]->getValue() / (float)BitshiftInputDefault::ANALOG_RESOLUTION;
    eventAnalog(analogInputToRead, value);
  }
}
