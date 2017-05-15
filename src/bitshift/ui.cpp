/*
 * ui
 * Base class for managing a UI (mainly updating audio objects and display in response to input)
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "ui.h"

#include <Arduino.h>
#include "StackArray.h"

BitshiftUI::BitshiftUI(
  BitshiftAudio& audio,
  BitshiftInput& input,
  BitshiftDisplay& display
):
  audio(&audio),
  input(&input),
  display(&display)
{
  this->input->init(this);
}
