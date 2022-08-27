#include <fstream>
#include <iostream>
#include "BorneInteractive.h"
#include "Simulation.h"
#include <cstdlib>
#include "IHM.h"
#include <limits>


void BorneInteractive::configurerSommets(std::ifstream &ifs, int nb_sommets)
{
    //On recupere les donnees sur les sommets stockés dans le fichier monde.txt
    int id, GPS, nbPistes, nbPlaces, TpsAttenteSol, TpsAccesPiste, TpsDecAt, DelaiCol, TpsBoucleAtt ;
    std::string nom;

    for (int i=0; i<nb_sommets; i++)
    {
        ifs >> id >> nom >> GPS >> nbPistes >> nbPlaces >> TpsAttenteSol >> TpsAccesPiste >> TpsDecAt >> DelaiCol >> TpsBoucleAtt;
        if (!ifs)
            throw std::runtime_error( "Sommet incorrect " );
        monde.ajouterSommet(id,nom, GPS, nbPistes, nbPlaces, TpsAttenteSol, TpsAccesPiste, TpsDecAt, DelaiCol, TpsBoucleAtt);
    }
}

void BorneInteractive::configurerArretes(std::ifstream &ifs, int nb_arretes)
{
    //On recupere les donnees sur les arretes stockés dans le fichier monde.txt
    //Il est possible de selectionner entre trois types d'avions

    int id,distance, depart2, arrivee2;
    std::string nom;
    for (int i=0; i<nb_arretes; i++)
    {
        ifs >> id >> nom >>depart2>>arrivee2>>distance;
        if (!ifs)
            throw std::runtime_error( "Arrete incorrecte " );

        monde.ajouterArrete( id,nom, depart2, arrivee2,distance);

    }
}


void BorneInteractive::configurerAvions(std::ifstream &ifs, int nb_avions)
{
    //On recupere les donnees sur les avions stockés dans le fichier monde.txt
    int id, consommation, capacite, x, y;
    std::string modele, type;

    for (int i=0; i<nb_avions; i++)
    {
        ifs >> id >> modele >> type >> consommation >> capacite >> x >> y;
        if (!ifs)
            throw std::runtime_error( "Avion incorrect " );
        monde.ajouterAvion(id, modele, type, consommation, capacite, x, y);
    }
}

void BorneInteractive::configurer(std::string fichier_config)
{
    //On ouvre le fichier et on va lire les données, lisant le nombre de sommets, d'arretes et d'avions
    int nb_sommets, nb_arretes, nb_avions;

    std::ifstream ifs{fichier_config};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + fichier_config );

    ifs >> nb_sommets;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture de l'ordre du graphe");
    configurerSommets(ifs, nb_sommets);

    ifs >> nb_arretes;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture du nombre d arrete");
    configurerArretes(ifs, nb_arretes);

    ifs >> nb_avions;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture des avions");
    configurerAvions(ifs, nb_avions);
}

bool read_choice( int & choix ) ///blindage saisie https://cpp.developpez.com/faq/cpp/?page=Manipulation-de-la-console#Comment-verifier-les-valeurs-saisies-avec-cin
{
    //Menu pour toutes les fonctions, s'execute jusqu'a l'appui sur la touche 7
    std::cout << std::endl << "Votre choix : ";
    while ( ! ( std::cin >> choix) || choix < 1 || choix > 8 )
    {
        if ( std::cin.eof() )
        {
            // ^D  (^Z sous windows); Fin du flux d'entree !
            return false;
        }
        else if ( std::cin.fail() )
        {
            std::cout << "Saisie incorrecte"<<std::endl;
            std::cout << std::endl << "Votre choix : ";
            std::cin.clear();
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        }
        else
        {
            std::cout << "Saisie incorrecte"<<std::endl;
            std::cout << std::endl << "Votre choix : ";
        }
    }
    return true; // succès
}

bool read_choice2( int & nb ) ///blindage saisie pour dijkstra
{
    //Menu pour toutes les fonctions, s'execute jusqu'a l'appui sur la touche 7
    while ( ! ( std::cin >> nb) || nb < 1 || nb > 8 )
    {
        if ( std::cin.eof() )
        {
            // ^D  (^Z sous windows); Fin du flux d'entree !
            return false;
        }
        else if ( std::cin.fail() )
        {
            std::cout << "Saisie incorrecte"<<std::endl;
            std::cout << std::endl << "Votre choix : ";
            std::cin.clear();
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        }
        else
        {
            std::cout << "Saisie incorrecte"<<std::endl;
            std::cout << std::endl << "Votre choix : ";
        }
    }
    return true; // succès
}

void BorneInteractive::demarrer()
{
    int choix;
    int depart;
    int arrivee;
    std::cout << "\t\t\t\tPROJET THEORIE DES GRAPHES : SIMULATION DU CONTROLE AERIEN" << std::endl;
    do
    {
        std::cout << std::endl << "Que voulez vous faire ?" << std::endl;
        std::cout << std::endl << "1- Liste des aeroports" << std::endl;
        std::cout << "2- Liste des trajets (Liste d'adjacence)" << std::endl;
        std::cout << "3- Liste des avions" << std::endl;
        std::cout << "4- Liste des aeroports IHM" << std::endl;
        std::cout << "5- Effectuer un trajet" << std::endl;
        std::cout << "6- Crise mondiale energetique" << std::endl;
        std::cout << "7- Trajet avec IHM" << std::endl;
        std::cout << "8- Quitter" << std::endl;

        if ( read_choice( choix ) ) ///Appel du sspg permettant le blindage
        {
            std::cout << "Votre choix est : " << choix << std::endl;
        }

        switch(choix)
        {
        case 1:
        {
            monde.afficherSommets();
            break;
        }
        case 2:
        {
            monde.afficherArretes(-1,-1);
            break;
        }
        case 3:
        {
            monde.afficherAvions();
            break;
        }

        case 4:
        {
            std::cout << "Appuyez sur ESC pour quitter" << std::endl;
            IHM I{depart,arrivee};
            break;
        }

        case 5:
        {
            std::cout << "Trajet entre aeroports" << std::endl;

            std::cout << std::endl << "Aeroport de depart : ";
            read_choice2( depart );  ///Appel du sspg2 permettant le blindage
            std::cout << std::endl << "Aeroport d'arrivee : ";
            read_choice2( arrivee );  ///Appel du sspg2 permettant le blindage

            monde.dijkstra(depart,arrivee);
            break;
        }
        case 6:
        {
            //Crise mondiale énergetique - Kruskal
            std::cout<< std::endl << "Une crise mondiale du petrole reduit tres fortement le nombre d avions pouvant voler. Certains aeroports" << std::endl;
            std::cout << "sont meme obliges de fermer, creant des zones d exclusion aerienne. Pour réduire au maximum la" << std::endl;
            std::cout << "consommation de kerosene des rares avions qui peuvent voler, il faut minimiser la distance parcourue dans" << std::endl;
            std::cout << "l ensemble des aeroports parcourus avec escales." << std::endl;
            std::cout << std::endl;
            monde.kruskal();
            break;
        }
        case 7:
        {
            std::cout << "Trajet entre aeroports" << std::endl;
            std::cout << std::endl << "Aeroport de depart : ";
            read_choice2( depart );  ///Appel du sspg2 permettant le blindage
            std::cout << std::endl << "Aeroport d'arrivee : ";
            read_choice2( arrivee );  ///Appel du sspg2 permettant le blindage
            std::cout << "Simulation IHM" << std::endl;
            monde.dijkstra(depart,arrivee);
            std::cout << "Appuyez sur ESC pour quitter" << std::endl;
            IHM I{depart,arrivee};
            break;
        }

        case 8:
            std::cout << "Vous quittez le programme" << std::endl;
            break;
        }
    }
    while(choix!=8);

}
