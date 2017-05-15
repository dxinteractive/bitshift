/*
 * visualizationdata
 * Data container class for storing data that can be rendered as a visualization
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#ifndef BITSHIFT_VISUALIZATIONDATA_H
#define BITSHIFT_VISUALIZATIONDATA_H

class BitshiftVisualizationData
{
  public:
    int const* data;
    int dataTotal;
    int type;
    float phase;
    float min;
    float max; // todo - param props can have a second visualizationdata for adjustments
    // synth_waveform can be copied and altered specifically for lfo
};

#endif
