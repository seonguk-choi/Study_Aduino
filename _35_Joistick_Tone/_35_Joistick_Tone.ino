#include<Servo.h>
Servo myservo;

//int Direction = 12;
//int PWMA = 3; //속도어 PORT

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);  
  pinMode(6, INPUT);
  
  //pinMode(Direction, OUTPUT);
  //pinMode(PWMA, OUTPUT);
  
  myservo.attach(5);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a2 = analogRead(A2);
  int a3 = analogRead(A3);  
  int d7 = digitalRead(6);
  
  Serial.print(a2);
  Serial.print(", ");
  Serial.print(a3);
  Serial.print(", ");
  Serial.println(d7);
  
  if(a2 >= 515 && a2 <= 525){
    //digitalWrite(Direction, HIGH);
    //analogWrite(PWMA, 0); 
    
    myservo.write(map(a2, 0, 1023, 0 ,179));
  }
  else if(a2 < 515){
    //digitalWrite(Direction, LOW);
    myservo.write(map(a2, 515, 0, 0 ,179));
  }
  else if(a2 > 525){
    //digitalWrite(Direction, HIGH);
    myservo.write(map(a2, 525, 1023, 0 ,179));
  }
    
  
//  if(a3 >= 515 && a3 <= 525){
//    //digitalWrite(Direction, HIGH);
//    analogWrite(PWMA, 0); 
//  }
//  else if(a3 < 515){
//    digitalWrite(Direction, LOW);
//    analogWrite(PWMA, map(a3, 515, 0, 0 ,255));
//  }
//  else if(a3 > 525){
//    digitalWrite(Direction, HIGH);
//    analogWrite(PWMA, map(a3, 525, 1023, 0 ,255));
//  }
//    
  
}            
