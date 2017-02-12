/*
 * ui_default
 * Default set of UI states for input handling and updating audio objects and display
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "ui.h"
#include "ui_default.h"
#include "uistate_preset.h"

BitshiftUIDefault::BitshiftUIDefault(
  BitshiftAudio& audio,
  BitshiftInput& input,
  BitshiftDisplay& display,
  BitshiftUIState* initialState,
  int analogVisible,
  int buttonsVisible
):
  BitshiftUI(
    audio,
    input,
    display,
    analogVisible,
    buttonsVisible
  )
{
  this->initialState(initialState);
}
