#include <Arduino.h>
const int ledPin = 2;
// PWM参数
const int pwmChannel = 0;
const int freq = 5000;
const int resolution = 8;
unsigned long prevTime = 0;
const unsigned long interval = 15;
int brightness = 0;
int step = 1;

void setup() {
  Serial.begin(115200);
  ledcSetup(pwmChannel, freq, resolution);
  ledcAttachPin(ledPin, pwmChannel);
}

void loop() {
  unsigned long curTime = millis();
  if (curTime - prevTime >= interval)
  {
    prevTime = curTime;
    brightness += step;
    // 亮度边界反转渐变方向
    if (brightness <= 0 || brightness >= 255) {
      step = -step;
    }
    ledcWrite(pwmChannel, brightness);
  }
}