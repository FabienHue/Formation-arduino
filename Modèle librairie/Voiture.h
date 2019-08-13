#ifndef NomLibrairie_h
#define NomLibrairie_h

#include "Arduino.h"

class NomLibrairie
{
  public:
    NomLibrairie(boolean argument1, int argument2);
    void Methode1();
    float Methode2(String argument3);
  private:
    boolean attribut1;
    int attribut2;
    String attribut3;
};
#endif




