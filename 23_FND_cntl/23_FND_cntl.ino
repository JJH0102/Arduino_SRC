const unsigned char fnd_pin[8] = { 2, 3, 4, 5, 6, 7, 8, 9 }; // -> { a, b, c, d, e, f, g, dp }
const unsigned char fnd_data[10] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xF6};

void FND_OUTPUT(int num);

void setup() {
  
  for (int i = 0; i < 8; i++) {
    pinMode(fnd_pin[i], OUTPUT);
  }
}

void loop() {
  // 0 ~ 9 출력
  for (int i = 0; i < 10; i++) {
    FND_OUTPUT(i);
    delay(500);
  }
}

void FND_OUTPUT(int num)
{
  for (int i = 0; i < 8; i++) {
    digitalWrite(fnd_pin[i], fnd_data[num] & (0x80 >> i));
  }
}