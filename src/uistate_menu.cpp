/*
 * uistate_menu
 * UI state for displaying a temporary message
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "uistate_menu.h"
#include "uistate.h"
#include "display.h"
#include "props.h"
#include "input_consts.h"

BitshiftUIStateMenu::BitshiftUIStateMenu():
  BitshiftUIState()
{
}

void BitshiftUIStateMenu::eventButton(int id, int value)
{
  switch(id)
  {
    case BUTTON_UP:
      if(value == BUTTONEVENT_PRESS || value == BUTTONEVENT_REPEAT)
      {
        cursor--;
        if(cursor < 0)
          cursor = itemsTotal - 1;

        render();
      }
      return;

    case BUTTON_DOWN:
      if(value == BUTTONEVENT_PRESS || value == BUTTONEVENT_REPEAT)
      {
        cursor++;
        if(cursor >= itemsTotal)
          cursor = 0;

        render();
      }
      return;

    case BUTTON_BACK:
      if(value == BUTTONEVENT_PRESS)
      {
        popState();
      }
      return;

    case BUTTON_SELECT:
      if(value == BUTTONEVENT_PRESS)
      {
        onSelect(cursor);
      }
      return;
  }

  passDownEventInvisibleButton(id, value);
}

void BitshiftUIStateMenu::eventAnalog(int id, float value)
{
  passDownEventInvisibleAnalog(id, value);
}

void BitshiftUIStateMenu::render()
{
  BitshiftPropsMenu props;
  props.itemsTotal = itemsTotal;
  props.cursor = cursor;

  if(itemLabels)
  {
    for(int i = 0; i < itemsTotal; i++)
      props.itemLabels[i] = itemLabels[i];
  }

  display->render(props);
}

void BitshiftUIStateMenu::setItems(char const** itemLabels, int itemsTotal)
{
  this->itemLabels = itemLabels;
  this->itemsTotal = itemsTotal;
}
