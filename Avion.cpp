#include <iostream>
#include <iomanip>
#include "Avion.h"

void Avion::afficher()
{   //On affiche les avions et leurs caracteristiques
    std::cout << std::setw(6)<< id << std::setw(15) << modele <<std::setw(15)<< type <<std::setw(15)<<consommation<<std::setw(15)<<capacite<<std::setw(15)<< x<<std::setw(15)<< y<<std::endl; //aligner le texte
}

int Avion:: getId()
{
    return id;
}


//renvoi une string representant un point
std::string Avion::toString()
{
    std::stringstream ss;
    ss << std::setw(6)<< id << std::setw(15) << modele <<std::setw(15)<< type <<std::setw(15)<<consommation<<std::setw(15)<<capacite<<std::setw(15)<< x<<std::setw(15)<< y<<std::endl; //aligner le texte
    return ss.str();
}
