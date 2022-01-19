int ledR = 10;
int ledG = 9;
int ledY = 11;
int btn1 = 8;
int btn1Value = 0;

int btn1State = 0;

int before = 0; //버튼이 눌린 상태
int cnt = 0;    //led on/off


//led : 짧은 선 -, 긴 선 포트연결
//버튼 : - 에 저항(갈검주), -에서 포트 연결

void setup() {
  //시리얼 모니터 사용하기 위해 초기화
  //입력 값이나 변수값 확인
  
  Serial.begin(9600);
  
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(btn1, INPUT);
}

void loop() {
  
  btn1Value = digitalRead(btn1);
      
//    if(btn1Value == 1) {
//      if(btn1State == 0){
//        btn1State = 1;    
//      } else {
//        btn1State = 0;
//      }
//    }
//  
//    if(btn1State == 0){
//      digitalWrite(ledR, LOW);
//    } else {
//      digitalWrite(ledR, HIGH);
//    }

    Serial.print("btn1Value : ");
    Serial.println(btn1Value);
    Serial.print(", before : ");
    Serial.println(before);
    Serial.print(", cnt : ");
    Serial.println(cnt);
        
    if(btn1Value == 1) {
      if(before == 0){
        cnt++;
        before = 1;
      }
      if(cnt == 3){
        cnt = 0;
      }    
    } else {
      before = 0;
    }
    
    if(cnt == 1){
      digitalWrite(ledR, LOW);
      digitalWrite(ledG, HIGH);
    } else if(cnt == 2){
      digitalWrite(ledG, LOW);
      digitalWrite(ledY, HIGH);
    }else{
      digitalWrite(ledY, LOW);
      digitalWrite(ledR, HIGH);
    }
}
