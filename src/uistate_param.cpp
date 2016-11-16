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

BitshiftUIStateParam::BitshiftUIStateParam(int analogId, float value):
  BitshiftUIState(),
  analogId(analogId)
{

}

void BitshiftUIStateParam::event(int id, int value)
{

}

void BitshiftUIStateParam::eventAnalog(int id, float value)
{
  //audio->setAnalogParam(id + analogParamOffset, value);
  //render();
  //setTimeout();
}

void BitshiftUIStateParam::render()
{
  BitshiftPropsParam props;
  props.paramName = audio->analogParamName(analogId);
  display->render(props);
}
