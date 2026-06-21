#include <Arduino.h>
// 定义LED引脚
const int ledPin = 2;
const int pwmCh = 0;   // 手动分配PWM通道0

// 设置PWM属性
const int freq = 5000;          // 频率 5000Hz
const int resolution = 8;       // 分辨率 8位 (0-255)

void setup() {
  Serial.begin(115200);
  // 1. 配置PWM通道
  ledcSetup(pwmCh, freq, resolution);
  // 2. 绑定引脚到通道
  ledcAttachPin(ledPin, pwmCh);
}

void loop() {
  // 逐渐变亮
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){
    ledcWrite(pwmCh, dutyCycle);
    delay(10);
  }
  // 逐渐变暗
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    ledcWrite(pwmCh, dutyCycle);
    delay(10);
  }
  Serial.println("Breathing cycle completed");
}