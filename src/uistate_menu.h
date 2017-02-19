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
    BitshiftUIStateMenu(int initialValue, char const* heading);
    virtual ~BitshiftUIStateMenu() {}

    virtual void render();
    virtual void eventButton(int id, int value);
    virtual void eventAnalog(int id, float value);

    void setItems(char const** itemLabels, int itemsTotal, bool selection = false);
    virtual void onSelect(int cursor) {}
    virtual void onBack(int cursor) {}

  private:
    char const** itemLabels;
    char const* heading;
    int itemsTotal = 0;
    int cursor = 0;
    bool selection = false;
};

#endif
