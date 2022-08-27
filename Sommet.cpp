#include <iostream>
#include <iomanip>
#include "Sommet.h"


void Sommet::afficher()
{
    std::cout << std::setw(6)<< id << std::setw(15) << nom <<std::setw(15)<<GPS<<std::setw(15)<<nbPistes<<std::setw(15)<<nbPlaces<<std::setw(15)<< TpsAttenteSol<<std::setw(15)<< TpsAccesPiste<<std::setw(15)<<TpsDecAt<<std::setw(15)<<DelaiCol<<std::setw(15)<<TpsBoucleAtt<< std::endl; //aligner le texte
}

int Sommet:: getId()
{
    return id;
}

//renvoi une string representant un point
std::string Sommet::toString()
{
    std::stringstream ss;
    ss << std::setw(6)<< id << std::setw(15) << nom <<std::setw(15)<<GPS<<std::setw(15)<<nbPistes<<std::setw(15)<<nbPlaces<<std::setw(15)<< TpsAttenteSol<<std::setw(15)<< TpsAccesPiste<<std::setw(15)<<TpsDecAt<<std::setw(15)<<DelaiCol<<std::setw(15)<<TpsBoucleAtt<<std::endl; //aligner le texte
    return ss.str();
}
