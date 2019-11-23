int led = 13;
int bouton = 7;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(bouton, INPUT_PULLUP);
}

void loop() {
  
  if (digitalRead(bouton) == HIGH) {    //Si le bouton est appuyé
    digitalWrite(led, HIGH);
  } else {  //Sinon (tous les autres cas)
    digitalWrite(led,LOW); 
  }
}
