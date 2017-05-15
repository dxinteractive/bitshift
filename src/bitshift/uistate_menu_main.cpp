/*
 * uistate_menu_main
 * UI state for displaying a temporary message
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "uistate_menu_main.h"
#include "uistate_menu.h"
#include "uistate_usage.h"
#include "uistate_inputs.h"
#include "uistate_menu_param.h"
#include "uistate_menu_expassign.h"
#include "audio.h"
#include <Arduino.h>

// see uistate_menu_main.h for ITEMS_TOTAL
char const* BitshiftUIStateMenuMain::ITEM_LABELS[] = {
  "CPU Usage",
  "Debug inputs"
};

BitshiftUIStateMenuMain::~BitshiftUIStateMenuMain()
{
  if(allItemLabels)
    delete [] allItemLabels;

  if(analogExpLabels)
  {
    for(int i = 0; i < analogExpTotal; i++)
      delete [] analogExpLabels[i];

    delete [] analogExpLabels;
  }
}

void BitshiftUIStateMenuMain::init()
{
  menuItemParamsTotal = audio->menuItemParamsTotal();
  allItemsTotal = menuItemParamsTotal + analogExpTotal + BitshiftUIStateMenuMain::ITEMS_TOTAL;
  analogExpLabels = new char*[analogExpTotal];
  allItemLabels = new char const*[allItemsTotal];

  int index = 0;
  for(int i = 0; i < menuItemParamsTotal; i++)
    allItemLabels[index++] = audio->menuItemParamName(i);

  for(int i = 0; i < analogExpTotal; i++)
  {
    // int optionIndex = audio->expAssignment(i);
    // char const* selectionLabel = optionIndex == -1
    //    ? BitshiftUIStateMenuExpAssign::NONE
    //    : audio->analogParamName(optionIndex);

    analogExpLabels[i] = new char[20];
    sprintf(analogExpLabels[i], "Exp %d", i); // (%s) , selectionLabel
    allItemLabels[index++] = analogExpLabels[i];
  }

  for(int i = 0; i < BitshiftUIStateMenuMain::ITEMS_TOTAL; i++)
    allItemLabels[index++] = BitshiftUIStateMenuMain::ITEM_LABELS[i];

  setItems(allItemLabels, allItemsTotal);
}

void BitshiftUIStateMenuMain::onSelect(int cursor)
{
  if(cursor < menuItemParamsTotal)
  {
    int initialValue = audio->menuItemParamValueInt(cursor);
    pushState(new BitshiftUIStateMenuParam(cursor, initialValue, allItemLabels[cursor]));
    return;
  }
  cursor -= menuItemParamsTotal;

  if(cursor < analogExpTotal)
  {
    int initialValue = audio->expAssignment(cursor) + 1;
    pushState(new BitshiftUIStateMenuExpAssign(cursor, initialValue, analogExpLabels[cursor]));
    return;
  }
  cursor -= analogExpTotal;

  switch(cursor)
  {
    case 0:
      pushState(new BitshiftUIStateUsage());
      return;

    case 1:
      pushState(new BitshiftUIStateInputs());
      return;
  }
}
