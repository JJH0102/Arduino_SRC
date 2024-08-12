/*
  하드웨어 설계
  - SW2(스위치2)는 Active LOW, SW4(스위치4)는 Active HIGH
  - LED3는 Active LOW, LED5는 Active HIGH
*/

const int ledPin1 = 3;
const int ledPin2 = 5;
const int buttonPin1 = 2;
const int buttonPin2 = 4;
int led_flag = 0; // 0 = LED off, 1 = LED on
int cur_btn_val1 = LOW, per_btn_val1 = HIGH;
int cur_btn_val2 = LOW, per_btn_val2 = HIGH;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);

  // LED를 끄고 시작
  digitalWrite(ledPin1 , HIGH);
  digitalWrite(ledPin2 , LOW);
}

void loop() {
  int cur_btn_val1 = digitalRead(buttonPin1); // 현재값 저장
  int cur_btn_val2 = digitalRead(buttonPin2);

  if (per_btn_val1 == HIGH && cur_btn_val1 == LOW) {
    if (led_flag == 0) {  // 꺼져 있으면 켜고
      digitalWrite(ledPin1, LOW);
      led_flag = 1;
    }
    else {  // 켜져 있으면 끄고
      digitalWrite(ledPin1, HIGH); 
      led_flag = 0;
    }
  }

  if (cur_btn_val2 == HIGH && per_btn_val2 == LOW) {
    if (led_flag == 0) {  // 꺼져 있으면 켜고
      digitalWrite(ledPin2, HIGH);
      led_flag = 1;
    }
    else {  // 켜져 있으면 끄고
      digitalWrite(ledPin2, LOW); 
      led_flag = 0;
    }
  }

  per_btn_val1 = cur_btn_val1;  // 이전값 갱신
  per_btn_val2 = cur_btn_val2;
}