#ifndef ARRETE_H_INCLUDED
#define ARRETE_H_INCLUDED
#include "Sommet.h"

class Arrete
{

private :
    int id;
    std::string nom;
    Sommet* depart2;
    Sommet* arrivee2;
    int distance;
public:
    Arrete(int id,std::string nom,  Sommet* depart2, Sommet* arrivee2,int distance ):
        id(id),nom(nom),depart2(depart2), arrivee2(arrivee2), distance(distance) {};
    void afficher();
    int getId();
    int getDistance()
    {
        return distance;
    }
    Sommet* getDepart();
    Sommet* getArrivee();
    std::string toString();


};


#endif // ARRETE_H_INCLUDED
