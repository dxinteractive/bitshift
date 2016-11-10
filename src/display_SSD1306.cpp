/*
 * display_SSD1306
 * Rendering specifics for Adafruit SSD1306 128x64 OLED screen
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * .-.    _  .-.      .-.    _  .--. .-.
 * : :   :_;.' `.     : :   :_;: .-'.' `.
 * : `-. .-.`. .'.--. : `-. .-.: `; `. .'
 * ' .; :: : : :`._-.': .. :: :: :   : :
 * `.__.':_; :_;`.__.':_;:_;:_;:_;   :_;
 */

#include "display.h"
#include "display_SSD1306.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

BitshiftDisplaySSD1306::BitshiftDisplaySSD1306(
 int pin_sid,
 int pin_sclk,
 int pin_dc,
 int pin_rst,
 int pin_cs
):
  BitshiftDisplay(),
  screen(pin_sid, pin_sclk, pin_dc, pin_rst, pin_cs)
{
  screen.begin(SSD1306_SWITCHCAPVCC);
  screen.clearDisplay();
  screen.setTextSize(6);
  screen.println(":)");
  screen.setTextColor(WHITE);
  screen.display();
}

void BitshiftDisplaySSD1306::renderPreset(char const* presetName, float poo)
{
  screen.clearDisplay();
  screen.setTextSize(1);
  screen.setCursor(0,0);
  screen.println("Yay! ");
  screen.println(presetName);
  screen.println(poo);
  screen.display();
}
