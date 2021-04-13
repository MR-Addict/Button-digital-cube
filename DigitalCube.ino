const int Button1 = 10;
const int Button2 = 11;
unsigned long int LastTime;
int count;
const int ledCount = 8;
const unsigned char DuanMa[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
int ledPins[] = {
  2, 3, 4, 5, 6, 7, 8, 9,
};

void deal(unsigned char value) {
  for (int i = 0; i < 8; i++)
    digitalWrite(ledPins[i], bitRead(value, i)); //使用了bitWrite函数，非常简单
}

void setup() {
  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }
  Serial.begin(9600);
  deal(DuanMa[count]);
}

void loop() {
  boolean Button1Status = digitalRead(Button1);
  boolean Button2Status = digitalRead(Button2);
  if (!Button1Status && millis() - LastTime > 200) {
    count ++;
    if (count == 10)
      count = 0;
    deal(DuanMa[count]);
    Serial.println(count);
    LastTime = millis();
  }
  else if(!Button2Status && millis() - LastTime > 200){
    count --;
    if (count == -1)
      count = 9;
    deal(DuanMa[count]);
    Serial.println(count);
    LastTime = millis();
  }
}
