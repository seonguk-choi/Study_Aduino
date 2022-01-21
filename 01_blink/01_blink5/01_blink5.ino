#include<String.h>

int sum = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
    while(Serial.available()){
        int val = Serial.parseInt();
        Serial.print(sum);
        Serial.print(" + ");
        Serial.print(val);
        Serial.print(" = ");
        sum = sum + val;
        Serial.println(sum);
    }
}
