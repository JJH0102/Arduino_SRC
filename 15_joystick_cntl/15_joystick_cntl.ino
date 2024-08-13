const int Xin = A0;
const int Yin = A1;
const int KEYin = 3;

void setup() {
  pinMode(KEYin, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  int xVal = analogRead(Xin);
  int yVal = analogRead(Yin);
  int buttonVal = digitalRead(KEYin);

  Serial.print("X = ");
  Serial.println(xVal, DEC);

  Serial.print("Y = ");
  Serial.println(yVal, DEC);

  Serial.print("Button is ");

  if (buttonVal == HIGH) {
    Serial.println("not pressed");
  }
  else {
    Serial.println("pressed");
  }

  delay(500);
}
