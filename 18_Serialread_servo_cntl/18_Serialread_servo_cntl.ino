#include <Servo.h>

const int SERVO = 10;
int degree = 0;
Servo servo;

void setup() {
  Serial.begin(115200);
  servo.attach(SERVO, 544, 2500);
  servo.write(degree);
  delay(100);
}

void loop() {
  if (Serial.available()) {
    String rx_data = Serial.readString();
    Serial.print(rx_data);
    rx_data.trim(); 

    degree = rx_data.toInt();

    if (degree >= 0 && degree <= 180) {
       servo.write(degree);
    }

  }
}
