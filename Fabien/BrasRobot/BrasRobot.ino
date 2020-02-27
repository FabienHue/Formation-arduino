const int potBase = A0;
const int potcom = A1;

//moteur 1
const int c11 = 2;
const int c21 = 4;
const int vit1 = 3;
int commande1 = 800;
int a1 = 120;
int b1 = 20;
int pos1;
int dep1 = 100;
const int pot1 = A0;//asservissement
const int potcom1 = A1;//commande



//moteur 2
const int c12 = 6;
const int c22 = 7;
const int vit2 = 5;
int commande2 = 800;
int a2 = 120;
int b2 = 20;
int pos2;
int dep2 = 100;
const int pot2 = A2;//asservissement
const int potcom2 = A3;//commande


//moteur 3
const int c13 = 7;
const int c23 = 8;
const int vit3 = 9;
int commande3 = 800;
int a3 = 120;
int b3 = 20;
int pos3;
int dep3 = 100;
const int pot3 = A4;//asservissement
const int potcom3 = A5;//commande

//Pince
const int c1p = 12;
const int c2p = 11;
const int vitp = 10;
boolean etat = false; //False = ouvert true = fermé
const int btpince = 13;


void setup() {
  Serial.begin(9600);
  pinMode(c11, OUTPUT);
  pinMode(c21, OUTPUT);
  pinMode(vit1, OUTPUT);
  pinMode(c12, OUTPUT);
  pinMode(c22, OUTPUT);
  pinMode(vit2, OUTPUT);
  pinMode(c13, OUTPUT);
  pinMode(c23, OUTPUT);
  pinMode(vit3, OUTPUT);
  pinMode(btpince, OUTPUT);
}

void loop() {
  commande1 = analogRead(potcom1);
  pos1 = analogRead(pot1);
  pos1 = map(pos1, 0, 456, 0, 1024);
  goTo(commande1, 1, a1, b1, pos1);

  commande2 = analogRead(potcom2);
  pos2 = analogRead(pot2);
  pos2 = map(pos1, 73, 910, 0, 1024);
  goTo(commande2, 2, a2, b2, pos2);

  commande3 = analogRead(potcom3);
  pos3 = analogRead(pot3);
  pos3 = map(pos3, 33, 860, 0, 1024);
  goTo(commande3, 3, a3, b3, pos3);


}
void goTo(int COMMANDE, int MOTEUR, int A, int B, int POS) {
  if (MOTEUR == 1) {
    if (POS < COMMANDE - A) {
      digitalWrite(c11, HIGH);
      digitalWrite(c21, LOW);
      analogWrite(vit1, 255);
    }
    if (POS > COMMANDE + A) {
      digitalWrite(c11, LOW);
      digitalWrite(c21, HIGH);
      analogWrite(vit1, 255);
    }
    if ((POS > COMMANDE - A) && (POS < COMMANDE)) {
      digitalWrite(c11, HIGH);
      digitalWrite(c21, LOW);
      analogWrite(vit1, ((-255 / A) * (POS - B) + (255 / A)*COMMANDE));
    }
    if ((POS < COMMANDE + A) && (POS > COMMANDE)) {
      digitalWrite(c11, LOW);
      digitalWrite(c21, HIGH);
      analogWrite(vit1, ((-255 / A) * (POS - B) + (255 / A)*COMMANDE));
    }
  }
  if (MOTEUR == 3) {
    if (POS < COMMANDE - A) {
      digitalWrite(c12, HIGH);
      digitalWrite(c22, LOW);
      analogWrite(vit2, 255);
    }
    if (POS > COMMANDE + A) {
      digitalWrite(c12, LOW);
      digitalWrite(c22, HIGH);
      analogWrite(vit2, 255);
    }
    if ((POS > COMMANDE - A) && (POS < COMMANDE)) {
      digitalWrite(c12, HIGH);
      digitalWrite(c22, LOW);
      analogWrite(vit2, ((-255 / A) * (POS - B) + (255 / A)*COMMANDE));
    }
    if ((POS < COMMANDE + A) && (POS > COMMANDE)) {
      digitalWrite(c12, LOW);
      digitalWrite(c22, HIGH);
      analogWrite(vit2, ((-255 / A) * (POS - B) + (255 / A)*COMMANDE));
    }
  }
  if (MOTEUR == 3) {
    if (POS < COMMANDE - A) {
      digitalWrite(c13, HIGH);
      digitalWrite(c23, LOW);
      analogWrite(vit3, 255);
    }
    if (POS > COMMANDE + A) {
      digitalWrite(c13, LOW);
      digitalWrite(c23, HIGH);
      analogWrite(vit3, 255);
    }
    if ((POS > COMMANDE - A) && (POS < COMMANDE)) {
      digitalWrite(c13, HIGH);
      digitalWrite(c23, LOW);
      analogWrite(vit3, ((-255 / A) * (POS - B) + (255 / A)*COMMANDE));
    }
    if ((POS < COMMANDE + A) && (POS > COMMANDE)) {
      digitalWrite(c13, LOW);
      digitalWrite(c23, HIGH);
      analogWrite(vit3, ((-255 / A) * (POS - B) + (255 / A)*COMMANDE));
    }
  }
}
