/*
 * uistate_preset
 * UI state for displaying and altering preset parameters
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#include "uistate_preset.h"
#include "uistate.h"
#include "display.h"
#include <Arduino.h>
#include "input_consts.h"

void BitshiftUIStatePreset::onEvent(int id, int value)
{
  switch(id)
  {
    case 0:
      pushState(new BitshiftUIStatePreset(a + 1));
      return;

    case 1:
      popState();
      return;

    case 2:
      paramOffset += 4;
      // render
      return;

    case 3:

      return;
  }
}

void BitshiftUIStatePreset::onEvent(int id, float value)
{
}

void BitshiftUIStatePreset::render()
{
  display->renderPreset(a);
}
