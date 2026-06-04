#include <Arduino.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 1
#define CS_PIN 10

MD_Parola matrix(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  matrix.begin();
  matrix.setIntensity(5);
  matrix.displayClear();
  matrix.setTextAlignment(PA_CENTER);
  matrix.print("Hi!");
}

void loop() {}