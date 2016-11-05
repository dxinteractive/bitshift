#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int PIN_SCREEN_SID = 4;
const int PIN_SCREEN_SCLK = 3;
const int PIN_SCREEN_DC = 2;
const int PIN_SCREEN_RST = 1;
const int PIN_SCREEN_CS = 0;

Adafruit_SSD1306 screen(PIN_SCREEN_SID, PIN_SCREEN_SCLK, PIN_SCREEN_DC, PIN_SCREEN_RST, PIN_SCREEN_CS);

// timing
unsigned long t = 0;

void setup() {
  screen.begin(SSD1306_SWITCHCAPVCC);
  screen.clearDisplay();
  screen.setTextSize(1);
  screen.setTextColor(WHITE);
  screen.println("A.Mix     C.Feedback");
  screen.println("B.Depth   D.Chunch  ");
  
  screen.setCursor(15,22);
  screen.setTextSize(2);
  screen.println("Bitshift");
  
  screen.display();
}


void loop() {
  delay(10);
}

