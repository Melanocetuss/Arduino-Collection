int state;
#define BUTTON 8
#define LEDRED 2
#define LEDBLUE 3
#define LEDGREEN 4
#define LEDYELLOW 5
#define LEDWHITE 6
void setup() {
  //Serial.begin(9600);
  pinMode(BUTTON, INPUT);
  pinMode(LEDRED, OUTPUT);
  pinMode(LEDBLUE, OUTPUT);
  pinMode(LEDGREEN, OUTPUT);
  pinMode(LEDYELLOW, OUTPUT);
  pinMode(LEDWHITE, OUTPUT);
}

void loop() {
  state = digitalRead(BUTTON);
  if (state == 0) {
    digitalWrite(LEDRED, LOW);
    digitalWrite(LEDBLUE, LOW);
    digitalWrite(LEDGREEN, LOW);
    digitalWrite(LEDYELLOW, LOW);
    digitalWrite(LEDWHITE, LOW);
  }

  else {
    digitalWrite(LEDRED, HIGH);
    digitalWrite(LEDBLUE, HIGH);
    digitalWrite(LEDGREEN, HIGH);
    digitalWrite(LEDYELLOW, HIGH);
    digitalWrite(LEDWHITE, HIGH);
  }
}