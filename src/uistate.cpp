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

#include "uistate.h"
#include "ui.h"
#include "audio.h"
#include "display.h"

void BitshiftUIState::setUI(BitshiftUI* const ui)
{
  this->ui = ui;
  this->audio = ui->audio;
  this->display = ui->display;
}

void BitshiftUIState::update(unsigned long ms)
{
  if(timeout != 0 && timeout + 2000 < ms)
  {
    Serial.println("POP");
    Serial.println(timeout);
    Serial.println(ms);
    popState();
  }
}

void BitshiftUIState::pushState(BitshiftUIState* newState)
{
  ui->pushState(newState);
}

void BitshiftUIState::popState()
{
  ui->popState();
}

void BitshiftUIState::setTimeout()
{
  timeout = lastUpdateMS + 1; // how can we set this when this state doesn't know the time yet?
}
