#include <IRremote.h>

const char RECEPTEUR_INFRAROUGE = 6;

IRrecv monRecepteurInfraRouge (RECEPTEUR_INFRAROUGE);

decode_results messageRecu;

void setup()
{
  Serial.begin(9600);
  monRecepteurInfraRouge.enableIRIn();
  monRecepteurInfraRouge.blink13(true);
}

void loop()
{
  if (monRecepteurInfraRouge.decode(&messageRecu))
  {
    Serial.println(messageRecu.value, HEX);
    delay(100);
    monRecepteurInfraRouge.resume();
  }
}


œ
