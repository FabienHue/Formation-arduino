#include <SD.h>                                                                           
#include <SPI.h>
File fichier;
int pinCS = 4;

void setup() {
  Serial.begin(9600);
  pinMode(pinCS, OUTPUT);
  if (SD.begin())
  {
    Serial.println("Carte SD prête");
  } else
  {
    Serial.println("Erreur carte SD ");
    return;
  }
  fichier = SD.open("Journee.txt", FILE_WRITE);
  if (fichier) {
    Serial.println("Écriture du fichier...");
    fichier.println("Voici le premier fichier créé sur arduino");
    fichier.close();
    Serial.println("Fait");
  }
}
void loop() {
}
