#include <Arduino.h>

int ping(byte TriggerPin, byte EchoPin) {
    long duration, distanceCm;

    digitalWrite(TriggerPin, LOW);
    delayMicroseconds(4);

    digitalWrite(TriggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TriggerPin, LOW);

    duration = pulseIn(EchoPin, HIGH);

    distanceCm = duration * 10 / 292 / 2;
    
    return distanceCm;
}

void setup() {
    Serial.begin(9600);
    pinMode(4, OUTPUT);
}

void loop() {
    if(ping(6,5) <= 10) {
        Serial.println("Close");
        digitalWrite(4, HIGH);
        delay(500);
    } else {
        Serial.println("Safe");
        delay(500);
    }
    digitalWrite(4, LOW);
}