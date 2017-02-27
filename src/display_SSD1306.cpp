/*
 * display_SSD1306
 * Rendering specifics for Adafruit SSD1306 128x64 OLED screen
 * Copyright (c) 2016 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/bitshift
 *
 * █▄   ▀ ▄█▄    █▄   ▀ ▄▀ ▄█▄
 * █▄▀ ▀█  ▀▄ ▄▀ █ █ ▀█ █▀  ▀▄
 *
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
  screen.fillRect(18, 24, 4, 2, WHITE);
  screen.display();
}

void BitshiftDisplaySSD1306::render(BitshiftPropsInputDebug &props)
{
  screen.clearDisplay();
  screen.setCursor(0,0);
  screen.setTextSize(1);
  screen.println("Debug inputs");
  screen.println("");
  screen.print("Button pressed: ");

  if(props.buttonId != -1)
  {
    screen.println(props.buttonId);
  } else {
    screen.println("-");
  }

  for(int i = 0; i < 10; i++)
  {
    if(props.analogValues[i] != -1.0)
    {
      screen.print("Analog ");
      screen.print(i);
      screen.print(": ");
      screen.println(props.analogValues[i], 4);
    }
  }

  screen.display();
}


void BitshiftDisplaySSD1306::render(BitshiftPropsMenu &props)
{
  screen.clearDisplay();
  screen.setCursor(0,0);
  screen.setTextSize(1);
  if(props.heading)
  {
    screen.print("  ");
    screen.print(props.heading);
  }

  int start = 0;
  if(props.cursor > 2)
    start = props.cursor - 2;

  int end = props.itemsTotal;
  if(start + 5 < end)
    end = start + 5;

  int line = 0;
  for(int i = start; i < props.itemsTotal; i++)
  {
    if(props.cursor == i)
    {
      int y = 24 + 10 * line;
      screen.drawPixel(3, y, WHITE);
      screen.drawPixel(6, y, WHITE);
      screen.drawPixel(123, y, WHITE);
      screen.drawPixel(120, y, WHITE);
      if(props.selection)
      {
        screen.drawLine(107, y, 109, y + 2, WHITE);
        screen.drawLine(109, y + 2, 114, y - 3, WHITE);
      }
    }
    screen.setCursor(12, 20 + 10 * line);
    screen.print(props.itemLabels[i]);
    line++;

  }
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
  if(props.analogParamNamesTotal > 0)
  {
    screen.setCursor(0,0);
    screen.print("A:");
    screen.print(props.analogParamNames[0]);
  }

  if(props.analogParamNamesTotal > 2)
  {
    screen.setCursor(63,0);
    screen.print("C:");
    screen.print(props.analogParamNames[2]);
  }

  if(props.analogParamNamesTotal > 1)
  {
    screen.setCursor(0,9);
    screen.print("B:");
    screen.print(props.analogParamNames[1]);
  }

  if(props.analogParamNamesTotal > 3)
  {
    screen.setCursor(63,9);
    screen.print("D:");
    screen.print(props.analogParamNames[3]);
  }

  screen.setCursor(64 - strlen(props.presetName) * 6, 26);
  screen.setTextSize(2);
  screen.println(props.presetName);

  if(props.moreParams)
  {
    screen.drawPixel(127, 0, WHITE);
    screen.drawPixel(127, 2, WHITE);
    screen.drawPixel(127, 4, WHITE);
  }

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

void BitshiftDisplaySSD1306::render(BitshiftPropsSplash &props)
{
  int frame = props.frame;
  int squaresTotal = 41;
  if(frame > squaresTotal)
    frame = squaresTotal;

  int squares[] = {
    // b
    0,0,4,4,
    0,4,4,4,
    0,7,4,5,
    0,11,4,3,
    4,4,4,4,
    4,11,4,3,
    7,7,4,5,
    // i
    13,5,4,4,
    16,0,4,4,
    16,5,4,4,
    16,9,4,5,
    // t
    22,3,4,4,
    26,0,4,4,
    26,3,4,4,
    26,7,4,4,
    30,3,4,4,
    30,10,4,4,
    // s
    36,8,6,6,
    41,3,6,6,
    // h
    49,0,4,4,
    49,4,4,4,
    49,7,4,4,
    49,10,4,4,
    53,4,4,4,
    56,7,4,4,
    56,10,4,4,
    // i
    62,5,4,4,
    65,0,4,4,
    65,5,4,4,
    65,9,4,5,
    // f
    71,3,4,4,
    71,7,4,4,
    71,11,4,5,
    74,0,4,4,
    74,5,4,4,
    // t
    80,3,4,4,
    84,0,4,4,
    84,3,4,4,
    84,7,4,4,
    88,3,4,4,
    88,10,4,4
  };

  screen.clearDisplay();
  for(int i = 0; i < frame; i++)
  {
    screen.fillRect(
      squares[i * 4] + 18,
      squares[i * 4 + 1] + 24,
      squares[i * 4 + 2],
      squares[i * 4 + 3],
      WHITE
    );
  }
  screen.display();
}


void BitshiftDisplaySSD1306::render(BitshiftPropsUsage &props)
{
  screen.clearDisplay();
  screen.setCursor(0,0);
  screen.setTextSize(1);
  screen.println("CPU & Memory Usage");
  screen.println("");
  screen.print("CPU:        ");
  screen.println(props.processorUsage);
  screen.print("CPU max:    ");
  screen.println(props.processorUsageMax);
  screen.print("Memory:     ");
  screen.println(props.memoryUsage);
  screen.print("Memory max: ");
  screen.println(props.memoryUsageMax);
  screen.print("Time (ms):  ");
  screen.println(props.ms);
  screen.display();
}
