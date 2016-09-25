/*
 * ui_default
 * Default set of UI states for input handling and updating audio objects and display
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-. 
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : : 
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_; 
 */

#include "ui_default.h"
#include "uistate.h"
#include "uistate_preset.h"

BitshiftUIState* BitshiftUIDefault::createState(int id)
{
  switch(id)
  {
    case 0:
      return new BitshiftUIStatePreset();
  }
  return NULL;
}