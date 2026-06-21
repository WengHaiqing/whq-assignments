#include <Arduino.h>
const int ledPin = 2;
unsigned long prevTime = 0;
const unsigned long interval = 1000; // 1000ms=1Hz
bool ledState = false;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long curTime = millis();
  if (curTime - prevTime >= interval)
  {
    prevTime = curTime;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    if(ledState) Serial.println("LED ON");
    else Serial.println("LED OFF");
  }
}