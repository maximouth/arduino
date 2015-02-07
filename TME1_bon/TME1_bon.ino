#define MAX_PILE 30

int top;
int pile[MAX_PILE];

void push (int n) 
{
  if (top == MAX_PILE) {
   Serial.println("ERREUR Pile pleine");
   delay(1000);
   exit(0);
  }
  else {
   pile[top++] = n; 
  }
}

int pop () {
 int ret = 0;
  if (top == 0) {
   Serial.println("ERREUR pile vide");
   delay(1000);
   exit(0);
 }
  else {
    ret = pile[--top];
    return ret;
  }
}

int empty() {
 return (top == 0);
}

void reset_pile() {
  top= 0;
}

void setup() 
{
  Serial.begin(9600);
  Serial.println("initialisation terminee");
}


void loop() {
  int op1, op2;
  
  while (!Serial.available());
  char c = Serial.read();
  Serial.print((char)toupper(c));
  
  switch(c) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      push(c-'0');
      break;
      
    case '+':
        op2 = pop();
        op1 = pop();
        push(op1+op2);
        break;
      case '-'  :
        op2 = pop();
        op1 = pop();
        push(op1-op2);
        break;
      case '*':
        op2 = pop();
        op1 = pop();
        push(op1*op2);
        break;
      case '/':
        op2 = pop();
        op1 = pop();
        push(op1/op2);
        break;
        
      case '=':
        op1 = pop();
        if(empty()) {
          Serial.println(op1);
        }
        else {
          Serial.println("Erreur expression incorrecte.");
          delay(1000);
          reset_pile();
        }
        break;
        
      case ' ':
      case '\n':
        break;
        
      default:
//        Serial.print("Caractere : ");
//        Serial.println(c);
        Serial.println("Erreur caractere incorrect.");
        delay(1000);
        exit(0);
        break;
    }
//  }
}
  

