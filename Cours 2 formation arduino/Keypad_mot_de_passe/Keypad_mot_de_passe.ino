#include <Keypad.h>

const byte lignes = 4; //4 lignes
const byte colonnes = 4; //4 colonnes

//Définir les symboles par lignes et colonnes
char touches[lignes][colonnes] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pinsLignes[lignes] = {9, 8, 7, 6}; //Pins auquels sont connectés les lignes
byte pinsColonnes[colonnes] = {5, 4, 3, 2}; //Pins auquels sont connectés les colonnes

//initialisation d'un keypad
Keypad monKeypad = Keypad(makeKeymap(touches), pinsLignes , pinsColonnes, lignes, colonnes);

/************************************************************************/

String essai;  //Ce qu'on va taper
String MDP = "1234"; // Le mot de passe

int led = 12;
boolean etat = LOW; //État de la led

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  digitalWrite(led,etat);
  
  char appui = monKeypad.getKey(); //On stock ce qui est appuyé

  if (appui) {

    essai = essai + appui; // On ajoute le caractère appuyé à notre essai

    if (appui == 'C') { // Si on tape C, on supprime notre essai
      essai = "";
    }

    if (essai == MDP) { //Si c'est le bon MDP
      Serial.println("Bon MDP");
      etat = !etat; //On change l'état de la led
      essai = ""; // On supprime notre essai
    }

    Serial.println(essai); // On affiche notre essai
  }
}
