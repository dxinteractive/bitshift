/*
 * uistate_expassign
 * UI state for a menu for assigning expression inputs to control params
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_UISTATE_MENU_EXPASSIGN_H
#define BITSHIFT_UISTATE_MENU_EXPASSIGN_H

#include "uistate_menu.h"

class BitshiftUIStateMenuExpAssign: public BitshiftUIStateMenu
{
  public:
    static char const* NONE;

    BitshiftUIStateMenuExpAssign(int expId, int initialValue, char const* paramName)
      :BitshiftUIStateMenu(initialValue, paramName),
      expId(expId) {}
    ~BitshiftUIStateMenuExpAssign();

  protected:
    virtual void init();
    virtual void onMove(int cursor);

  private:
    int expId;
    char const** expOptions;
};

#endif
