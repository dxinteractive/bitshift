/*
 * uistate_menu_param
 * UI state for displaying a temporary message
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "uistate_menu_expassign.h"
#include "uistate_menu.h"
#include "audio.h"

char const* BitshiftUIStateMenuExpAssign::NONE = "None";

BitshiftUIStateMenuExpAssign::~BitshiftUIStateMenuExpAssign()
{
  if(expOptions)
    delete [] expOptions;
}

void BitshiftUIStateMenuExpAssign::init()
{
  int analogParamsTotal = audio->analogParamsTotal();
  expOptions = new char const*[analogParamsTotal + 1];
  expOptions[0] = NONE;

  for(int i = 0; i < analogParamsTotal; i++)
    expOptions[i + 1] = audio->analogParamName(i);

  setItems(expOptions, analogParamsTotal + 1, true);
}

void BitshiftUIStateMenuExpAssign::onMove(int cursor)
{
  audio->setExpAssignment(expId, cursor - 1);
}
