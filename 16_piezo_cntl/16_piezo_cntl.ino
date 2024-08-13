const int piezo = 10;

const int melody[8] = {262, 294, 330, 349, 393, 440, 494, 523,};

void setup() {
  for (int note = 0; note < 8; note++) {
    tone(piezo, melody[note]);
    delay(500);
  }

  noTone(piezo);
}

void loop() {
  // digitalWrite(piezo, HIGH);
  // delayMicroseconds(1900);
  // digitalWrite(piezo, LOW);
  // delayMicroseconds(1900);
}
