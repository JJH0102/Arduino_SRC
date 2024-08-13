void setup() {
  Serial.begin(115200);
}

void loop() {

}

void serialEvent() {
  char inChar = (char)Serial.read();
  Serial.print(inChar);
}
