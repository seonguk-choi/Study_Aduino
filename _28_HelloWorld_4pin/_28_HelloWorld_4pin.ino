//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // 0x27  set the LCD address to 0x27 for a 16 chars and 2 line display

void setup(){
  lcd.begin();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
  
}


void loop(){
  for (int posCnt = 0; posCnt < 13; posCnt++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }  
  
  for (int posCnt = 0; posCnt < 29; posCnt++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(150);
  }

  for (int posCnt = 0; posCnt < 16; posCnt++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }

  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);

  for(int i = 0 ; i < 10; i++){    
    lcd.clear();
    delay(100);
    lcd.setCursor(0, 0);
    lcd.print("Hello, World!");
    delay(100);
  }
  
  // delay at the end of the full loop:
  delay(5000);
  
}
