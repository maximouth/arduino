//bancher un bouton, une pin sur GND une sur 13.


const int entre_ils = 2;
const int led = 13;

unsigned long time1 = 0;
unsigned long time2;
int nb_tour = 0;
unsigned long total = 0;
int val = 1;

void setup() {
 Serial.begin(9600);
 
 pinMode (entre_ils, INPUT_PULLUP);
 pinMode (led, OUTPUT);
 Serial.println("debut test");
 digitalWrite(2,LOW);
}


void loop() {
  //s'éteind si la l'aimant devant l'ILS
   digitalWrite(led, digitalRead(entre_ils)); 
   Serial.println(val);
    while (val == 1) {
    val = digitalRead(13);
    }
   //if (val == LOW) { 
      time2 = millis();
      total = time2 - time1;
      nb_tour++;
      Serial.print("nombre de tour : ");
      Serial.println(nb_tour); 
      Serial.print("total   : ");
      Serial.println(total);
      
 //}

  if ( total > 5000 ) {
    Serial.print("tours/5seconde : ");
    Serial.println(nb_tour);
    total = 0;
    nb_tour = 0;
    time1 = millis();
    delay(1000);
  }

val = 1;
}
