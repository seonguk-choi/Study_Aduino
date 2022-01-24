#include<Servo.h>
Servo myservo;

int gabun = A0;
int gabunValue = 0;

int trig = 10;
int echo = 9;

int interval = 3;
int lastMillis = 0;

void setup() {
 Serial.begin(9600);

 //서버모터 포트 지정
 myservo.attach(11);

 //0도 셋팅
 myservo.write(0);

 pinMode(gabun, INPUT);

 pinMode(trig, OUTPUT);
 pinMode(echo, INPUT);
 
}

void loop() {
//  for(int i = 0 ; i < 180 ; i++){   
//    myservo.write(i);
//    delay(10);
//  }
//  for(int j = 179; j >0 ; j--){
//    myservo.write(j);
//    delay(10);
//  }

// gabunValue = analogRead(gabun);
// 
//  myservo.write(map(gabunValue, 0, 1023, 0,179));
//  delay(10);

  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);

  
  int duration = pulseIn(echo, HIGH);
  int distance = (duration/2) / 29.1;

  Serial.print(distance);
  Serial.println(" cm");
  delay(100);

  if(distance > 0 && distance <= 100){
    if(distance <= 10){
      myservo.write(90);
      lastMillis = millis()/1000;
    }else if(distance > 10){
      if(millis() - lastMillis >= interval){
         myservo.write(0);
      }
     
    }
  }
  
}
