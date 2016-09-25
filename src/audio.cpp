/*
 * audio
 * Class responsible for all audio management
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-. 
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : : 
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_; 
 */

#include "audio.h"
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

BitshiftAudio::BitshiftAudio():
  inToOut(audioIn, 0, audioOut, 0)
{
}

BitshiftAudio::~BitshiftAudio()
{
}

void BitshiftAudio::setup()
{
  AudioMemory(12);
  audioAdaptor.enable();
  audioAdaptor.inputSelect(AUDIO_INPUT_LINEIN);
  audioAdaptor.lineInLevel(5);
  audioAdaptor.lineOutLevel(18);
  audioAdaptor.adcHighPassFilterDisable();
}

void BitshiftAudio::loop()
{
}