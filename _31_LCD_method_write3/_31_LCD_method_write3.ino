#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // 0x27  set the LCD address to 0x27 for a 16 chars and 2 line display

void setup(){
  Serial.begin(9600);
  
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
  
}

void loop() {

  if(Serial.available()){
    char ch = Serial.read();
    if(ch == '/'){
      lcd.clear();
    }else{
      lcd.write(ch);
    }
    
  }

  
}
