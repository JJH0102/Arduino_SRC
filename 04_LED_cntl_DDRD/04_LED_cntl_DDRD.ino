void setup() {
  DDRD |= 0xC0;
}

void loop() {
  PORTD |= 0xC0; // 원하는 비트를 1로 변경(7, 6)
  delay(100);
  PORTD &= 0x00; // 원하는 비트를 0으로 변경(7, 6)
  delay(100);
}
