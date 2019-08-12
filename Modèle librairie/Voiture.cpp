#include "Arduino.h"
#include "Voiture.h"

Voiture::Voiture(String nomvoiture, String couleurvoiture, int vit){
  Nom = nomvoiture;
  Couleur = couleurvoiture;
  Vitesse = vit;
}

void Voiture::setVitesse(float vit){
  Vitesse = vit;
}

void Voiture::setCouleur(String couleur){
  Couleur = couleur;
}

void Voiture::setNom(String nomvoiture){
  Nom = nomvoiture;
}

String Voiture::getNom(){
  return Nom;
}

float Voiture::getVitesse(){
  return Vitesse;
}


