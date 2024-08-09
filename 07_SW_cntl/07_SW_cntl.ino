const int ledPin = 3;
const int buttonPin = 2;
int led_flag = 0; // 0 = LED off, 1 = LED on

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  digitalWrite(ledPin , LOW);
}

void loop() {
  int buttonInput = digitalRead(buttonPin);

  if (buttonInput == 1) {
    if (led_flag == 0) {
      digitalWrite(ledPin, 1);
      led_flag = 1;
    }
    else {
      digitalWrite(ledPin, 0);
      led_flag = 0;
    }
    delay(300);
  }
}