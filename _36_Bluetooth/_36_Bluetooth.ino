#include <SoftwareSerial.h>
#define TxP 2
#define RxP 3

char recvChar;
SoftwareSerial BT(TxP, RxP);

void setup(){  
  Serial.begin(9600);
  BT.begin(9600);

  pinMode(RxP, INPUT);
  pinMode(TxP, OUTPUT);
  
}

void loop() {
  while(1){
    if(BT.available()){
      recvChar = BT.read();
      Serial.print(recvChar);
      Serial.println("Value : ");

      
    }
  }
}
