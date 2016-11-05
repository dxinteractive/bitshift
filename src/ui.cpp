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
#include "uistate_preset.h"

BitshiftUI::BitshiftUI(
  BitshiftAudio& audio,
  BitshiftInput& input,
  BitshiftDisplay& display
):
  audio(&audio),
  input(&input),
  display(&display)
{
  this->input->setUI(this);
  //pushState(initialState);
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

void BitshiftUI::pushState(BitshiftUIState* newState)
{
  newState->setUI(this);

  if(stateStack.isEmpty())
  {
    //newState->setup(this, pControl);
    stateStack.push(newState);
    return;
  }

  BitshiftUIState* topState = stateStack.peek();
  if(newState != topState)
  {
    //newState->setup(this, pControl, topState);
    stateStack.push(newState);
  }
}

void BitshiftUI::popState()
{
  if(stateStack.count() == 1) return;

  BitshiftUIState* topState = stateStack.peek();
  stateStack.pop();
  delete topState;
}

void BitshiftUI::update()
{
  input->update();

  /*BitshiftUIState* topState = stateStack.peek();
  if(topState != NULL)
  {
    topState->update();
  }*/
}

void BitshiftUI::event(int id)
{
  BitshiftUIState* topState = stateStack.peek();
  if(topState != NULL)
  {
    topState->onEvent(id);
  }
}

void BitshiftUI::setValue(int id, int value)
{
  /*BitshiftUIState* topState = stateStack.peek();
  if(topState != NULL)
  {
    topState->trigger(id);
  }*/
}
