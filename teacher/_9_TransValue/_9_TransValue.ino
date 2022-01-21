int count = 0;

void setup() {  
  Serial.begin(9600);
}

void loop() {
  
  while(Serial.available()){
     //char c = Serial.read();
     int val = Serial.parseInt();
     
     count++;   
     Serial.print(count); 
     Serial.print(" : ");  
     Serial.println(val);     
  }
  
}
