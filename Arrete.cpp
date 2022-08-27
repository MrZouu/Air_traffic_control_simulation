#include <iostream>
#include<iomanip>
#include "Arrete.h"

int Arrete::getId()
{
    return id;
}
Sommet* Arrete::getDepart()
{
    return depart2;
}
Sommet* Arrete::getArrivee()
{
    return arrivee2;
}

void Arrete::afficher()
{   //On affiche les arretes et leurs caracteristiques
    std::cout << std::setw(6)<< id<< std::setw(20)<< nom << std::setw(20) << depart2->getId() <<std::setw(20) << arrivee2->getId() <<std::setw(20) << distance<< std::endl;
}

//renvoi une string representant un trajet
std::string Arrete::toString()
{
    std::stringstream ss;
    ss << std::setw(6)<< id << std::setw(20)<< nom<< std::setw(20) << depart2->getId() <<std::setw(20) << arrivee2->getId() <<std::setw(20) << distance<< std::endl;
    return ss.str();
}
