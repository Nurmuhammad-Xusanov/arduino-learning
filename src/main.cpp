#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
RTC_DS3231 rtc;

#define KENGLIK 128
#define BALANDLIK 64
#define MANZIL 0x3C
Adafruit_SSD1306 oled(KENGLIK,BALANDLIK, &Wire, -1);
void setup() {
    Serial.begin(9600);
    if(!rtc.begin()) {
        Serial.println("RTC modul topilmadi!");
        while(1);
    }

    if(rtc.lostPower()) {
        Serial.println("RTC batareykasi o'chgan");
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
    if(!oled.begin(SSD1306_SWITCHCAPVCC, MANZIL)) {
        Serial.println("OLED YOQ NIGER");
    }
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setCursor(0,0);
    oled.setTextColor(WHITE);
}

void loop() {
    DateTime now = rtc.now();

    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();


    oled.print(now.hour(), DEC);
    oled.print(":");
    oled.print(now.minute(), DEC);
    oled.print(":");
    oled.print(now.second(), DEC);
    oled.display();
    delay(1000);
    oled.setCursor(0, 0);
    oled.clearDisplay();
}