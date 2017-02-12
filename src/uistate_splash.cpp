/*
 * uistate_splash
 * UI state for displaying the splash screen when the bitshift first turns on
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "uistate_splash.h"
#include "uistate.h"
#include "display.h"
#include "props.h"
#include "input_consts.h"

void BitshiftUIStateSplash::update(unsigned long ms)
{
  if(ms > 2000)
  {
    popState(false);
    pushState(nextState);
    return;
  }

  if(msFirst == 0)
    msFirst = ms;

  this->ms = ms - msFirst;
  render();
}

void BitshiftUIStateSplash::render()
{
  BitshiftPropsSplash props;
  props.frame = ms >> 4;
  display->render(props);
}
