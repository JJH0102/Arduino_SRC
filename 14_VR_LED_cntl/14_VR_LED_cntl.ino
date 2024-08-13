const int analogPin = A0;
const int ledPin = 3;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int analogValue = analogRead(analogPin);  // 0 ~ 1023 값 출력
  int val = map(analogValue, 90, 300, 0, 255);  // analogValue에는 0~1023 값이 들어오지만 0~255에 맞춰서 값을 리턴

  analogWrite(ledPin, val);
  Serial.println(analogValue);
}
