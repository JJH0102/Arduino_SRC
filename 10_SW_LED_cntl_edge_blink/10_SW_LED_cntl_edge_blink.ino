/*
  하드웨어 설계
  - SW(스위치)는 Active HIGH
  - LED는 Active HIGH
*/

const int ledPin = 5;
const int buttonPin = 4;
int led_flag = 0; // 0 = LED off, 1 = LED on
int cur_btn_val = LOW, per_btn_val = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  // LED를 끄고 시작
  digitalWrite(ledPin, LOW);
}

void loop() {
  int cur_btn_val = digitalRead(buttonPin); // 현재값 저장

  // 스위치 동작에 따른 상태값 변경

  if (per_btn_val == LOW && cur_btn_val == HIGH) {
    if (led_flag == 0) {  // 꺼져 있으면 켜고
      led_flag = 1;
    }
    else {  // 켜져 있으면 끄고
      led_flag = 0;
    }
  }

  // 상태값에 따른 동작 구현

  if (led_flag == 1) {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }

  per_btn_val = cur_btn_val;  // 이전값 갱신
}