/*
 * uistate_preset
 * UI state for displaying and altering preset parameters
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "uistate_preset.h"
#include "uistate_param.h"
#include "uistate_message.h"
#include "uistate_menu_main.h"
#include "uistate.h"
#include "ui.h"
#include "display.h"
#include "props.h"
#include "audio.h"
#include "input_consts.h"

#include <Arduino.h>

BitshiftUIStatePreset::BitshiftUIStatePreset(
  const int* analogsAssign,
  int analogsTotal
):
  BitshiftUIState(),
  analogsAssign(analogsAssign),
  analogsTotal(analogsTotal)
{
  for(int i = 0; i < ANALOG_TYPES_TOTAL; i++)
    analogTotalsByType[i] = 0;

  for(int i = 0; i < analogsTotal; i++)
  {
    int assign = analogsAssign[i] >> ANALOG_TYPES_BITSHIFT;
    if(assign >= 0 && assign < ANALOG_TYPES_TOTAL)
      analogTotalsByType[assign]++;
  }
}

void BitshiftUIStatePreset::eventButton(int id, int value)
{
  switch(id)
  {
    case BUTTON_UP:
      if(value == BUTTONEVENT_PRESS || value == BUTTONEVENT_REPEAT)
      {
        audio->prevPreset();
        analogParamOffset = 0;
        render();
      }
      return;

    case BUTTON_DOWN:
      if(value == BUTTONEVENT_PRESS || value == BUTTONEVENT_REPEAT)
      {
        audio->nextPreset();
        analogParamOffset = 0;
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
      {
        pushState(new BitshiftUIStateMenuMain(analogTotalsByType[ANALOG_EXP >> ANALOG_TYPES_BITSHIFT]));
        return;
      }
  }
}

void BitshiftUIStatePreset::eventAnalog(int id, float value)
{
  if(analogsAssign[id] >> ANALOG_TYPES_BITSHIFT == ANALOG_EXP >> ANALOG_TYPES_BITSHIFT)
  {
    audio->setExpParam(analogsAssign[id] - (1 << ANALOG_TYPES_BITSHIFT), value);
    return;
  }

  if(id + analogParamOffset >= audio->analogParamsTotal())
  {
    render();
    return;
  }

  BitshiftUIStateParam* newState = new BitshiftUIStateParam(id, analogParamOffset, value);
  newState->setTimeout();
  pushState(newState);
}

void BitshiftUIStatePreset::render()
{
  int analogParamNamesTotal = 4; //analogTotalsByType[ANALOG_VISIBLE];
  int paramsTotal = audio->analogParamsTotal();
  int visibleParams = paramsTotal - analogParamOffset;
  if(analogParamNamesTotal > visibleParams)
    analogParamNamesTotal = visibleParams;

  const char* analogParamNames[analogParamNamesTotal];

  int j = 0;
  for(int i = 0; i < analogsTotal; i++)
  {
    if(analogsAssign[i] >> ANALOG_TYPES_BITSHIFT == ANALOG_VISIBLE)
      analogParamNames[j++] = audio->analogParamName(i + analogParamOffset);
  }

  BitshiftPropsPreset props;
  props.presetName = audio->presetName();
  props.analogParamNames = analogParamNames;
  props.analogParamNamesTotal = analogParamNamesTotal;
  props.moreParams = paramsTotal > analogParamNamesTotal;
  display->render(props);
}

void BitshiftUIStatePreset::analogOffset()
{
  int analogParamsTotal = audio->analogParamsTotal();
  if(analogParamsTotal <= analogTotalsByType[ANALOG_VISIBLE])
  {
    BitshiftUIStateMessage* newState = new BitshiftUIStateMessage("No more params");
    newState->setTimeout(1000);
    pushState(newState);
    return;
  }

  analogParamOffset += analogTotalsByType[ANALOG_VISIBLE];
  if(analogParamOffset > analogParamsTotal)
    analogParamOffset = 0;

  render();
}
