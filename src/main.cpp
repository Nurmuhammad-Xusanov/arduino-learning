#include <Arduino.h>

void setup() {
  pinMode(13, OUTPUT);
}

void blink(int times) {
  for(int i = 0; i < times; i++) {
    digitalWrite(13, HIGH);
    delay(200);
    digitalWrite(13, LOW);
    delay(200);
  }
}

void loop() {
  blink(5);
  delay(2000);
  blink(5);
}

