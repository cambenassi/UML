#ifndef universe_h
#define universe_h

#include <vector>
#include <memory>
#include "celestial.h"

using namespace std;

class Universe{
    public:
        Universe(int numParticles, double radius);
        vector<shared_ptr<CelestialBody>> objects;

        void step(double seconds);
    private:
        

};

#endif