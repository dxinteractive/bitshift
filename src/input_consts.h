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

const int ANALOGTYPES_BITSHIFT = 6; // 2 ^ ANALOGTYPES_BITSHIFT items can belong to each ANALOG_<TYPE>
const int ANALOGTYPES_TOTAL = 2;

const int ANALOG_VISIBLE = 0 << ANALOGTYPES_BITSHIFT;
const int ANALOG_EXP = 1 << ANALOGTYPES_BITSHIFT;

const int BUTTONTYPES_BITSHIFT = 6; // 2 ^ BUTTONTYPES_BITSHIFT items can belong to each BUTTON_<TYPE>
const int BUTTONTYPES_TOTAL = 2;

const int BUTTON_VISIBLE = 0 << BUTTONTYPES_BITSHIFT;
const int BUTTON_TAP = 1 << BUTTONTYPES_BITSHIFT;
// named buttons for ease of use in project file...
const int BUTTON_UP = BUTTON_VISIBLE;
const int BUTTON_DOWN = BUTTON_VISIBLE + 1;
const int BUTTON_BACK = BUTTON_VISIBLE + 2;
const int BUTTON_SELECT = BUTTON_VISIBLE + 3;

const int BUTTONEVENT_PRESS = 0;
const int BUTTONEVENT_RELEASE = 1;
const int BUTTONEVENT_REPEAT = 2;
const int BUTTONEVENT_TAP = 3;
const int BUTTONEVENT_HOLD = 4;

#endif
