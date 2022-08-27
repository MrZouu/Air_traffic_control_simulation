#ifndef MONDE_H_INCLUDED
#define MONDE_H_INCLUDED
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Sommet.h"
#include "Arrete.h"
#include "Avion.h"


class Monde
{
private:
    std::vector <Sommet*> sommets;
    std::vector <Arrete*> arretes;
    std::vector <Avion*> avions;
public:
    void ajouterSommet (int id, std::string nom, int GPS, int nbPistes, int nbPlaces, int TpsAttenteSol, int TpsAccesPiste, int TpsDecAt, int DelaiCol, int TpsBoucleAtt);
    void ajouterArrete(int id,std::string nom, int depart2, int arrivee2,int distance);
    void ajouterAvion(int id, std::string modele, std::string type, int consommation, int capacite, int x, int y);
    void afficherArretes(int ar, int point);
    void afficherAvions();
    void afficherSommets();
    void dijkstra (int debut, int fin);
    void trier();
    void kruskal();
    std::vector<std::pair<int, Sommet*>>getSuccesseurs(int s);
    Arrete* getArrete(int depart, int arrivee);
    Sommet* getSommet(int id);
    std::vector<Arrete*> getArretes();
    Avion* getAvion(int id);
    std::vector<Sommet*>getSommets();
};

#endif // MONDE_H_INCLUDED
