#include "Ultrasonic.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);   // 연결핀 설정
Ultrasonic ulso(5,6); // trig,echo

void setup(void)
{  
  
  lcd.begin(16, 2);           // LCD크기설정 (행,열)
  lcd.setCursor(0, 0);
  lcd.print("Distance range");
  delay(2000);

}

void loop(void)
{   
    lcd.setCursor(0,1);    
    lcd.print(ulso.Ranging(CM));
    lcd.print("cm");    
    delay(1000);
}
