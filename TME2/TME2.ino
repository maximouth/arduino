//bancher un bouton, une pin sur GND une sur 13.


const int entre_ils = 1;
const int led = 13;

unsigned long time1 = 0;
unsigned long time2;

int cpt = 0;
void setup() {
 Serial.begin(9600);
 
 pinMode (entre_ils, INPUT_PULLUP);
 attachInterrupt (0, compte, FALLING);
 pinMode (led, OUTPUT);
 Serial.println("debut test");
 time1 = millis();
}


void loop() {
  //s'éteint si la l'aimant devant l'ILS
   digitalWrite(led, digitalRead(entre_ils)); 
   time2 = millis();
  
   if ((time2 -time1) > 5000) {
     //Serial.print ("nombre tour/5sec : ");
     Serial.println(cpt);
     cpt = 0;
     time1 = millis();
   }
  

}

void compte() {
 Serial.println(cpt ++); 
 //delay(10);
}
