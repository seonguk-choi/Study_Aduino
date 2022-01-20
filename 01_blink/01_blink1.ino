int ledR = 9;
int ledG = 10;
//한번만 실행 : 환경설정
void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
}

// 계속해서 반복 실행
void loop() {
  analogWrite(ledR, 50);
  delay(100);
  analogWrite(ledR, 100);
  delay(100);
  analogWrite(ledR, 150);
  delay(100);
  analogWrite(ledR, 200);
  delay(100);
  analogWrite(ledR, 255);
  delay(100);
  analogWrite(ledR, 0);
  delay(100);
  analogWrite(ledG, 50);
  delay(100);
   analogWrite(ledG, 100);
  delay(100);
  analogWrite(ledG, 150);
  delay(100);
  analogWrite(ledG, 200);
  delay(100);
  analogWrite(ledG, 255);
  delay(100);
  analogWrite(ledG, 0);
  delay(100);

}
