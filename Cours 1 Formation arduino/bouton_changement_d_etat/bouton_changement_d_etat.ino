int led = 13;
int bouton = 7;
boolean etat = HIGH;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(bouton, INPUT_PULLUP);
}

void loop() {
  digitalWrite(led,etat); 
  
  if (digitalRead(bouton) == HIGH) {    //Si le bouton est appuyé
    etat = !etat; //Etat est égal à l'inverse de état
    delay(250); //Laisse le temps à l'utilisateur de retirer son doigt
  }
}
