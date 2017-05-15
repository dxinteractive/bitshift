/*
 * router
 * Creates a network of virtual patch cables to route audio between inputs, outputs and presets
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
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
  patchMixerToOutput(mixer, 0, audioOut, audioOutChannel)
{
  patchInputToPresets = new AudioConnection*[presetsTotal];
  patchPresetsToMixer = new AudioConnection*[presetsTotal];
  for(int i = 0; i < presetsTotal; i++)
  {
    patchInputToPresets[i] = new AudioConnection(
      audioIn,
      audioInChannel,
      *(presets[i]->audioIn()),
      presets[i]->audioInChannel()
    );

    patchPresetsToMixer[i] = new AudioConnection(
      *(presets[i]->audioOut()),
      presets[i]->audioOutChannel(),
      mixer,
      i
    );
  }
}

BitshiftRouter::~BitshiftRouter()
{
  for(int i = 0; i < presetsTotal; i++)
  {
    delete patchInputToPresets[i];
    delete patchPresetsToMixer[i];
  }
  delete[] patchInputToPresets;
  delete[] patchPresetsToMixer;
}

void BitshiftRouter::setActivePreset(int presetId)
{
  if(activePresetId != -1)
    presets[activePresetId]->audioDisable();

  activePresetId = presetId;
  presets[activePresetId]->audioEnable();
}
