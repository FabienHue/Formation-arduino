#include "Arduino.h"
#include "NomLibrairie.h"

NomLibrairie::NomLibrairie(boolean argument1, int argument2){
  Attribut1 = argument1;
  Attribut2 = argument2;
}

void NomLibrairie::Methode1(){
  Serial.println("Methode1");
}

float NomLibrairie::Methode2(String argument3){
  Attribut3 = argument3;
  return 5;
}


