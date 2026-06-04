#include <Arduino.h>

// Interrupt ichida o'zgaruvchi o'zgaruvchilarga VOLATILE qo'shamiz
volatile byte led = 5;
volatile unsigned long lastRun = 0;

bool state = false;
unsigned long oldTime = 0;
const long interval = 1000;

void color_swap() {
    // Tugma shovqinini (Bouncing) dasturiy filtrlaymiz
    if(millis() - lastRun > 200) { // 50ms juda kam, tugma siqilganda 200ms yaxshi ishlaydi
        
        digitalWrite(led, LOW); // Yangisiga o'tishdan oldin, hozirgi yonib turgan pinni o'chiramiz!
        
        led++;
        if(led == 8) led = 5; // 5, 6, 7 pinlar aylanadi
        
        lastRun = millis();
    }
}

void setup() {
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    
    // 2-pinni ham INPUT (yoki sizda pull-up bo'lsa INPUT_PULLUP) qilish kerak
    pinMode(2, INPUT_PULLUP); 
    
    attachInterrupt(digitalPinToInterrupt(2), color_swap, FALLING); // INPUT_PULLUP bo'lsa FALLING yaxshi
}

void loop() {
    unsigned long newTime = millis();

    if(newTime - oldTime >= interval) {
        oldTime = newTime;
        state = !state;
        digitalWrite(led, state); // Faqat hozirgi tanlangan pin yonib-ochadi
    }
}