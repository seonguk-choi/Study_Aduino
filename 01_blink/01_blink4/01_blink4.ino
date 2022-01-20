#include<String.h>

String str = "";

void setup() {
    Serial.begin(9600);

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
        int val = Serial.parseInt();
        Serial.println(val);        

    }
}
