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

#ifndef BITSHIFT_AUDIO_H
#define BITSHIFT_AUDIO_H

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

class BitshiftAudio
{
  public:
    BitshiftAudio();
    ~BitshiftAudio();
    
    void setup();
    void loop();
    
  private:
    AudioInputI2S audioIn;
    AudioOutputI2S audioOut;
    AudioConnection inToOut;
    AudioControlSGTL5000 audioAdaptor;
};

#endif
