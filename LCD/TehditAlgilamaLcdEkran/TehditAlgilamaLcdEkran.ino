#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

#define TRIGGER 13
#define ECHO 12

int time;
int distance;
void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  digitalWrite(TRIGGER, 1);
  delayMicroseconds(1000);
  digitalWrite(TRIGGER, 0);

  time = pulseIn(ECHO, 1);
  distance = (time / 2) / 28.5;

  /*lcd.home();
              lcd.setCursor(6, 0);
              lcd.print("Fire");
              lcd.setCursor(4, 1);
              lcd.print("Detected");*/

  if (distance <= 10) {
    lcd.clear();
    lcd.home();
    lcd.setCursor(5, 0);
    lcd.print("Tehdit");
    lcd.setCursor(3, 1);
    lcd.print("Cok Yakin");
    delay(1000);
  }

  else if (distance <= 25) {
    lcd.clear();
    lcd.home();
    lcd.setCursor(5, 0);
    lcd.print("Tehdit");
    lcd.setCursor(5, 1);
    lcd.print("Yakin");
    delay(1000);
  }

  else {
    lcd.clear();
    lcd.home();
    lcd.setCursor(5, 0);
    lcd.print("Tehdit");
    lcd.setCursor(6, 1);
    lcd.print("Yok");
    delay(1000);
  }
}
