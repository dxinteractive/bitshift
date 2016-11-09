/*
 * preset_tremolo
 * Tremolo effect (modulations in volume)
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#include "preset_tremolo.h"

char const* BitshiftPresetTremolo::_name = "Tremolo";

char const* BitshiftPresetTremolo::name()
{
  return BitshiftPresetTremolo::_name;
}

void BitshiftPresetTremolo::param(int id, int value)
{

}

void BitshiftPresetTremolo::paramAnalog(int id, float value)
{

}

 /*

void BitshiftPresetTremolo::name(char* outName, int bufferSize)
{
  return
}*/
