// 사용자 함수 선어
int myPinMode(int pin_num, int mode);

// 전역 변수 선언
unsigned char led_data[4] = { 0x04, 0x08, 0x10, 0x20 };
unsigned char ary_size = sizeof(led_data) / sizeof(led_data[0]);

void setup() {
  Serial.begin(115200);
  int state = myPinMode(3, OUTPUT);
}

void loop() {
    PORTD |= 0x01 << PORT3;
    delay(100);
    PORTD |= ~(0x01 << PORT3);
    delay(100);
}

int myPinMode(int pin_num, int mode)
{
  int pin_array[14] = {0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5};
  int port;
  int pin;

  if(pin_num > 13 || pin_num < 0) {
    Serial.println("pin 번호가 13 이하 0 이상이여야 합니다.");
    return -1;
  }
  else {
    pin = pin_array[pin_num];
  }

  if(pin_num > 7) {
    port = DDRB;
  }
  else {
    port = DDRD;
  }

  if (mode = OUTPUT) {
    port |= 0x01 << pin;
  }
  else {
    port |= ~(0x01 << pin);  
  }
}