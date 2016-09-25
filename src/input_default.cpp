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
#include "ui.h"

BitshiftInputDefault::BitshiftInputDefault(
  int analogTotal,
  const int analogPins[],
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
    analogInputs[i] = new ResponsiveAnalogRead(analogPins[i], true);

  for(int i = 0; i < buttonsTotal; i++)
    this->buttonsAssign[buttonsAssign[i]] = i;
}

void BitshiftInputDefault::update()
{
  buttons.update();

  /*
  for(int i = 0; i < analogTotal; i++)
  {
      analogInputs[i]->update();
  }
  */

  if(buttons.onPress(0)) // up
    ui->event(0);

  if(buttons.onPress(1)) // down
    ui->event(1);

  if(buttons.onPress(2)) // back
    ui->event(2);

  if(buttons.onPress(3)) // select
    ui->event(3);

  
}