/*
 * input_consts
 * Enums and consts for inputs
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_INPUT_CONSTS_H
#define BITSHIFT_INPUT_CONSTS_H

const int ANALOG_TYPES_BITSHIFT = 6; // 2 ^ ANALOG_TYPES_BITSHIFT items can belong to each ANALOG_<TYPE>
const int ANALOG_TYPES_TOTAL = 2;
const int ANALOG_VISIBLE = 0 << ANALOG_TYPES_BITSHIFT;
const int ANALOG_EXP = 1 << ANALOG_TYPES_BITSHIFT;

const int BUTTON_UP = 0;
const int BUTTON_DOWN = 1;
const int BUTTON_BACK = 2;
const int BUTTON_SELECT = 3;
const int BUTTON_TAP1 = 4;
const int BUTTON_TAP2 = 5;
const int BUTTON_TAP3 = 6;
const int BUTTON_TAP4 = 7;
const int BUTTON_TAP5 = 8;

const int BUTTONEVENT_PRESS = 0;
const int BUTTONEVENT_RELEASE = 1;
const int BUTTONEVENT_REPEAT = 2;

#endif
