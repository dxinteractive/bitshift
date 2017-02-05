/*
 * ui
 * Base class for managing a stack of UI states, handling input, and updating audio objects and display in response to input
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#include "ui.h"

#include <Arduino.h>
#include "StackArray.h"

BitshiftUI::BitshiftUI(
  BitshiftAudio& audio,
  BitshiftInput& input,
  BitshiftDisplay& display,
  int visibleButtonsTotal,
  int visibleAnalogsTotal
):
  audio(&audio),
  input(&input),
  display(&display),
  visibleButtonsTotal(visibleButtonsTotal),
  visibleAnalogsTotal(visibleAnalogsTotal)
{
  this->input->init(this);
}

BitshiftUI::~BitshiftUI()
{
  BitshiftUIState* topState;
  while(!stateStack.isEmpty())
  {
    topState = stateStack.peek();
    stateStack.pop();
    delete topState;
  }
}

void BitshiftUI::update(unsigned long ms)
{
  input->update();

  BitshiftUIState* topState = stateStack.peek();
  if(topState)
    topState->update(ms);
}

void BitshiftUI::render()
{
  if(stateStack.isEmpty())
    return;

  BitshiftUIState* topState = stateStack.peek();
  topState->render();
}

void BitshiftUI::initialState(BitshiftUIState* initialState)
{
  stateStack.push(initialState);
  initialState->init(this);
}

void BitshiftUI::pushState(BitshiftUIState* newState)
{
  BitshiftUIState* topState = stateStack.peek();
  if(newState != topState)
  {
    stateStack.push(newState);
    newState->init(this, topState);
    newState->render();
  }
}

void BitshiftUI::popState(bool render)
{
  if(stateStack.count() == 1)
    return;

  BitshiftUIState* topState = stateStack.peek();
  stateStack.pop();
  delete topState;

  if(render)
    stateStack.peek()->render();
}

void BitshiftUI::eventButton(int id, int value)
{
  BitshiftUIState* topState = stateStack.peek();
  if(topState)
    topState->eventButton(id, value);
}

void BitshiftUI::eventAnalog(int id, float value)
{
  BitshiftUIState* topState = stateStack.peek();
  if(topState)
    topState->eventAnalog(id, value);
}
