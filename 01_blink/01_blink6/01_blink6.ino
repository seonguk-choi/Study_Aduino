#include<String.h>

void makeRandom();

int num1 = 0;
int chkNum = 0;

int ledR = 9;
int ledY = 10;

int on = 0;

void setup() {  
 Serial.begin(9600);

 pinMode(ledR, OUTPUT);
 pinMode(ledY, OUTPUT);
 //값을 계속 새롭게 해줌
 randomSeed(analogRead(A0));

 Serial.println("Making Random Number!!!");
 Serial.println("Let's Start");

 num1 = random(1, 10); // 1 ~ 9
 //Serial.println(num1);
 
}

void loop() {
  while(Serial.available()){
        //num1 = random(1, 10);
        //Serial.println(num1);
        chkNum = Serial.parseInt();
        if(chkNum == num1){
          Serial.print(chkNum);
          Serial.println(" : 성공");
          on =1;
          makeRandom();
        } else {
          Serial.print(chkNum);
          Serial.println(" : 실패");
          on = 0;
        }
    }

    
  if(on == 1){
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, HIGH);
    delay(1000);
    digitalWrite(ledY, HIGH);
    
  } else {
    digitalWrite(ledR, LOW);
    digitalWrite(ledY, HIGH);
  }
}

void makeRandom(){
  randomSeed(analogRead(A0));
  Serial.println("Making Random Number!!!");
  Serial.println("Let's Start");
  num1 = random(1, 10);
}
