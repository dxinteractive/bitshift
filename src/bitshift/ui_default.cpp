/*
 * ui_default
 * Default UI comprised of a stack of UI states
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
  BitshiftUIState* initialState
):
  BitshiftUI(
    audio,
    input,
    display
  )
{
  this->initialState(initialState);
}

BitshiftUIDefault::~BitshiftUIDefault()
{
  BitshiftUIState* topState;
  while(!stateStack.isEmpty())
  {
    topState = stateStack.peek();
    stateStack.pop();
    delete topState;
  }
}

void BitshiftUIDefault::update(unsigned long ms)
{
  input->update(ms);

  BitshiftUIState* topState = stateStack.peek();
  if(topState)
    topState->updateTimeout(ms);
    topState->update(ms);
}

void BitshiftUIDefault::render()
{
  if(stateStack.isEmpty())
    return;

  BitshiftUIState* topState = stateStack.peek();
  topState->render();
}

void BitshiftUIDefault::initialState(BitshiftUIState* initialState)
{
  stateStack.push(initialState);
  initialState->init(this);
}

void BitshiftUIDefault::pushState(BitshiftUIState* newState)
{
  BitshiftUIState* topState = stateStack.peek();
  if(newState != topState)
  {
    stateStack.push(newState);
    newState->init(this, topState);
    newState->render();
  }
}

void BitshiftUIDefault::popState(bool render)
{
  if(stateStack.count() == 1)
    return;

  BitshiftUIState* topState = stateStack.peek();
  stateStack.pop();
  delete topState;

  if(render)
    stateStack.peek()->render();
}

void BitshiftUIDefault::eventButton(int id, int value)
{
  BitshiftUIState* topState = stateStack.peek();
  if(topState)
    topState->eventButton(id, value);
}

void BitshiftUIDefault::eventAnalog(int id, float value)
{
  BitshiftUIState* topState = stateStack.peek();
  if(topState)
    topState->eventAnalog(id, value);
}
