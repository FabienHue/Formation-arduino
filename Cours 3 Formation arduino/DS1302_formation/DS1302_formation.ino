// DS1302:  RST pin    -> Arduino Digital 8
//          DATA pin   -> Arduino Digital 7
//          CLK pin  -> Arduino Digital 6
#include <DS1302.h>
DS1302 rtc(8, 7, 6);

void setup()
{
  rtc.halt(false);// Mettre l'horloge en fonctionnement
  rtc.writeProtect(false);// Désactiver la protection d'écriture
  Serial.begin(9600);
  //   Décommenter les lignes suivantes pour changer la date
  //rtc.setDOW(SUNDAY);        // Definir le Day-of-Week à SUNDAY
  //rtc.setTime(21, 9, 0);     // Definir l'heure 21:09:00 (format 24hr)
  //rtc.setDate(10, 01, 2020);   // Definir la date August 6th, 2010
}
void loop()
{ Serial.print(rtc.getTimeStr());// Afficher l'heure
  Serial.print("");
  Serial.print(rtc.getDOWStr(FORMAT_SHORT));// Afficher Day-of-Week
  Serial.print(",");
  Serial.println(rtc.getDateStr());// Afficher Date

  // Attendre une seconde avant de réafficher
  delay (1000);
}
