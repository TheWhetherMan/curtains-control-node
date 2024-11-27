/*
*  Curtains Control Node
*  December 2014
*
*  Displays current status on LCD, controls electric motor that opens/closes curtain
*/
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte lcdBlock[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
int pitch = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Initializing...");
  lcd.blink();
  delay(2000);
  lcd.noBlink();
  lcd.clear();
  
  lcd.createChar(0, lcdBlock);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 16; j++) {
      lcd.setCursor(j, i);
      lcd.write(byte(0));
      delay(100);
    }
  }
  
  lcd.clear();
}

void loop() {
  tone(13, pitch, 100);
  lcd.print(pitch);
  delay(500);
  lcd.clear();
  
  if (pitch >= 4500) {
    pitch = 100;
  } else {
    pitch += 100;
  }
}


