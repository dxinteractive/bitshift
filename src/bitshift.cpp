/*
 * bitshift
 * Main import for Deeep Bitshift digital guitar pedal UI library
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "bitshift.h"

void Bitshift::setup()
{
  if(audio)
    audio->setup();

  if(ui)
    ui->render();
}

void Bitshift::update(unsigned long ms)
{
  if(ui)
    ui->update(ms);
}
