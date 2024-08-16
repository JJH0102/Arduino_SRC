                              // a, b, c, d, e, f, g, h
const unsigned char fnd_pin[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
const unsigned char fnd_digit[4] = {10, 11, 12, 13};
const unsigned char fnd_data[10] = { 0xFC, 0x60, 0xDA, 0xF2, 0x66, 
                                    0xB6, 0xBE, 0xE4, 0xFE, 0xF6 };

unsigned int num = 0;

void FND_OUTPUT(int num);
void fnd_display(unsigned int num);

void digit_clear(); //digit 전부 LOW로

void setup() {

  for(int i=0; i<8; i++) {
    pinMode(fnd_pin[i], OUTPUT);
  }
  for(int i=0; i<4; i++) {
    pinMode(fnd_digit[i], OUTPUT);
    digitalWrite(fnd_digit[i], LOW);
  }
}

void loop() {
  fnd_display(6698);
}


void FND_OUTPUT(int num) {

  for(int i=0; i<8; i++){
    digitalWrite(fnd_pin[i], (~fnd_data[num]) & (0x80>>i) );
  }
}

void fnd_display(unsigned int num){
  unsigned int num_1000 = (num%10000)/1000;
  unsigned int num_100 = (num%1000)/100;
  unsigned int num_10 = (num%100)/10;
  unsigned int num_1 = num%10;

  unsigned int num_arry[4] = {num_1000,num_100,num_10,num_1};

  for(int i=0; i<4; i++) {
    digitalWrite(fnd_digit[i], HIGH);
    FND_OUTPUT(num_arry[i]);
    delay(1);
    digitalWrite(fnd_digit[i], LOW);
  }
}

void digit_clear() {
  for(int i=0; i<4; i++) {
    digitalWrite(fnd_digit[i], LOW);
  }
}
