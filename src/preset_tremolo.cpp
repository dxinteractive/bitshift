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

const int BitshiftPresetTremolo::_totalParams = 5;
char const* BitshiftPresetTremolo::_name = "Tremolo";
char const* BitshiftPresetTremolo::_paramNames[] = {
  "Speed",
  "Depth",
  "Shape",
  "Division",
  "Volume"
};

const int BitshiftPresetTremolo::totalParams()
{
  return BitshiftPresetTremolo::_totalParams;
}

char const* BitshiftPresetTremolo::name()
{
  return ":D";
}

char const** BitshiftPresetTremolo::paramNames()
{
  return BitshiftPresetTremolo::_paramNames;
}

int BitshiftPresetTremolo::getParam(int id)
{
  return 3;
}

float BitshiftPresetTremolo::getParamAnalog(int id)
{
  return 0.3;
}


void BitshiftPresetTremolo::setParam(int id, int value)
{

}

void BitshiftPresetTremolo::setParamAnalog(int id, float value)
{
  temp = value;
}

 /*

void BitshiftPresetTremolo::name(char* outName, int bufferSize)
{
  return
}*/
