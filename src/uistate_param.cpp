/*
 * uistate_param
 * UI state for providing visual feedback while altering preset parameters
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "uistate_param.h"
#include "uistate.h"
#include "ui.h"
#include "display.h"
#include "props.h"
#include "audio.h"
#include "input_consts.h"

void BitshiftUIStateParam::eventButton(int id, int value)
{
  if((id == BUTTON_UP || id == BUTTON_DOWN || id == BUTTON_BACK) && value == BUTTONEVENT_PRESS) {
    popState();
    return;
  }
  passDownEventInvisibleButton(id, value);
}

void BitshiftUIStateParam::eventAnalog(int id, float value)
{
  if(id != analogId)
  {
    popState(false);
    passDownEventAnalog(id, value);
    return;
  }

  audio->setAnalogParam(analogId + analogParamOffset, value);
  render();
  setTimeout();
}

void BitshiftUIStateParam::render()
{
  BitshiftPropsParam props;
  // get param name from audio and pass it to props
  props.paramName = audio->analogParamName(analogId + analogParamOffset);

  // get param value (as a string) from audio and pass it to props
  char paramValueString[30];
  audio->analogParamValueString(paramValueString, analogId + analogParamOffset);
  props.paramValueString = paramValueString;

  // render
  display->render(props);
}
