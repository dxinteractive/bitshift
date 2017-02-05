/*
 * A simple hardware test which receives audio from the audio shield
 * Line-In pins and send it to the Line-Out pins and headphone jack.
 *
 * This example code is in the public domain.
 */

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=95.19999694824219,439.20001220703125
AudioInputI2S            i2s1;           //xy=101.19999694824219,358.1999969482422
AudioEffectMultiply      multiply1;      //xy=366.1999969482422,431.1999969482422
AudioOutputI2S           i2s2;           //xy=612.2000122070312,326.20001220703125
AudioConnection          patchCord1(sine1, 0, multiply1, 1);
AudioConnection          patchCord2(i2s1, 0, multiply1, 0);
AudioConnection          patchCord3(multiply1, 0, i2s2, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=877.1999969482422,50.19999694824219
// GUItool: end automatically generated code

AudioControlSGTL5000 audioAdaptor;

void setup() {
  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(12);

  sine1.frequency(3.0);
  sine1.amplitude(1.0);

  // Enable the audio shield, select input, and enable output
  audioAdaptor.enable();
  audioAdaptor.inputSelect(AUDIO_INPUT_LINEIN);
  audioAdaptor.micGain(0);
  audioAdaptor.lineInLevel(12);
  audioAdaptor.lineOutLevel(31);
  audioAdaptor.dacVolume(0.9);
  audioAdaptor.muteHeadphone();
  audioAdaptor.adcHighPassFilterDisable();
}

void loop() {
}


