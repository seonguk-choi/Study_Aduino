// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd( 7, 8, 9, 10, 11,12);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);  
}

void loop() {
  
  if(Serial.available()){
    lcd.write(Serial.read());
    //lcd.print(Serial.read()); 
  }
}
