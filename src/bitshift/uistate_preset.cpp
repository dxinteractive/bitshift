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
  for(int i = 0; i < ANALOGTYPES_TOTAL; i++)
    analogTotalsByType[i] = 0;

  for(int i = 0; i < analogsTotal; i++)
  {
    int assign = analogsAssign[i] >> ANALOGTYPES_BITSHIFT;
    if(assign >= 0 && assign < ANALOGTYPES_TOTAL)
      analogTotalsByType[assign]++;
  }
}

void BitshiftUIStatePreset::eventButton(int id, int value)
{
  int buttonType = id >> BUTTONTYPES_BITSHIFT;

  // try this as a BUTTON_VISIBLE...
  if(buttonType == BUTTON_VISIBLE >> BUTTONTYPES_BITSHIFT)
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
          pushState(new BitshiftUIStateMenuMain(analogTotalsByType[ANALOG_EXP >> ANALOGTYPES_BITSHIFT]));
          return;
        }
    }
    return;
  }

  // ...or else try this as a BUTTON_TAP
  if(buttonType == BUTTON_TAP >> BUTTONTYPES_BITSHIFT)
  {
    audio->eventTap(id - BUTTON_TAP, value);
    return;
  }
}

void BitshiftUIStatePreset::eventAnalog(int id, float value)
{
  if(analogsAssign[id] >> ANALOGTYPES_BITSHIFT == ANALOG_EXP >> ANALOGTYPES_BITSHIFT)
  {
    audio->setExpParam(analogsAssign[id] - (1 << ANALOGTYPES_BITSHIFT), value);
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
    if(analogsAssign[i] >> ANALOGTYPES_BITSHIFT == ANALOG_VISIBLE)
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
