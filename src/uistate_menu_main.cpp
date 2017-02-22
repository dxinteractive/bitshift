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
#include "audio.h"
#include <Arduino.h>

char const* BitshiftUIStateMenuMain::ITEM_LABELS[] = {
  "CPU Usage",
  "Debug inputs"
};

BitshiftUIStateMenuMain::~BitshiftUIStateMenuMain()
{
  if(allItemLabels)
    delete [] allItemLabels;
}

void BitshiftUIStateMenuMain::init()
{
  menuItemParamsTotal = audio->menuItemParamsTotal();
  allItemsTotal = menuItemParamsTotal + BitshiftUIStateMenuMain::ITEMS_TOTAL;

  allItemLabels = new char const*[allItemsTotal];
  for(int i = 0; i < menuItemParamsTotal; i++)
    allItemLabels[i] = audio->menuItemParamName(i);

  for(int i = 0; i < BitshiftUIStateMenuMain::ITEMS_TOTAL; i++)
    allItemLabels[i + menuItemParamsTotal] = BitshiftUIStateMenuMain::ITEM_LABELS[i];

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

  switch(cursor - menuItemParamsTotal)
  {
    case 0:
      pushState(new BitshiftUIStateUsage());
      return;

    case 1:
      pushState(new BitshiftUIStateInputs());
      return;
  }
}
