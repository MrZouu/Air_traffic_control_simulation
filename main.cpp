#include <iostream>
#include "BorneInteractive.h"

int main()
{
    BorneInteractive borne;

    try
    {
        borne.configurer("monde.txt"); //Configuration de la lecture du fichier monde.txt
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    borne.demarrer(); //Appel du menu

    return 0;
}
