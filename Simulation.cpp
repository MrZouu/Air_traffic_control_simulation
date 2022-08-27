#include "Simulation.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

Simulation::Simulation()
{
    ///remplir les aeroports avec des avions (aleatoirement/fichier de conf
    ///remplir les places libres
    /*for(int i=0; i<7; i++)
    {
        int places =0;
        int remplissage =0;
        Sommet* aeroport;
        aeroport = monde.getSommet(i);
        places = aeroport->nbPlacesDispo;
        int alea = rand()%places +1;
        std::cout << alea << std::endl;
        remplissage = places-alea;
    }*/

}

void Simulation::manageFlyingPlane(Avion *avion)
{
    if(avion->getX())///si coord idem que aeroport d'arrivee alors ajout fileAtt atterr x passer statut a atter
        return;///sinon le faire avancer vers aeroport de destination
}

void Simulation:: gererAtter()
{
    for(int i=0; i<7; i++)
    {
        // monde.getSommet(i);///mettre a jour file attente (si place dispo sors de la file d'att) et places (atteri direct)
    }
}

void Simulation:: gererDecol()
{
    std::default_random_engine re(time(0));

    for(int i=0; i<7; i++)
    {
        ///fonction de decision, avions dispo ds aero en statio, nb piste dispo, generer destination
        int places =0;
        int remplissage =0;
        int alea = 0;
        Sommet* aeroport;
        aeroport = monde.getSommet(i);
        places = aeroport->nbPlacesDispo;
        std::uniform_int_distribution<int> distrib{1,places};
        alea = distrib(re);
        std::cout << "TEST" << std::endl;
        remplissage = places-alea;
    }

}



void Simulation::lancerSim()
{
    int ut=0;
    while(1)
    {
        for(auto a: avions)
        {
            if(a->statut==EN_VOL)
            {
                manageFlyingPlane(a);
            }
            else if(a->statut==ATTER)
            {
                a->statut=STATIO;
                a->aeroActuel->nbPistesDispo++;
                a->aeroActuel->nbPlacesDispo--;
            }
            else if(a->statut==DECOL)
            {
                a->statut=EN_VOL;
                // nbPistesdispo++
            }
        }

        gererAtter();
        gererDecol();

        ut++;
    }
}
