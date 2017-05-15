/*
 * paramset
 * Simple base type for effect parameters
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_PARAMSET_H
#define BITSHIFT_PARAMSET_H

const int EXPASSIGN_MAX = 3;
const int TAPASSIGN_MAX = 6;

class BitshiftParamset
{
  public:
    BitshiftParamset() {
      for(int i = 0; i < EXPASSIGN_MAX; i++)
        expAssignment[i] = -1;

      for(int i = 0; i < TAPASSIGN_MAX; i++)
        tapAssignment[i] = -1;
    }
    ~BitshiftParamset() {}

    int expAssignment[EXPASSIGN_MAX];
    int tapAssignment[TAPASSIGN_MAX];
};

#endif
