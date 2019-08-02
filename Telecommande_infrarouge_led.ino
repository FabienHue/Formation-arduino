#include <IRremote.h>

const char RECEPTEUR_INFRAROUGE = 6;

boolean ETAT = false;

const int LED = 10;

IRrecv monRecepteurInfraRouge (RECEPTEUR_INFRAROUGE);

decode_results messageRecu;

void setup()
{
  Serial.begin(9600);
  monRecepteurInfraRouge.enableIRIn();
  monRecepteurInfraRouge.blink13(true);
  pinMode(LED,OUTPUT);
}

void loop()
{
  if (monRecepteurInfraRouge.decode(&messageRecu))
  {
    Serial.println(messageRecu.value, HEX);
    if(messageRecu.value == 0x20DF22DD){
      ETAT = !ETAT;
    }
    delay(100);
    monRecepteurInfraRouge.resume();
  }
  delay(1);
  digitalWrite(LED,ETAT);
}
