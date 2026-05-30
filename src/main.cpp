#include <Arduino.h>
#include <Servo.h>
int buttons[] = {2,3,4};
int size = sizeof(buttons) / sizeof(buttons[0]);
Servo myServo;

void setup() {
  for(int i = 0; i < size; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
  myServo.attach(12);
}

void loop() {
  while(digitalRead(2) == LOW) {
    myServo.write(0); // left
  }
  while(digitalRead(3) == LOW) {
    myServo.write(90); // bottom
  }
  while(digitalRead(4) == LOW) {
    myServo.write(180);// right
  }
  myServo.write(90);
}

