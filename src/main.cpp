#include <Arduino.h>

volatile byte led = 5;
volatile bool state = false;
volatile unsigned long lastRun = 0;

unsigned long oldTime = 0;
const long interval = 1000;

void color_swap() {
    if(millis() - lastRun > 50) {
        digitalWrite(led, LOW);
        led++;
        if(led == 8) led = 5;
        lastRun=millis();
        state = true;
        digitalWrite(led, state);
    }
}

void setup() {
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(2), color_swap, RISING);
}

void loop() {
    unsigned long newTime = millis();

    if(newTime - oldTime >= interval) {
        oldTime = newTime;
        state = !state;
        digitalWrite(led, state);
    }
    
}