/*
 * uistate
 * Base class for UI states, reads user input and can update audio and display differently depending on active state behaviour
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include <Arduino.h>
#include "uistate.h"
#include "ui_default.h"
#include "audio.h"
#include "display.h"

void BitshiftUIState::init(BitshiftUIDefault* const ui)
{
  this->ui = ui;
  this->audio = ui->audio;
  this->display = ui->display;
  init();
}


void BitshiftUIState::init(BitshiftUIDefault* const ui, BitshiftUIState* const lowerState)
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

void BitshiftUIState::setTimeout(int duration)
{
  timeout = millis() + duration;
}
