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

#ifndef BITSHIFT_ROUTER_H
#define BITSHIFT_ROUTER_H

#include <Audio.h>
#include "preset.h"

class BitshiftRouter
{
  public:
    BitshiftRouter(
      AudioStream& audioIn,
      int audioInChannel,
      BitshiftPreset** presets,
      int presetsTotal,
      AudioStream& audioOut,
      int audioOutChannel
    );
    ~BitshiftRouter();

    void setActivePreset(int presetId) { activePresetId = presetId; }

  private:
    BitshiftPreset** presets;
    int presetsTotal;
    int activePresetId;

    AudioConnection** patchInputToPresets;

    // for testing
    AudioConnection inToOut;
};

#endif
