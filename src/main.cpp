#include <Arduino.h>

void setup() {
  pinMode(13, OUTPUT);
}
void blinkThreeTimes() {
  for(int i = 0; i < 3; i++) {
    digitalWrite(13, HIGH);
    delay(200);
    digitalWrite(13, LOW);
    delay(200);
  }
}
void loop() {
  blinkThreeTimes();
  delay(2000);
  blinkThreeTimes();
}

