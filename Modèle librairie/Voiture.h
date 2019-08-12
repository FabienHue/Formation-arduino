#ifndef Voiture_h
#define Voiture_h

#include "Arduino.h"

class Voiture
{
  public:
    Voiture(String nomvoiture, String couleurvoiture, int vit);
    void Allumer();
    void Eteindre();
    void setVitesse(float vit);
    void setCouleur(String couleurvoiture);
    void setNom(String nomvoiture);
    String getNom();
    int getAnnee();
    float getVitesse();
  private:
    String Nom;
    int Annee;
    String Couleur;
    boolean Allumage;
    float Vitesse;
};
#endif




