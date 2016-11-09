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

void BitshiftUIState::pushState(BitshiftUIState* newState)
{
  if(ui)
    ui->pushState(newState);
}

void BitshiftUIState::popState()
{
  if(ui)
    ui->popState();
}
