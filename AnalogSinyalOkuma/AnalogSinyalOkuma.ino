void setup() {
  Serial.begin(9600);
  pinMode(PLUS, INPUT);
  //pinMode(MINUS, INPUT_PULLUP);
}
void loop() {
  if (digitalRead(PLUS) == 1) {
    counter++;
    Serial.print("Sayac = ");
    Serial.println(counter);
    while (digitalRead(PLUS) == 1) {
      delay(1);
    }
  }
  /*if (digitalRead(MINUS) == 0) {
    Serial.print("Sayac = ");
    Serial.println(counter);
    while (digitalRead(MINUS) == 0)
      delay(1);
  }*/
}
