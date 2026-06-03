#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define KENGLIK 128
#define BALANDLIK 64
#define MANZIL  0x3C

Adafruit_SSD1306 oled(KENGLIK, BALANDLIK, &Wire, -1);

void setup() {
  Serial.begin(9600);
  if(!oled.begin(SSD1306_SWITCHCAPVCC, MANZIL)) {
    Serial.println("OLED TOPILMADI!");
    while(true);
  }

  oled.clearDisplay(); //ekranni tozalash
  oled.setTextSize(1); // 1-3
  oled.setTextColor(WHITE); // rang
  oled.setCursor(0, 0); // (x, y)
  oled.println("Hello world!");
  oled.display(); 
}

void loop() {

}