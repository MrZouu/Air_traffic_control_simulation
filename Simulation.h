#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED
#include "Monde.h"
#include <random>
#include <time.h>

class Simulation
{
private:
    Monde monde;
    std::vector<Avion*> avions;
public:
    Simulation();
    void lancerSim();
    void manageFlyingPlane(Avion *avion);
    void gererAtter();
    void gererDecol();
};


#endif // SIMULATION_H_INCLUDED
