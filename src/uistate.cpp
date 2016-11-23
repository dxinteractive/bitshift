/*
 * uistate
 * Base class for UI states, reads user input and can update audio and display differently depending on active state behaviour
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#include <Arduino.h>
#include "uistate.h"
#include "ui.h"
#include "audio.h"
#include "display.h"

void BitshiftUIState::init(BitshiftUI* const ui)
{
  this->ui = ui;
  this->audio = ui->audio;
  this->display = ui->display;
}


void BitshiftUIState::init(BitshiftUI* const ui, BitshiftUIState* const lowerState)
{
  init(ui);
  this->lowerState = lowerState;
}

void BitshiftUIState::update(unsigned long ms)
{
  if(timeout > 0 && timeout < ms)
    popState();
}

void BitshiftUIState::pushState(BitshiftUIState* newState)
{
  ui->pushState(newState);
}

void BitshiftUIState::popState(bool render)
{
  ui->popState(render);
}

int BitshiftUIState::visibleButtonsTotal()
{
  return ui->visibleButtonsTotal;
}

int BitshiftUIState::visibleAnalogsTotal()
{
  return ui->visibleAnalogsTotal;
}

void BitshiftUIState::passDownEventButton(int id, int value)
{
  if(lowerState)
    lowerState->eventButton(id, value);
}

void BitshiftUIState::passDownEventAnalog(int id, float value)
{
  if(lowerState)
    lowerState->eventAnalog(id, value);
}

bool BitshiftUIState::passDownEventInvisibleButton(int id, int value)
{
  if(lowerState && id >= ui->visibleButtonsTotal)
  {
    lowerState->eventButton(id, value);
    return true;
  }
  return false;
}

bool BitshiftUIState::passDownEventInvisibleAnalog(int id, float value)
{
  if(lowerState && id >= ui->visibleAnalogsTotal)
  {
    lowerState->eventAnalog(id, value);
    return true;
  }
  return false;
}

void BitshiftUIState::setTimeout(int duration)
{
  timeout = millis() + duration;
}
