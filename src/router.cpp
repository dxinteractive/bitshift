/*
 * router
 * Creates a network of virtual patch cables to route audio between inputs, outputs and presets
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#include "router.h"
#include <Audio.h>
#include "preset.h"

BitshiftRouter::BitshiftRouter(
  AudioStream& audioIn,
  int audioInChannel,
  BitshiftPreset** presets,
  int presetsTotal,
  AudioStream& audioOut,
  int audioOutChannel
):
  presets(presets),
  presetsTotal(presetsTotal),
  inToOut(audioIn, audioInChannel, audioOut, audioOutChannel)
{
  patchInputToPresets = new AudioConnection*[presetsTotal];
  for(int i = 0; i < presetsTotal; i++)
  {
    patchInputToPresets[i] = new AudioConnection(
      audioIn,
      audioInChannel,
      *(presets[i]->audioIn()),
      presets[i]->audioInChannel()
    );
  }
}

BitshiftRouter::~BitshiftRouter()
{
  for(int i = 0; i < presetsTotal; i++)
  {
    delete patchInputToPresets[i];
  }
  delete[] patchInputToPresets;
}
