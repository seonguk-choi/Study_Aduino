int trig = 7;
int echo = 8;

int piezo = 9;

void setup() {
  Serial.begin(9600);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(piezo, OUTPUT);
}

void loop() {

  
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);

  int duration = pulseIn(echo, HIGH);
  int distance = (duration/2) / 29.1;

  Serial.print(distance);
  Serial.println(" cm");
  delay(100);

  if(distance > 0 && distance < 100){
    tone (piezo, 349, 1000);
    delay(100);
  }

}
