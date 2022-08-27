#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include <vector>
#include <string>
#include <queue>

class Avion;

class Sommet
{
private :
    int id;
    std::string nom;
    const int GPS, nbPistes, nbPlaces, TpsAttenteSol, TpsAccesPiste, TpsDecAt, DelaiCol, TpsBoucleAtt;

    std::queue<Avion*> fileAtt;
    std::queue<Avion*>fileDeco;
    Sommet* m_antecedent=NULL;
    int m_distance=INT_MAX;

public:
    Sommet(int id, std::string nom, int GPS, int nbPistes, int nbPlaces, int TpsAttenteSol, int TpsAccesPiste, int TpsDecAt, int DelaiCol, int TpsBoucleAtt):
        id(id), nom(nom), GPS(GPS), nbPistes(nbPistes), nbPlaces(nbPlaces), TpsAttenteSol(TpsAttenteSol), TpsAccesPiste(TpsAccesPiste), TpsDecAt(TpsDecAt), DelaiCol(DelaiCol), TpsBoucleAtt(TpsBoucleAtt), nbPistesDispo(nbPistes), nbPlacesDispo(nbPlaces) {};
    void afficher();
    int getId();
    std::string getNom()
    {
        return nom;
    }
    int getDistance()
    {
        return m_distance;
    }

    void setDistance(int _distance)
    {
        m_distance=_distance;
    }
    void reset()
    {
        m_antecedent=NULL;
        m_distance=INT_MAX;
    }
    Sommet* getAntecedent()
    {
        return m_antecedent;
    }

    void setAntecedent(Sommet* _antecedent)
    {
        m_antecedent=_antecedent;
    }
    int nbPistesDispo, nbPlacesDispo;


    std::string toString(); //fonction pour recup ce quil y a dans le fichier


};
#endif // SOMMET_H_INCLUDED
