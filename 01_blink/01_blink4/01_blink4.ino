#include<String.h>

String str = "";

int ledR = 9;
int ledY = 10;
int ledG = 11;

int val = 0;

void setup() {
    Serial.begin(9600);

    pinMode(ledR, OUTPUT);
    pinMode(ledY, OUTPUT);
    pinMode(ledG, OUTPUT);

}

void loop() {
    //시리얼 버퍼에 데이터가 있으면 1
    //데이터가 없으면 0

    while(Serial.available()){
//      문자로 읽어들임      
//      char ch = Serial.read();
//
//      Serial.println(ch);
//      str += ch;
//      Serial.println(str);

//      숫자로 읽어들임
        val = Serial.parseInt();
        Serial.println(val);   

    }


    if(val == 1) {
      digitalWrite(ledR, HIGH);
      digitalWrite(ledY, LOW);
      digitalWrite(ledG, LOW);
    } else if(val == 2) {
      digitalWrite(ledR, LOW);
      digitalWrite(ledY, HIGH);
      digitalWrite(ledG, LOW);
    } else if(val == 3) {
      digitalWrite(ledR, LOW);
      digitalWrite(ledY, LOW);
      digitalWrite(ledG, HIGH);
    } else if(val == 4){
      digitalWrite(ledR, LOW);
      digitalWrite(ledY, LOW);
      digitalWrite(ledG, LOW);
    }

    
}
