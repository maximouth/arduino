const int m0 = 8;
const int m1 = 9;
const int m2 = 10;
const int m3 = 11;
int start = 2;
int reset = 3;
const int s = 2;

int etat = 0;

void setup() {
  pinMode(m0, OUTPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(s,INPUT_PULLUP);
  attachInterrupt(0,swap,FALLING);
  attachInterrupt(1,restart,FALLING);
  Serial.begin(9600);

}


void restart() {
  Serial.println("restart");
  etat=0;
}

void swap() {
  Serial.println("start");
  delay(1000);
  if (start == 0) {
    start = 1;
  } 
  else {
    start = 0;
  }
}


void loop() {
  // Serial.println("start");
 
  delay(5);
 
  if (start == 0) {
    return;
  }
  else {

    switch (etat) {

 case 0 : //c0
  digitalWrite(m0, HIGH);
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  etat = 1;
  break;
 
 case 1://c1
  digitalWrite(m0, HIGH);
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  etat = 2;
  break;
 
 case 2://c2
  digitalWrite(m0, LOW);
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  etat = 3;
  break;

 case 3://c3
  digitalWrite(m0, LOW);
  digitalWrite(m1, HIGH);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, LOW);
  etat = 4;
  break;

  case 4://c4
  digitalWrite(m0, LOW);
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, LOW);
  etat = 5;
  break;

 case 5://c5
  digitalWrite(m0, LOW);
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, HIGH);
  etat = 6;
  break;

 case 6://c6
  digitalWrite(m0, LOW);
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  etat = 7;
  break;

case 7://c7
  digitalWrite(m0, HIGH);
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  etat = 0;
  break;

    }
  }


}
