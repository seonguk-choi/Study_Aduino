#define C 262  // 도
#define D 294  // 레
#define E 330  // 미
#define F 349  // 파
#define G 392  // 솔
#define A 440  // 라
#define B 494  // 시
int piezoPin = 7;
int tempo = 200;

//int notes[25] = {G, G, A, A, G, G, E, G, G, E, E, D, G, G, A, A, G, G, E, G, E, D, E, C };

int notes1[15] = [E, D, C, E, D, C, G, G, A, G, F, E, C, D };


void setup() {
  Serial.begin(9600);

  pinMode(piezoPin, OUTPUT);
}

void loop() {
  tone (piezoPin, notes1[1], 400);
  for(int i = 2 ; i < 6 ; i++){
    tone (piezoPin, note1[i], 200);
  }
  tone (piezoPin, notes1[6], 400);
  tone (piezoPin, notes1[7], 200);
  tone (piezoPin, notes1[8], 300);
  tone (piezoPin, notes1[9], 200);
  tone (piezoPin, notes1[10], 400);
  tone (piezoPin, notes1[11], 300);
  tone (piezoPin, notes1[12], 200);
 tone (piezoPin, notes1[13], 200);
 tone (piezoPin, notes1[14], 200);
}
