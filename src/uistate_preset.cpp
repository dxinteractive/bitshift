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
#include "audio.h"
#include "input_consts.h"

void BitshiftUIStatePreset::onEvent(int id, int value)
{
  if(!audio) return;

  if(value == BUTTON_PRESS || value == BUTTON_REPEAT)
  {
    switch(id)
    {
      case BUTTON_UP:
        //pushState(new BitshiftUIStatePreset(a + 1));
        return;

      case BUTTON_DOWN:
        //popState();
        return;

      case BUTTON_BACK:
        //paramOffset += 4;
        return;

      case BUTTON_SELECT:
        return;
    }
  }
}

void BitshiftUIStatePreset::onEventAnalog(int id, float value)
{
  if(!audio) return;
  audio->setPresetParamAnalog(id + paramOffset, value);

  render();
}

void BitshiftUIStatePreset::render()
{
  if(!display || !audio) return;
  display->renderPreset(audio->presetName(), audio->getPresetParamAnalog(0));
}
