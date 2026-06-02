#include <Arduino.h>

void setup() { 
  Serial.begin(9600);
}

void loop() {
  float angle = millis() / 1000.0;
  float value = sin(angle) * 100;
  Serial.println(value);
  delay(10);
}