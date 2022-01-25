#include<Servo.h>
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i =0; i <= 179; i++){
    myservo.write(i);
    delay(10);
  }
  
  
  for(int i =179; i >= 0; i--){
    myservo.write(i);
    delay(10);
  }
//  myservo.write(1);
//  delay(1000);
//  myservo.write(179);
//  delay(1000);
}
