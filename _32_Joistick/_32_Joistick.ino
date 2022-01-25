void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  pinMode(3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a0 = analogRead(A0);
  int a1 = analogRead(A1);  
  int d7 = digitalRead(3);
  
  Serial.print(a0);
  Serial.print(", ");
  Serial.print(a1);
  Serial.print(", ");
  Serial.println(d7);
    

}
