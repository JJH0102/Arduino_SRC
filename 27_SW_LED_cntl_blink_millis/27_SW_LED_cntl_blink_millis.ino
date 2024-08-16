/*
  하드웨어 설계
  - SW(스위치)는 Active HIGH
  - LED는 Active HIGH
*/

const int ledPin1 = 4;
const int buttonPin1 = 2;
const int ledPin2 = 5;
const int buttonPin2 = 3;
const int com1 = 10;
int led_flag1 = 0; // 0 = LED off, 1 = LED on
int led_flag2 = 0;

const unsigned long t1_delay = 300;
unsigned long t1_prev = 0;

const unsigned long t2_delay = 500;
unsigned long t2_prev = 0;

// 사용자 함수 선언
// ISR(인터럽트 서비스 루틴)
void buttonPressed1(void)
{
  // 스위치 동작에 따른 상태값 변경

  if (led_flag1 == 0) {  // 꺼져 있으면 켜고
      led_flag1 = 1;
    }
  else {  // 켜져 있으면 끄고
    led_flag1 = 0;
  }
}

void buttonPressed2(void)
{
  // 스위치 동작에 따른 상태값 변경

  if (led_flag2 == 0) {  
      led_flag2 = 1;
    }
  else {  
    led_flag2 = 0;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin1, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(com1, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin1), buttonPressed1, RISING);
  attachInterrupt(digitalPinToInterrupt(buttonPin2), buttonPressed2, RISING);

  // LED를 끄고 시작
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);

  digitalWrite(com1, HIGH);
}

void loop() {

 

  // 상태값에 따른 동작 구현
  unsigned long t1_now = millis();
  
  if (t1_now - t1_prev >= t1_delay) {
    t1_prev = t1_now;

    if (led_flag1 == 1) {
      digitalWrite(ledPin1, digitalRead(ledPin1) ? LOW : HIGH);
    }
  }

  unsigned long t2_now = millis();
  if (t2_now - t2_prev >= t2_delay) {
    t2_prev = t2_now;

    if (led_flag2 == 1) {
      digitalWrite(ledPin2, digitalRead(ledPin2) ? LOW : HIGH); 
    }
  }
}