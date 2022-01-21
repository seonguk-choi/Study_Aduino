int RedPin = 10;
int Btn1 = 8;
int curBtnState;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RedPin, OUTPUT);
  pinMode(Btn1, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  
 curBtnState = digitalRead(Btn1);

 if(curBtnState == 0){
  digitalWrite(RedPin, LOW);
 }else{
  digitalWrite(RedPin, HIGH);
 } 
 
}
