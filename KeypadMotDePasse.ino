#include <Keypad.h>

const int lignes = 4; //4 lignes
const int colonnes = 4; //4 colonnes

char Touches[lignes][colonnes] = {
  {'1', '2', '3', 'A'},                                                                                   
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte PinsLignes[lignes] = {9, 8, 7, 6}; 
byte PinsColonnes[colonnes] = {5, 4, 3, 2};

//Déclaration du keypad
Keypad MonKeypad = Keypad(makeKeymap(Touches), PinsLignes, PinsColonnes, lignes, colonnes);

String MDP = "123A";
String tape;

boolean verrouillage = false; //false = verrouillé; true = déverrouillé
const int led = 10;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  char appui = MonKeypad.getKey();
  if (appui) {
    if (appui == 'D') {
      if (tape == MDP) {
        Serial.println("Bon mot de passe");
        verrouillage = !verrouillage;
      } else {
        Serial.println("Mauvais mot de passe");
      }
      tape = "";
    }
    if (appui == 'C') {
      Serial.println("Supprime");
      tape = "";
    }
    if (appui != 'C' && appui != 'D') {
      tape += appui;
    }
    if (tape != "") {
      Serial.print("Tapé : ");
      Serial.println(tape);
    }
  }
  digitalWrite(led, verrouillage);
}
