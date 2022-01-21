void makeRandom();
int num1 = 0; // 랜덤수
int chkNum = 0; // 내가 입력한 수

int ledR = 3;
int ledG = 4;

void setup() {  
  Serial.begin(9600);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);

  // 반드시 처음에 랜덤시드를 만들어 줘야 한다
  randomSeed(analogRead(A0));
  makeRandom();
  
  //num1 = random(50, 100); // 50-99  
}

void loop() {  
  while(Serial.available()){
    chkNum = Serial.parseInt();
  
    // 틀리면 그냥 보여준다
    if(chkNum != num1){
      Serial.print(chkNum);
      Serial.println(" : Fail"); 
      digitalWrite(ledR, HIGH);
      delay(2000); 
      digitalWrite(ledR, LOW);
    }
    // 맞으면 다시 랜덤수 만들어 시작
    if(chkNum == num1){
      Serial.print(chkNum);
      Serial.println(" : Success !!!");

      digitalWrite(ledG, HIGH);
      delay(2000); 
      digitalWrite(ledG, LOW);

      makeRandom();
      
    }

  }
   
  
}

void makeRandom(){
  Serial.println("Making Random Number !!!");
  Serial.println("Let's Start ");
  num1 = random(1, 10); // 1-9
  Serial.println(num1);
}
