/*Code modified by Carlos Jarro
The goal of this code is to provide an initial template for 
display usage when connected to an I2C adapter*/
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

//Cool Icons
byte heart[8] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};

byte smiley[8] = {
  B00000,
  B01010,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000,
};

byte up[8] = {
  B00100,
  B00100,
  B01110,
  B01110,
  B11111,
  B11111,
  B00100
};

int counter = 0;

void setup() {
  // put your setup code here, to run once:
lcd.init();
lcd.backlight();

// Create custom characters
lcd.createChar(0, heart);
lcd.createChar(1, smiley);
lcd.createChar(2, up);
// x, y
lcd.setCursor(3,0);
lcd.print("HELLOOOOOO");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (counter == 0)
  {
    lcd.setCursor(1,0);
    lcd.write(1);
    lcd.setCursor(14,0);
    lcd.write(1);
    counter = 1;
  }
  else if (counter == 1)
  {
    lcd.setCursor(1,0);
    lcd.write(2);
    lcd.setCursor(14,0);
    lcd.write(2);
    counter = 2;
  }
  else if (counter == 2)
  {
    lcd.setCursor(1,0);
    lcd.write(0);
    lcd.setCursor(14,0);
    lcd.write(0);
    counter = 0;
  }

lcd.setCursor(0,1);
lcd.print("Seconds: ");
lcd.print(millis() / 1000);
delay(1000);
}
