/*
 * uistate_menu_param
 * UI state for displaying a menu where a param can be adjusted
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_UISTATE_MENU_PARAM_H
#define BITSHIFT_UISTATE_MENU_PARAM_H

#include "uistate_menu.h"

class BitshiftUIStateMenuParam: public BitshiftUIStateMenu
{
  public:
    BitshiftUIStateMenuParam(int itemId, int initialValue, char const* paramName)
      :BitshiftUIStateMenu(initialValue, paramName),
      itemId(itemId) {}
    ~BitshiftUIStateMenuParam() {}

  protected:
    virtual void init();
    virtual void onMove(int cursor);

  private:
    int itemId;
    char const** menuItemParamOptions;
    int menuItemParamOptionsTotal;
};

#endif
