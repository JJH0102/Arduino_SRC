#define A_REF       5.0 // 레퍼런스 전압
#define RESOLUTION  1024
#define UNIT_ADC    A_REF / RESOLUTION

char str[100];
const int analogPin = A0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  double analogValue = analogRead(analogPin);

  sprintf(str, "%.1lf, %.2lf", analogValue, analogValue * UNIT_ADC);
  Serial.println(str);

  // Serial.print(analogValue, 0);
  // Serial.print(", ");
  // Serial.println(analogValue * UNIT_ADC, 6);
}
