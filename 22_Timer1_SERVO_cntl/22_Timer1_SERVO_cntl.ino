#include <TimerOne.h>

const int SERVO = 10;
const int buttonPin = 2;
const int flag = 0;

void buttonPressed(void) {
  if (flag == 0) {
    
  }
  else {
    
  }
  
}

void setup() {
  Timer1.initialize(20000);
  Timer1.pwm(SERVO, 0);
  
  pinMode(buttonPin, INPUT);

  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressed, RISING);

}

void loop() {

  flag = digitalRead(buttonPin);

  // 0도
  Timer1.setPwmDuty(SERVO, 27);
  delay(500);

  // 90도
  Timer1.setPwmDuty(SERVO, 77);
  delay(500);

  // 180도
  Timer1.setPwmDuty(SERVO, 127);
  delay(500);
}
