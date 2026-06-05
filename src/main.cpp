#include <Arduino.h>


void setup() {
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}

void loop() {
    int ldr = analogRead(A0);
    Serial.println(ldr);
    if (ldr > 350) {
        digitalWrite(13, HIGH);
    } else {
        digitalWrite(13, LOW);
    }
    delay(100);
}