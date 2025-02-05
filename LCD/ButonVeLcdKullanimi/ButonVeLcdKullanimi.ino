#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
#define BTN 8
int state;
void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(BTN, INPUT_PULLUP);
}

void loop() {
  state = digitalRead(BTN);
  if (state == 0) {
    lcd.home();
    lcd.setCursor(4, 0);
    lcd.print("Butona");
    lcd.setCursor(4, 1);
    lcd.print("Basildi");
  } else {
    lcd.clear();
  }
}
