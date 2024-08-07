const unsigned int LED_0 = 2;
const unsigned int LED_1 = 3;
const unsigned int LED_2 = 4;
const unsigned int LED_3 = 5;
const unsigned int LED_4 = 6;
const unsigned int LED_5 = 7;
const unsigned int LED_6 = 8;
const unsigned int LED_7 = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_0, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
  pinMode(LED_6, OUTPUT);
  pinMode(LED_7, OUTPUT);

  digitalWrite(LED_0, HIGH);
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_4, HIGH);
  digitalWrite(LED_5, HIGH);
  digitalWrite(LED_6, HIGH);
  digitalWrite(LED_7, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for (int t_high = 0; t_high < 1001; t_high++) {
    digitalWrite(LED, HIGH);
    delayMicroseconds(t_high);

    digitalWrite(LED, LOW);
    delayMicroseconds(1000 - t_high);
  }
}
