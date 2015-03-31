//bancher un bouton, une pin sur GND une sur 13.

const int entre_ils = 1;
const int led = 3;

int etat = 0;
unsigned long time1 = 0;
unsigned long time2;

int cpt = 0;

void setup() {
  Serial.begin(9600);
  pinMode (entre_ils, INPUT_PULLUP);
  attachInterrupt (0, compte, FALLING);
  pinMode (led, OUTPUT);
  Serial.println("debut jeu\n serez vous assez rapide?");
}

void loop() {
  
  if (etat == 0) {
    delay (random(350,3500));
    digitalWrite(led,HIGH);
    time1 = millis();
    etat = 1;
  }
  
}

void compte() {
    if (etat == 1) {
      time2 = millis();
      digitalWrite(led, LOW);
      cpt = time2 - time1;
      Serial.print("Vous avez mis : "); 
      Serial.print(cpt);
      Serial.println (" ms");
      etat = 0; 
      
    }
    else {
     Serial.println("trop tot raté"); 
    }
}

