/*
 * menuitem
 * Simple container for data for menu items
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#ifndef BITSHIFT_MENUITEM_H
#define BITSHIFT_MENUITEM_H

class BitshiftMenuItem
{
  public:
    BitshiftMenuItem(
      char const* label,
      bool canEnter = false,
      bool checked = false,
      bool focus = false
    ):
      label(label),
      canEnter(canEnter),
      checked(checked),
      focus(focus) {}

    char const* label;
    bool canEnter;
    bool checked;
    bool focus;
};

#endif
