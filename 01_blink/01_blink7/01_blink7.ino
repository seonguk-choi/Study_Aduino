int jodo = 0;
int ledY = 9;

void setup() {
  Serial.begin(9600);
  
  pinMode(A0, INPUT);
  pinMode(ledY, OUTPUT);
}


void loop() {
  int val = analogRead(jodo);

  Serial.println(val);

  analogWrite(ledY, map(val, 0, 890, 255,0));
}
