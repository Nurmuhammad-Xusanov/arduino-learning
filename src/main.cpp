#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define KENGLIK 128
#define BALANDLIK 64
#define MANZIL  0x3C

int buttons[] = {2,3,4,5};
byte size = sizeof(buttons) / sizeof(buttons[0]);
byte option;

Adafruit_SSD1306 oled(KENGLIK, BALANDLIK, &Wire, -1);

void setup() {
  Serial.begin(9600);
  for(byte i = 2; i <= size; i++) {
    pinMode(i, INPUT_PULLUP);
  }

  if(oled.begin(SSD1306_SWITCHCAPVCC, MANZIL)) {
    oled.clearDisplay(); //ekranni tozalash
    oled.setTextSize(1); // 1-3
    oled.setTextColor(WHITE); // rang
  }
}

void loop() {
  if(digitalRead(2) == LOW) {
    Serial.println("Bosildi pin2");
    delay(200);
  }
  if(digitalRead(3) == LOW) {
    Serial.println("Bosildi pin3");
    delay(200);
  }
  if(digitalRead(4) == LOW) {
    Serial.println("Bosildi pin4");
    delay(200);
  }
  if(digitalRead(5) == LOW) {
    oled.clearDisplay();
    delay(200);
  }
}