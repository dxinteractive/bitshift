/*
 * uistate_menu
 * UI state for displaying a menu with selectable options
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_UISTATE_MENU_H
#define BITSHIFT_UISTATE_MENU_H

#include "uistate.h"

class BitshiftUIStateMenu: public BitshiftUIState
{
  public:
    BitshiftUIStateMenu();
    virtual ~BitshiftUIStateMenu() {}

    virtual void render();
    virtual void eventButton(int id, int value);
    virtual void eventAnalog(int id, float value);

    void setItems(char const** itemLabels, int itemsTotal);
    virtual void onSelect(int cursor) {}

  private:
    char const** itemLabels;
    int itemsTotal = 0;
    int cursor = 0;
};

#endif
