#include "LiquidCrystal.h" //ajout de la librairie

#define TCOMB 5000
// le code
int code[4];

// valeur du potentiomatre
int val = 0;
//temps pour determiner les differants changements
unsigned long time1 = 0;
unsigned long time2 = 0;

int cpt = 0;

//ecran LCD
LiquidCrystal lcd(1,3,5,6,7,8,9,10,11,12); //liaison 8 bits de données


void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);  
  lcd.print("entrez nv combinaison");
  delay(2000);
  time1 = millis();
}

void loop() {
  lcd.clear();
  val = map(analogRead(1),0,1023,0,9);
  lcd.setCursor(0,2);
  lcd.print(val);
  delay(1);
  time2 = millis();

  switch(cpt) {
  case 0:
    lcd.setCursor(0,0);  
    lcd.print("1er chiffre");
    break;
  case 1:
    lcd.setCursor(0,0);  
    lcd.print("2eme chiffre");
    lcd.setCursor(4,1);
    lcd.print(code[0]);
    break;
  case 2:
    lcd.setCursor(0,0);  
    lcd.print("3eme chiffre");
    lcd.setCursor(4,1);
    lcd.print(code[0]);
    lcd.setCursor(6,1);
    lcd.print(code[1]);
    break;
  case 3:
    lcd.setCursor(0,0);  
    lcd.print("4eme chiffre");
    break;
    lcd.setCursor(4,1);
    lcd.print(code[0]);
    lcd.setCursor(6,1);
    lcd.print(code[1]);
    lcd.setCursor(8,1);
    lcd.print(code[2]);
     case 4:
    lcd.setCursor(0,0);
    lcd.print("nouveau");
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
  
  if (((time2-time1) > TCOMB) && (cpt < 4)) {
    code[cpt] = val;
    cpt++;
    time1 = millis();
  }
  
  
  
}
