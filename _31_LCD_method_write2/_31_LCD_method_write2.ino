// include the library code:
#include <LiquidCrystal.h>

LiquidCrystal lcd( 7, 8, 9, 10, 11,12);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  
  if(Serial.available()){    
      //lcd.clear();     
      char c;
      c = Serial.read();        
      if(c == '/'){
        lcd.setCursor(0,1); 
      }else if(c == '$'){
        lcd.clear();
      }
      else{       
        lcd.print(c); 
      }  
      Serial.print(c);       
  }
  Serial.println(); 
    
 
}

