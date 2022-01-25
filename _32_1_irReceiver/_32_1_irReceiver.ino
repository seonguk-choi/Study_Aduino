/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int led_pin = 3;
int RECV_PIN = 9;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  
  pinMode(led_pin, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    Serial.println(digitalRead(led_pin));

    if(results.value == 16580863){   
      if(digitalRead(led_pin) == LOW){
        digitalWrite(led_pin, HIGH);
        Serial.println("Here!!!");
      }else{
        digitalWrite(led_pin, LOW);
        Serial.println("Here2!!!");
      }
        
    }
    
    irrecv.resume(); // Receive the next value

  }
}
