/*
 * bitshift
 * Main import for Deeep Bitshift digital guitar pedal UI library
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-. 
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : : 
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_; 
 */

#include "bitshift.h"
#include "audio.h"
#include "ui.h"

Bitshift::Bitshift()
{
}

Bitshift::~Bitshift()
{
}

void Bitshift::setup()
{
	audio.setup();
}

void Bitshift::update()
{
	ui.update();
}