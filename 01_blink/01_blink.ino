int ledR = 13;

//한번만 실행 : 환경설정
void setup() {
  pinMode(ledR, OUTPUT);
}

// 계속해서 반복 실행
void loop() {
  digitalWrite(ledR, HIGH);
  delay(500);
  digitalWrite(ledR, LOW);
  delay(500);
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);
  delay(1000);
  digitalWrite(11, HIGH);
  delay(1500);
  digitalWrite(11, LOW);
  delay(1500);
  
}
