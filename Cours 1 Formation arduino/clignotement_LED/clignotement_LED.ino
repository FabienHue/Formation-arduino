int led = 13;    //On stock le pin de la led
int temps = 500; //On stock le temps


void setup() {
  pinMode(led,OUTPUT); //On déclare comme sortie
}

void loop() {
  digitalWrite(led,HIGH); // On allume
  delay(temps); //On attend
  digitalWrite(led,LOW); // On eteint
  delay(temps);//On attend
}
