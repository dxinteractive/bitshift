/*
 * effect_lfo
 * General purpose low frequency oscillator
 * Copyright (c) 201y Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
 */

#include "effect_lfo.h"
#include "effect.h"
#include <Audio.h>
#include <Arduino.h>
#include "visualizationdata.h"

static const uint8_t SINE = 0;
static const uint8_t SAW = 1;
static const uint8_t TRIANGLE = 2;
static const uint8_t REVSAW = 3;
static const uint8_t SQUARE = 4;

static const int16_t WAVETABLE_VALUE_MAX = 32766;
static const int16_t WAVETABLE_VALUE_MIN = -32767;

char const* BitshiftEffectLfo::OPTIONS_SHAPE[] = {
  "Sine",
  "Saw",
  "Triangle",
  "Revsaw",
  "Square"
};

BitshiftEffectLfo::BitshiftEffectLfo():
  BitshiftEffect(),
  patchLfoToSignalMixer(lfo, 0, signalMixer, 0),
  patchOffsetToSignalMixer(offset, 0, signalMixer, 1)
{
  //waveformVis.data = waveformVisData;
  //waveformVis.dataTotal = 256;
  //waveformVis.type = 0; // TODO - should be a visualizaiton const representing a LINE
}

void BitshiftEffectLfo::setup()
{
  // default values
  shape(SINE);
  lfo.begin(1.0, 1.0, WAVEFORM_ARBITRARY);
  offset.amplitude(1.0);
}

float BitshiftEffectLfo::speed(float hz)
{
  lfo.frequency(hz);
  _hz = hz;
  return hz;
}

float BitshiftEffectLfo::phase(float angle)
{
  lfo.phase(angle);
  _angle = angle;
  return angle;
}

int BitshiftEffectLfo::shape(int shape)
{
  shape = clamp(shape, 0, OPTIONS_SHAPE_TOTAL);
  _shape = shape;
  updateWaveform();
  return shape;
}

float BitshiftEffectLfo::mod(float mod)
{
  mod = clamp(mod, 0.0, 1.0);
  _mod = mod;
  updateWaveform();
  return mod;
}

float BitshiftEffectLfo::shapeAndMod(float value)
{
  value = clamp(value, 0.0, (float)OPTIONS_SHAPE_TOTAL);
  _shape = value;
  _mod = clamp(1.2 * (value - _shape) - 0.1, 0.0, 1.0);
  updateWaveform();
  return value;
}

//BitshiftEffectLfo::int division(int division)
//{
//
//}

float BitshiftEffectLfo::min(float min)
{
  _min = clamp(min, -1.0, 1.0);
  updateMinMax();
  return _min;
}

float BitshiftEffectLfo::max(float max)
{
  _max = clamp(max, -1.0, 1.0);
  updateMinMax();
  return _max;
}

void BitshiftEffectLfo::updateWaveform()
{
  BitshiftEffect::audioNoInterrupts();
  switch(_shape)
  {
    case SINE:
      for(int i = 0; i < 256; i++)
      {
        // scale this according to mod, but will need an int lerp
        wavetable[i] = AudioWaveformSine[i];
      }
      break;

    case SAW:
    {
      int32_t val = WAVETABLE_VALUE_MAX;
      uint8_t intMod = int(_mod * 255);
      int32_t slope = -65536 / (intMod + 1);

      for(int i = 0; i < 256; i++)
      {
        wavetable[i] = val;
        val += slope;
        if(val < WAVETABLE_VALUE_MIN)
          val = WAVETABLE_VALUE_MIN;
      }
      break;
    }

    case TRIANGLE:
    {
      int32_t val = WAVETABLE_VALUE_MIN;
      uint8_t intMod = int(_mod * 255);
      int32_t slope = 65536 / (intMod + 1);
      int32_t slopeDown = 65536 / (256 - intMod);

      for(int i = 0; i < 256; i++)
      {
        val += slope;
        if(val > WAVETABLE_VALUE_MAX)
        {
          val = WAVETABLE_VALUE_MAX;
          slope = -slopeDown;
        }

        wavetable[i] = clamp(val, WAVETABLE_VALUE_MIN, WAVETABLE_VALUE_MAX);
      }
      break;
    }

    case REVSAW:
    {
      int32_t val = WAVETABLE_VALUE_MAX;
      uint8_t intMod = int(_mod * 255);
      int32_t slope = -65536 / (256 - intMod);

      for(int i = 255; i >= 0; i--)
      {
        val += slope;
        if(val < WAVETABLE_VALUE_MIN)
          val = WAVETABLE_VALUE_MIN;

        wavetable[i] = val;
      }
      break;
    }

    case SQUARE:
    {
      uint8_t pulseWidth = _mod * 255;
      int16_t val = WAVETABLE_VALUE_MAX;
      for(int i = 0; i < 256; i++)
      {
        wavetable[i] = val;
        if(i == pulseWidth)
          val = WAVETABLE_VALUE_MIN;
      }
      break;
    }
  }

  lfo.arbitraryWaveform(wavetable, 0.0);

  // update waveform visualization data
  //for(int i = 0; i < 256; i++)
  //  waveformVisData[i] = wavetable[i];

  BitshiftEffect::audioInterrupts();
}

void BitshiftEffectLfo::updateMinMax()
{
  BitshiftEffect::audioNoInterrupts();
  lfo.amplitude((_max - _min) * 0.5);
  offset.amplitude(_max * 0.5 + _min * 0.5);
  BitshiftEffect::audioInterrupts();
}
