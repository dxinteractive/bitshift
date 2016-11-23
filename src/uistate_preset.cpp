/*
 * uistate_preset
 * UI state for displaying and altering preset parameters
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#include "uistate_preset.h"
#include "uistate_param.h"
#include "uistate_message.h"
#include "uistate.h"
#include "ui.h"
#include "display.h"
#include "props.h"
#include "audio.h"
#include "input_consts.h"

void BitshiftUIStatePreset::eventButton(int id, int value)
{
  switch(id)
  {
    case BUTTON_UP:
      if(value == BUTTONEVENT_PRESS || value == BUTTONEVENT_REPEAT)
      {
        audio->prevPreset();
        render();
      }
      return;

    case BUTTON_DOWN:
      if(value == BUTTONEVENT_PRESS || value == BUTTONEVENT_REPEAT)
      {
        audio->nextPreset();
        render();
      }
      return;

    case BUTTON_BACK:
      if(value == BUTTONEVENT_PRESS)
      {
        analogOffset();
      }
      return;

    case BUTTON_SELECT:
      //pushState(new BitshiftUIStatePreset());
      return;
  }
}

void BitshiftUIStatePreset::eventAnalog(int id, float value)
{
  if(id + analogParamOffset >= audio->analogParamsTotal())
  {
    render();
    return;
  }

  BitshiftUIStateParam* newState = new BitshiftUIStateParam(id + analogParamOffset, value);
  newState->setTimeout();
  pushState(newState);
}

void BitshiftUIStatePreset::render()
{
  BitshiftPropsPreset props;
  props.presetName = audio->presetName();
  for(int i = 0; i < visibleAnalogsTotal(); i++)
    props.analogParamNames[i] = audio->analogParamName(i + analogParamOffset);

  //props.poo = audio->getPresetParamAnalog(0);
  display->render(props);
}

void BitshiftUIStatePreset::analogOffset()
{
  int analogParamsTotal = audio->analogParamsTotal();
  if(analogParamsTotal <= visibleAnalogsTotal())
  {
    BitshiftUIStateMessage* newState = new BitshiftUIStateMessage("No more params available on this preset");
    newState->setTimeout(2500);
    pushState(newState);
    return;
  }

  analogParamOffset += visibleAnalogsTotal();
  if(analogParamOffset > analogParamsTotal)
    analogParamOffset = 0;

  render();
}
