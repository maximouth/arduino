
//alimentation du potentiometre
const int pot = 6;

//potentiometre branché sur ax analog

// les 4 valeurs du coffres
int code[4];

//connaitre la position dans l'automate
int cpt = 0;
// valeur du potentiomatre
int val = 0;
//temps pour determiner les differants changements
unsigned long time1 = 0;
unsigned long time2 = 0;


void setup() {
 Serial.begin(9600);
 digitalWrite(pot,HIGH);
 time1 = millis();
}

void loop() {
  val = analogRead(1);
  
  
  
}
