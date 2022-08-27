#ifndef BORNEINTERACTIVE_H_INCLUDED
#define BORNEINTERACTIVE_H_INCLUDED

#include <string>
#include "Monde.h"


class BorneInteractive
{
private :
    Monde monde;
    void configurerSommets(std::ifstream &ifs, int nb_sommets);
    void configurerArretes(std::ifstream &ifs, int nb_arretes); //id numéro avion
    void configurerAvions(std::ifstream &ifs, int nb_avions);
public:
    void configurer(std::string fichier_config);
    void demarrer();
};

#endif // BORNEINTERACTIVE_H_INCLUDED
