/*
 * uistate_menu_param
 * UI state for displaying a temporary message
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "uistate_menu_param.h"
#include "uistate_menu.h"
#include "audio.h"

void BitshiftUIStateMenuParam::init()
{
  menuItemParamOptions = audio->menuItemParamOptions(itemId);
  menuItemParamOptionsTotal = audio->menuItemParamOptionsTotal(itemId);
  setItems(menuItemParamOptions, menuItemParamOptionsTotal, true);
}

void BitshiftUIStateMenuParam::onBack(int cursor)
{
  audio->setMenuItemParam(itemId, cursor);
}
