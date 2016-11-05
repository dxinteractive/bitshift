#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  while(!Serial) delay(1000);
}


void loop() {
  Serial.println("");
  Serial.println("loop");

  Serial.print("Buttons: ");
  Serial.println(analogRead(A10)); // or A14

  Serial.print("A: ");
  Serial.println(analogRead(A2));

  Serial.print("B: ");
  Serial.println(analogRead(A3));

  Serial.print("C: ");
  Serial.println(analogRead(A6));

  Serial.print("D: ");
  Serial.println(analogRead(A7));

  Serial.print("EXP: ");
  Serial.println(analogRead(A11));
  
  delay(10);
}

