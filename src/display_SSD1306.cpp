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
#include "props.h"
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
  screen.setTextColor(WHITE);
  screen.println("...");
  screen.display();
}

void BitshiftDisplaySSD1306::render(BitshiftPropsMessage &props)
{
  screen.clearDisplay();
  screen.setCursor(0,0);
  screen.setTextSize(1);
  screen.println(props.message);
  screen.display();
}

void BitshiftDisplaySSD1306::render(BitshiftPropsPreset &props)
{
  screen.clearDisplay();
  screen.setTextSize(1);
  if(props.analogParamNames[0][0])
  {
    screen.setCursor(0,0);
    screen.print("A:");
    screen.print(props.analogParamNames[0]);
  }
  if(props.analogParamNames[2][0])
  {
    screen.setCursor(60,0);
    screen.print("C:");
    screen.print(props.analogParamNames[2]);
  }
  if(props.analogParamNames[1][0])
  {
    screen.setCursor(0,9);
    screen.print("B:");
    screen.print(props.analogParamNames[1]);
  }
  if(props.analogParamNames[3][0])
  {
    screen.setCursor(60,9);
    screen.print("D:");
    screen.print(props.analogParamNames[3]);
  }

  screen.setCursor(64 - strlen(props.presetName) * 6, 26);
  screen.setTextSize(2);
  screen.println(props.presetName);
  screen.display();
}

void BitshiftDisplaySSD1306::render(BitshiftPropsParam &props)
{
  screen.clearDisplay();
  screen.setCursor(0,0);
  screen.setTextSize(2);
  screen.println(props.paramName);
  screen.println(props.paramValueString);
  screen.display();
}
