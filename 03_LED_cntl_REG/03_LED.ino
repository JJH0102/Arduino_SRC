const int LED[8] = { 2, 4, 6, 8, 3, 5, 7, 9};

void setup() {
  // put your setup code here, to run once:

  for (int i = 0; i < 8; i++) {
    pinMode(LED[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], HIGH);
  }
  delay(2000);

  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], LOW);
  }
  delay(2000);
}
