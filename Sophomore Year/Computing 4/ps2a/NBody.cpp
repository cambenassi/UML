#include <iostream>
#include "celestial.h"
#include "universe.h"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc, char* argv[]){
    int numParticles;
    double radius;

    cin >> numParticles >> radius;
    Universe test(numParticles, radius);

    sf::RenderWindow SolarSystem(sf::VideoMode(600, 600), "Solar System");
    while(SolarSystem.isOpen()){
        for(int i = 0; i < numParticles; i++){
            SolarSystem.draw(*test.objects.at(i));
        }
        SolarSystem.display();
    }
    
    
    
    return 0;
}
