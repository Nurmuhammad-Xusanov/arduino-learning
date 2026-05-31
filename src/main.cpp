#include <Arduino.h>
int option;
int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
    option = Serial.read();
    if(option == 'a') {
      digitalWrite(led, LOW);
    }
    if(option == 's') {
      digitalWrite(led, HIGH);
    }
  }
}

