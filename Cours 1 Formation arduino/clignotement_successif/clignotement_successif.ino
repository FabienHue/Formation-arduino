int ledR = 13;
int ledJ = 12;
int ledV = 11;

int temps = 1000;

void setup() {
  pinMode(ledR,OUTPUT);
  pinMode(ledJ,OUTPUT);
  pinMode(ledV,OUTPUT);
}

void loop() {
  //On allume le 1ere
  digitalWrite(ledR,HIGH);
  digitalWrite(ledJ,LOW);
  digitalWrite(ledV,LOW);
  delay(temps); // On attend
  //On allume la 2nd
  digitalWrite(ledR,LOW);
  digitalWrite(ledJ,HIGH);
  digitalWrite(ledV,LOW);
  delay(temps); //On attend
  //On allume la 3eme
  digitalWrite(ledR,LOW);
  digitalWrite(ledJ,LOW);
  digitalWrite(ledV,HIGH);
  delay(temps); //On attend
}
