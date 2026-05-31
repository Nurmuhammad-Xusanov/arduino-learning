#include <Arduino.h>
#include <Servo.h>
Servo myServo;
int potPin = A0;
int servoPin = 2;
int led = 3;
void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);  
  pinMode(led, OUTPUT);
}

void loop() {
  int natija = analogRead(potPin);
  Serial.println(natija);
  int burchak = map(natija, 0, 1023, 0, 180);
  int yoruglik = map(natija, 0, 1023, 0, 255);
  analogWrite(led, yoruglik);
  myServo.write(burchak);
  delay(50);
}

