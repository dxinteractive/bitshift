/*
 * uistate_menu_main
 * UI state for displaying the main menu
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_UISTATE_MENU_MAIN_H
#define BITSHIFT_UISTATE_MENU_MAIN_H

#include "uistate_menu.h"

class BitshiftUIStateMenuMain: public BitshiftUIStateMenu
{
  public:
    BitshiftUIStateMenuMain()
      :BitshiftUIStateMenu() {}
    ~BitshiftUIStateMenuMain();

  protected:
    virtual void init();
    virtual void onSelect(int cursor);

  private:
    int menuItemParamsTotal = 0;
    int allItemsTotal = 0;
    char const** allItemLabels;

    static const int ITEMS_TOTAL = 1;
    static char const* ITEM_LABELS[ITEMS_TOTAL];
};

#endif
