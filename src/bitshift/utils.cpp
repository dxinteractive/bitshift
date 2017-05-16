/*
 * bitshift
 * General utilities
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include <Arduino.h>

void floatToString(float number, int precision, const char* format, char* str)
{
  char str_temp[8];
  dtostrf(number, 0, precision, str_temp);
  sprintf(str, format, str_temp);
}
