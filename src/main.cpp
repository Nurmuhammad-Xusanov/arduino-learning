#include <Arduino.h>
#include <Servo.h>
int pin = 2;
int value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pin, INPUT);
}

void loop() {
  value = digitalRead(pin);
  if (value == HIGH) {
    Serial.println("On");
  } else {
    Serial.println("Off");
  }
  delay(1000);
}

