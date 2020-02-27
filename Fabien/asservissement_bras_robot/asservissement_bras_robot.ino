const int potBase = A0;
const int potcom = A1;

const int c1 = 7;
const int c2 = 8;
const int vit = 9;

int commande = 800;
int a = 120;
int b = 20;
int pos;
int dep = 100;

void setup() {
  Serial.begin(9600);
  pinMode(c1, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(vit, OUTPUT);
}

void loop() {
  commande = analogRead(potcom);
  pos = analogRead(potBase);
  pos = map(pos, 73, 910, 0, 1024);
  Serial.println(pos);
  if (pos < commande - a) {
    digitalWrite(c1, HIGH);
    digitalWrite(c2, LOW);
    analogWrite(vit, 255);
  }
  if (pos > commande + a) {
    digitalWrite(c1, LOW);
    digitalWrite(c2, HIGH);
    analogWrite(vit, 255);
  }
  if ((pos > commande - a) && (pos < commande)) {
    digitalWrite(c1, HIGH);
    digitalWrite(c2, LOW);
    analogWrite(vit, ((-255/a)*(pos-b) + (255/a)*commande));
  }
  if ((pos < commande + a) &&(pos > commande)) {
    digitalWrite(c1, LOW);
    digitalWrite(c2, HIGH);
    analogWrite(vit, ((-255/a)*(pos-b) + (255/a)*commande));
  }

}
