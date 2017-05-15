/*
 * input
 * Base class for input providers
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "ui.h"

void BitshiftInput::eventButton(int id, int value) {
  if(ui)
    ui->eventButton(id, value);
}

void BitshiftInput::eventAnalog(int id, float value) {
  if(ui)
    ui->eventAnalog(id, value);
}
