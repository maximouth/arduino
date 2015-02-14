#include "LiquidCrystal.h" //ajout de la librairie

//temps max avant remise a 0
#define TMAX 10000
//temps pour rentrer un chiffre
#define TCOMB 5000

//alimentation du potentiometre
const int pot = 6;
const int ledV = 2;
const int ledR = 4;

//ecran LCD
LiquidCrystal lcd(1,3,5,6,7,8,9,10,11,12); //liaison 8 bits de données

//potentiometre branché sur ax analog


// les 4 valeurs du coffres
int code[4] = {2,7,4,8};

//connaitre la position dans l'automate
int cpt = 0;
// valeur du potentiomatre
int val = 0;
//temps pour determiner les differants changements
unsigned long time1 = 0;
unsigned long time2 = 0;


void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  //  digitalWrite(pot,HIGH);
  time1 = millis();
  digitalWrite(ledR,HIGH);
  digitalWrite(ledV,LOW);
  
}

void loop() {
  lcd.clear();
  val = map(analogRead(1),0,1023,0,9);
  time2 = millis();
  lcd.setCursor(0,2);
  lcd.print(val);
  delay(1);


  switch(cpt) {
  case 0:
    lcd.setCursor(0,0);
    lcd.print("premier chiffre?");
    break;
  case 1:
    lcd.setCursor(0,0);
    lcd.print("second?");
    lcd.setCursor(4,1);
    lcd.print(code[0]);
    break;
  case 2:
    lcd.setCursor(0,0);
    lcd.print("3eme?");
    lcd.setCursor(4,1);
    lcd.print(code[0]);
    lcd.setCursor(6,1);
    lcd.print(code[1]);
    break;
  case 3:
    lcd.setCursor(0,0);
    lcd.print("dernier?");
    lcd.setCursor(4,1);
    lcd.print(code[0]);
    lcd.setCursor(6,1);
    lcd.print(code[1]);
    lcd.setCursor(8,1);
    lcd.print(code[2]);
    break;

  case 4:
    lcd.setCursor(0,0);
    lcd.print("ouvert!!");
    lcd.setCursor(0,1);
    lcd.print("code:");
    lcd.setCursor(6,1);
    lcd.print(code[0]);
    lcd.setCursor(8,1);
    lcd.print(code[1]);
    lcd.setCursor(10,1);
    lcd.print(code[2]);
    lcd.setCursor(12,1);
    lcd.print(code[3]);
    
    break;
  }

  if ((time2-time1) > TCOMB) {
      switch (cpt) {
	//premier chiffre
      case 0:
	/* lcd.setCursor(0,0); */
	/* lcd.clear(); */
	/* lcd.print("1er chiffre?"); */
	//Serial.println("entrez premier chiffre :");
	test();
	break;
	
	//second
      case 1 :
	lcd.setCursor(0,0);
	lcd.print("second?");
	//	Serial.println("entrez second chiffre :");
	test();
	break;
	
	//3eme
      case 2 :
	/* lcd.setCursor(0,0); */
	/* lcd.print("3 eme?"); */
	//	Serial.println("entrez 3eme chiffre :");
	test();
	break;
	
	//dernier
      case 3 :
	//tester si bon et ouvrir
	if (test() == 1 ) {
	  lcd.print("bien joue");
	  cpt = 4;
	  //allumer led verte /eteindre la rouge
	  digitalWrite(ledV,HIGH);
	  digitalWrite(ledR,LOW);
	}
	else {
	  /* lcd.setCursor(0,0); */
	  /* lcd.print("rate!"); */
	  //Serial.println("Bien joué mais raté");
	  cpt = 0;
	}
	break; 
      }
    }
  
  delay(50);
}

int test() {  
  if (val == code[cpt]) {
    cpt ++;
    time1 = millis();
    return 1;
  }
  else {
    //Serial.println("mauvaise entrée, veuillez recommencer");
    lcd.setCursor(0,0);
    lcd.print("mauvaise entree");
    delay(500);
    cpt = 0;
    time1 = millis();
    //return 0;
  }
} 

