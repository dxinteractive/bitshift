/*
 * uistate_param
 * UI state for providing visual feedback while altering preset parameters
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
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

  //audio->setAnalogParam(id + analogParamOffset, value);
  //render();
  setTimeout();
}

void BitshiftUIStateParam::render()
{
  char paramValueString[30];
  BitshiftPropsParam props;
  props.paramName = audio->analogParamName(analogId);
  audio->analogParamValueString(paramValueString, analogId);
  Serial.println(paramValueString);
  props.paramValueString = paramValueString;
  display->render(props);
}
