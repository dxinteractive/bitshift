/*
 * uistate_message
 * UI state for displaying a temporary message
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "uistate_message.h"
#include "uistate.h"
#include "display.h"
#include "props.h"
#include "input_consts.h"

void BitshiftUIStateMessage::eventButton(int id, int value)
{
  passDownEventInvisibleButton(id, value);
}

void BitshiftUIStateMessage::eventAnalog(int id, float value)
{
  passDownEventInvisibleAnalog(id, value);
}

void BitshiftUIStateMessage::render()
{
  BitshiftPropsMessage props;
  props.message = message;
  display->render(props);
}
