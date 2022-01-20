int gabun = A0;
int gabunValue = 0;

int ledR = 11;
int ledG = 10;
int ledB = 9;

int btnR =5;
int btnG =4;
int btnB =3;

int btnRstate = 0;
int btnGstate = 0;
int btnBstate = 0;

int btnRbefore = 0;
int btnGbefore = 0;
int btnBbefore = 0;

int cnt = 0;

void setup() {
  //시리얼 모니터 사용하기 위해 초기화
  //입력 값이나 변수값 확인
  
  Serial.begin(9600);
  
  pinMode(gabun, INPUT);
  
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);

  pinMode(btnR, INPUT);
  pinMode(btnG, INPUT);
  pinMode(btnB, INPUT);
}

void loop() {
  //gabunValue = analogRead(gabun);

  //Serial.println(gabunValue);

  //가변 저항 값 led값 다르다
  //-> map으로 값을 값게 변환

  //int ledValue = map(gabunValue, 250, 1020, 255, 0);

  //analogWrite(ledR, ledValue);
  
  btnRstate = digitalRead(btnR);
  btnGstate = digitalRead(btnG);
  btnBstate = digitalRead(btnB);

  
  Serial.print("btnR : ");
  Serial.print(btnRstate);
  Serial.print(", btnG : ");
  Serial.print(btnGstate);
  Serial.print(", btnB : ");   
  Serial.println(btnBstate);
  
  if(btnRstate == 1){
    if(btnRbefore == 0){
       cnt=1;
       btnRbefore = 1;
    }
    if(cnt > 3){
      cnt =0;
    }
  } else {
    btnRbefore = 0;
  }
  
  if(btnGstate == 1){
   if(btnGbefore == 0){
       cnt=2;
       btnGbefore = 1;
    }
    if(cnt > 3){
      cnt =0;
    }
  } else {
    btnGbefore = 0;
  }
  
  if(btnBstate == 1){
    if(btnBbefore == 0){
       cnt = 3;
       btnBbefore = 1;
    }
    if(cnt > 3){
      cnt = 0;
    }
  } else {
    btnBbefore = 0;
  }

  if(btnBstate == 1){
    if(btnBbefore == 0){
      cnt = 2;
      btnBbefore = 1;
    }
    if(cnt > 3){
      cnt = 0;
    }
  } else {
    btnBbefore = 0;
  }

  if(btnRstate == 1 && btnGstate == 1 && btnBstate == 1){
       cnt=0;
  }
  
  if(cnt == 1){
    digitalWrite(ledR, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(ledB, LOW);
  }else if(cnt == 2){
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledB, LOW);
  }else if(cnt == 3){
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledB, HIGH);
  } else if(cnt == 0){
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledB, LOW);
  }
  
//    for(int i = 0 ; i<256 ; i=i+5){
//      for(int j=0 ; j<256 ; j=j+5){
//        for(int k = 0 ; k<256; k=k+5){
//          analogWrite(ledR, i);
//          analogWrite(ledG, j);
//          analogWrite(ledB, k);
//        }
//      }
//    }
}
