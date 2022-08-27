#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED
#define EN_VOL 0
#define DECOL 1
#define ATTER 2
#define STATIO 3
class Sommet;

class Avion
{
private :
    int id;
    std::string modele, type;
    int consommation, capacite, x, y;


public:
    Avion(int id, std::string modele, std::string type, int consommation, int capacite, int x, int y):
        id(id), modele(modele), type(type), consommation(consommation), capacite(capacite), x(x), y(y) {};
    void afficher();
    int getId();
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    int statut;
    Sommet* aeroActuel;
    Sommet* destination;

    std::string toString(); //fonction pour recup ce quil y a dans le fichier

};

#endif // AVION_H_INCLUDED
