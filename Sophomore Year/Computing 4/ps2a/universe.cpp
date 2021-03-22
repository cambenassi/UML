#include <iostream>
#include "universe.h"

using namespace std;

Universe::Universe(int numParticles, double radius){
    //pass numParticles, for loop, call new CelestialBody shared ptr, cin data and push to vector
    for(int i = 0; i < numParticles; i++){
        shared_ptr<CelestialBody> ptr (new CelestialBody);
        CelestialBody temp;
        ptr->setRadius(radius);
        cin >> *ptr; 
        objects.push_back(ptr);
    }
}
