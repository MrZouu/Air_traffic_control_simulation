#include <iostream>
#include <fstream>
#include<iomanip>
#include <utility>
#include<queue>
#include <map>
#include "monde.h"
#include "Arrete.h"
//Sommets
//Cette fonction Ajoute des sommets dans la liste des sommets
void Monde::ajouterSommet(int id, std::string nom, int GPS, int nbPistes, int nbPlaces, int TpsAttenteSol, int TpsAccesPiste, int TpsDecAt, int DelaiCol, int TpsBoucleAtt)
{
    sommets.push_back(new Sommet(id, nom, GPS, nbPistes, nbPlaces,  TpsAttenteSol, TpsAccesPiste, TpsDecAt, DelaiCol, TpsBoucleAtt));
}

//Cette fonction permet d'afficher des sommets dans la liste des sommets
void Monde::afficherSommets()
{
    std::cout<< std::endl<<"Aeroports :"<<std::endl;
    std::cout<<std::endl<<std::setw(6) <<"Numero" << std::setw(15)<< "Nom"<<std::setw(15)<<"GPS"<<std::setw(15)<<"nbPistes"<<std::setw(15)<<"nbPlacesSol"<<std::setw(15)<<"AttenteSol"<<std::setw(15)<<"TpsAccesPiste"<<std::setw(15)<<"TpsAtt/Decol"<<std::setw(15)<<"DelaiAnticol"<<std::setw(15)<<"TpsBoucle"<<std::endl;
    for (auto s=sommets.begin(); s!=sommets.end(); s++)
    {
        (*s)->afficher();
    }
    std::cout<<std::endl;
}

Sommet* Monde::getSommet(int id)
{
    for (auto s=sommets.begin(); s!=sommets.end(); s++)
    {
        if ((*s)->getId()==id)
        {
            return(*s);
        }
    }
    return NULL;
}

std::vector<Sommet*> Monde::getSommets()
{
    return sommets;
}
//Cette fonction Ajoute des arretes dans la liste des arretes
void Monde::ajouterArrete(int id,std::string nom,int depart2,int arrivee2,int distance)
{
    /*std::cout << " 1 - Avion court-courrier (5000Km)" << std::endl;
    std::cout << " 2 - Avion moyen-courrier (6000Km)" << std::endl;
    std::cout << " 3 - Avion long-courrier (7000Km)" << std::endl;
    std::cout << std::endl << "Avion : ";
    int ID;
    std::cin >> ID;*/

    Sommet* d=getSommet(depart2);
    Sommet* a=getSommet(arrivee2);
    if (d==NULL)
    {
        throw std::runtime_error("Sommet depart inconnu");
    }
    if (a==NULL)
    {
        throw std::runtime_error("Sommet arrivee inconnu");
    }
    arretes.push_back(new Arrete(id,nom,d, a,distance));
    /*
    for(int i=0;i<30;i++)
    {
         if(ID==1&&i<14) //Selon le type d'avion, on va remplir plus ou moins les arretes du fichier afin d'avoir seulement les trajets faisables par l'avion en question
         {
             arretes.push_back(new Arrete(id,nom,d, a,distance));
         }
         if(ID==2&&i<24)
         {
             arretes.push_back(new Arrete(id,nom,d, a,distance));
         }
         if(ID==3&&i<30)
         {
             arretes.push_back(new Arrete(id,nom,d, a,distance));
         }
    }*/
}

//Cette fonction permet d'afficher des arretes dans la liste des arretes
void Monde::afficherArretes(int ar, int point)
{
    std::cout<<std::endl<<"arretes : "<<std::endl;
    std::cout<<std::endl<<std::setw(6) <<"Numero" <<std::setw(20)<<"Nom"<< std::setw(20)<< "Depart"<<std::setw(20)<<"Arrivee"<<std::setw(21)<< "Distance(Km)"<<std::endl;

    for (auto a=arretes.begin(); a!=arretes.end(); a++)
    {
        if ((ar==-1 && point==-1) || ar==(*a)->getId() || (*a)->getDepart()->getId()==point || (*a)->getArrivee()->getId()==point )
        {
            (*a)->afficher();
        }
    }
    std::cout<<std::endl;
}

Arrete* Monde::getArrete(int depart, int arrivee)
{
    Arrete*result;
    for(Arrete*a : arretes) //recup toutes les arretes dun point de depart
    {
        if (a-> getDepart()-> getId()==depart && a-> getArrivee()-> getId()==arrivee)
        {
            result=a;
        }
    }
    return result;
}


std::vector<Arrete*> Monde::getArretes()
{
    return arretes;
}
Avion* Monde::getAvion(int id)
{
    for (auto s=avions.begin(); s!=avions.end(); s++)
    {
        if ((*s)->getId()==id)
        {
            return(*s);
        }
    }
    return NULL;
}
//Cette fonction Ajoute des avions dans la liste des avions
void Monde::ajouterAvion(int id, std::string modele, std::string type, int consommation, int capacite, int x, int y)
{
    avions.push_back(new Avion(id, modele, type, consommation, capacite,  x, y));
}
//Cette fonction permet d'afficher des avions dans la liste des avions
void Monde::afficherAvions()
{
    std::cout<<std::endl<<"Avions :"<<std::endl;
    std::cout <<std::endl<< std::setw(6)<< "Numero " << std::setw(15) << "modele" <<std::setw(15)<< "type" <<std::setw(15)<<"consommation"<<std::setw(15)<<"capacite"<<std::setw(14)<< "x"<<std::setw(15)<< "y" <<std::endl;
    for (auto s=avions.begin(); s!=avions.end(); s++)
    {
        (*s)->afficher();
    }
    std::cout<<std::endl;
}

std::vector<std::pair<int, Sommet*>> Monde :: getSuccesseurs(int s)
{
    std::vector<std::pair<int, Sommet*>> successeurs;
    for(auto a: arretes)
    {
        if (a->getDepart()->getId() ==s)
        {
            successeurs.push_back(std::make_pair(a->getDistance(),a->getArrivee()));
            //std::cout<<a->getDepart()->getId()<< ":" <<a->getDistance()<< ":" << a->getArrivee()->getId()<<std::endl;
        }
    }
    return successeurs;
}

typedef std::pair <int, Sommet*> pi;   /// Source internet
void Monde::dijkstra (int debut, int fin)
{
    //Dijkstra
    std::priority_queue <pi, std::vector<pi>, std::greater <pi> > file;    ///  Source internet
    for(auto s : sommets)
    {
        s->reset();
    }
    Sommet*s = sommets[debut-1];
    s->setDistance(0);
    int lafin = 0;
    while(lafin == 0)
    {
        for (auto o : getSuccesseurs(s->getId()))
        {
            int farfrom;
            farfrom = s->getDistance() + o.first;// la distance totale farfrom egal à la distance pour arriver au predec plus la distance entre le predec et celui ou on est

            if(farfrom < o.second->getDistance())
            {
                o.second->setDistance(farfrom);
                o.second->setAntecedent(s);
                file.push(std::make_pair(farfrom, o.second)); /// pair de distance et du sommet en question
            }

        }
        s = file.top().second; /// On place notre sommet actuel en haut de la file
        file.pop();
        lafin = 1;
        for(unsigned int i = 0; i<sommets.size(); i++)
        {
            lafin = 0;
            if (file.size()==0)
            {
                lafin=1;
            }
        }

    }
    ///Affichage suite au calcul de l'algo
    std::cout<<"Le chemin le plus court entre "<<debut<<" et "<<fin<<" est : ";
    Sommet* sommetActuel = sommets[fin-1];
    int distanceTot=0;
    int compteur=0;

    while(sommetActuel !=sommets[debut-1])
    {
        if(compteur==0)     //Recuperer la distance totale
        {
            distanceTot=sommetActuel->getDistance();
            compteur++;
        }
        std::cout<<sommetActuel->getId();
        sommetActuel = sommetActuel->getAntecedent();
        std::cout<< "  <---  ";
    }
    std::cout<<debut<<std::endl;
    std::cout<<"Distance totale parcourue: "<<distanceTot<< " Km" << std::endl;
    if(distanceTot==0)  //Si la distance est de 0 c'est que debut et fin sont identiques
    {
        std::cout<<std::endl<<"Le point de depart est identique au point d'arrivee" <<std::endl;
    }
    std::cout<<std::endl;
}

///Kruskal
void Monde::trier()
{
    std::vector<Arrete*> tri;
    std::sort(tri.begin(), tri.end(), [] (Arrete* a, Arrete* b)   //tri avec sort
    {
        return a->getDistance() < b->getDistance();
    });
}

void Monde::kruskal()   //TP5
{
    //trier(); // On commence par trier les aretes par poids croissant
    int m_ordre = 8;
    std::vector<Arrete*> resultat;
    int numCC[sommets.size()]; // Liste pour éviter les boucles

    for (int i = 0; i < sommets.size(); i++)
    {
        numCC[i] = sommets[i]->getId();
    }

    int index = 0;
    while (resultat.size() < m_ordre - 1)   //ordre de 8
    {
        Arrete* a = arretes[index];

        int ia, ib;
        for (int i = 0; i < sommets.size(); i++)
        {
            if (sommets[i]->getId() == a->getDepart()->getId()) ia = i;
            if (sommets[i]->getId() == a->getArrivee()->getId()) ib = i;
        }

        if (numCC[ia] != numCC[ib])
        {
            resultat.push_back(a);

            int temp = numCC[ib];
            for (int i = 0; i < sommets.size(); i++)
            {
                if (numCC[i] == temp)
                    numCC[i] = numCC[ia];
            }
        }

        index++; //On incrémente index de 1 pour parcourir
    }

    int poids_total = 0; //Initialisation poids total à 0
    std::cout << "Liste des trajets de l'arbre couvrant :" << std::endl;
    for (int i = 0; i < resultat.size(); i++)
    {
        resultat[i]->afficher();
        poids_total += resultat[i]->getDistance(); //Le poids total sera la somme des poids de chaque aretes de l'arbre couvrant
    }
    std::cout << std::endl << "La distance minimale dans l'ensemble des aeroports est : " << poids_total << " Km" << std::endl;//Affichage du poids total
}
