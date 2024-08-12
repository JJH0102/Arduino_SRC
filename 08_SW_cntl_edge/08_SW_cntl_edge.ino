/*
  하드웨어 설계
  - SW(스위치)는 Active LOW
  - LED는 Active LOW
*/

const int ledPin = 3;
const int buttonPin = 2;
int led_flag = 0; // 0 = LED off, 1 = LED on
int cur_btn_val = 0, per_btn_val = 1;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  // LED를 끄고 시작
  digitalWrite(ledPin , HIGH);
}

void loop() {
  int cur_btn_val = digitalRead(buttonPin); // 현재값 저장

  if (per_btn_val == LOW && cur_btn_val == HIGH) {
    if (led_flag == 0) {  // 꺼져 있으면 켜고
      digitalWrite(ledPin, LOW);
      led_flag = 1;
    }
    else {  // 켜져 있으면 끄고
      digitalWrite(ledPin, HIGH); 
      led_flag = 0;
    }
  }

  per_btn_val = cur_btn_val;  // 이전값 갱신
}