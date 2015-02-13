//temps max avant remise a 0
#define TMAX 10000
//temps pour rentrer un chiffre
#define TCOMB 5000

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
  time2 = millis();

  //si 10 secondes se sont ecoulées sans que personne y touche remise a 0
  if ((time2-time1) > TMAX){
    cpt = 0;
    time1 = millis();
  }
  //sinon faire ce que l'on doit faire
  else {
    switch (cpt) {
      //premier chiffre
    case 0:
      Serial.println("entrez premier chiffre :");
      test();
      break;
      
      //second
    case 1 :
      Serial.println("entrez second chiffre :");
      test();
      break;

      //3eme
    case 2 :
      Serial.println("entrez 3eme chiffre :");
      test();
      break;

      //dernier
    case 3 :
      Serial.println("Et le dernier :");
      //tester si bon et ouvrir
      if (test() == 1 ) {
	Serial.println("bienjoué");
	//allumer led verte
      }
      else {
	Serial.println("Bien joué mais raté");
	cpt = 0;
      }
      break; 
    }
    
  }
}

int test() {
  if ((time2 - time1) > TCOMB) {
    if (val == code[cpt]) {
      cpt ++;
      time1 = millis();
      return 1;
    }
    else {
      Serial.println("mauvaise entrée, veuillez recommencer");
      cpt == 0;
      time2 = millis();
      return 0;
    }
  } 
}
