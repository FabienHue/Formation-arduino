#include "dht.h"

int pin = 2; //Capteur connecté à la broche digitale 2

dht DHT;

void setup() {
  Serial.begin(9600);
}

void loop() {
  DHT.read22(pin);
  Serial.print(DHT.temperature);//Afficher la température
  Serial.print(" ");
  Serial.println(DHT.humidity); //Afficher l'humidité
  delay(250); //4 mesures par seconde max
}
