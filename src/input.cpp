/*
 * input
 * Base class for input providers
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

void BitshiftInput::event(int id, int value) {
  if(ui)
    ui->onEvent(id, value);
}

void BitshiftInput::eventAnalog(int id, float value) {
  if(ui)
    ui->onEventAnalog(id, value);
}
