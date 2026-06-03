#include <Arduino.h>
#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Skanerlash boshlandi...");  

  for(byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if(Wire.endTransmission() == 0) {
      Serial.print("topildi: 0x");
      Serial.println(addr, HEX);
    }
  }
}

void loop() {

}