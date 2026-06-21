#include <Arduino.h>

const int ledPin = 2;

// 时序参数（和你示例完全一致）
const unsigned long shortOn = 200;    // 短亮
const unsigned long shortOff = 200;   // 短熄灭
const unsigned long longOn = 600;     // 长亮
const unsigned long charGap = 500;    // S/O 之间间隔
const unsigned long wordGap = 2000;   // 整套SOS结束停顿

// 状态机枚举
enum State {
    S1_FLASH, S1_GAP,
    O1_FLASH, O1_GAP,
    S2_FLASH, S2_GAP,
    END_WAIT
};

State curState = S1_FLASH;
unsigned long prevTime = 0;
int flashCnt = 0; // 闪烁计数
bool ledOn = false;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  unsigned long now = millis();
  if (now - prevTime < (ledOn ? (curState == O1_FLASH ? longOn : shortOn) : shortOff)) {
    return;
  }

  prevTime = now;

  if (!ledOn) {
    // 当前熄灭，点亮LED
    ledOn = true;
    digitalWrite(ledPin, HIGH);
  } else {
    // 当前点亮，熄灭LED
    ledOn = false;
    digitalWrite(ledPin, LOW);
    flashCnt++;

    switch (curState) {
      case S1_FLASH:
        if (flashCnt >= 3) {
          flashCnt = 0;
          curState = S1_GAP;
          prevTime = now + charGap;
        }
        break;
      case S1_GAP:
        curState = O1_FLASH;
        break;
      case O1_FLASH:
        if (flashCnt >= 3) {
          flashCnt = 0;
          curState = O1_GAP;
          prevTime = now + charGap;
        }
        break;
      case O1_GAP:
        curState = S2_FLASH;
        break;
      case S2_FLASH:
        if (flashCnt >= 3) {
          flashCnt = 0;
          curState = END_WAIT;
          prevTime = now + wordGap;
        }
        break;
      case END_WAIT:
        curState = S1_FLASH;
        break;
    }
  }
}