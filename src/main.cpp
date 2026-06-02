#include <Arduino.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  int data1 = analogRead(A0);
  int data2 = analogRead(A1);
  int data3 = analogRead(A2);
  Serial.print(data1);
  Serial.print("\t");
  Serial.print(data2);
  Serial.print("\t");
  Serial.println(data3);
  delay(10);
}