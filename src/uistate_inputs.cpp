/*
 * uistate_inputs
 * UI state for displaying readings from inputs for analysis / debugging
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "uistate_inputs.h"
#include "uistate.h"
#include "display.h"
#include "props.h"
#include "input_consts.h"
#include <Audio.h>

BitshiftUIStateInputs::BitshiftUIStateInputs():
  BitshiftUIState()
{
  for(int i = 0; i < 10; i++)
    analogValues[i] = -1.0;
}

void BitshiftUIStateInputs::eventButton(int id, int value)
{
  if(value == BUTTONEVENT_PRESS)
    buttonId = id;

  if(value == BUTTONEVENT_RELEASE)
    buttonId = -1;

  render();

  if(id == BUTTON_BACK && value == BUTTONEVENT_RELEASE) {
    popState();
    return;
  }
}

void BitshiftUIStateInputs::eventAnalog(int id, float value)
{
  analogValues[id] = value;
  render();
}

void BitshiftUIStateInputs::render()
{
  BitshiftPropsInputDebug props;
  props.buttonId = buttonId;
  props.analogValues = analogValues;
  display->render(props);
}
