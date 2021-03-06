#include <iostream>
#include "celestial.h"
#include "universe.h"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]){
    int numParticles;
    double radius, endTime, deltaTime, currentTime = 0;

    endTime = atof(argv[1]);
    deltaTime = atof(argv[2]);

    cin >> numParticles >> radius;
    Universe test(numParticles, radius);

    sf::RenderWindow SolarSystem(sf::VideoMode(600, 600), "Solar System");
    SolarSystem.setFramerateLimit(60);

    sf::SoundBuffer buffer;
    sf::Sound sound;
    if(!buffer.loadFromFile("halo.wav"))
        return -1;
    sound.setBuffer(buffer);
    sound.play();

    while(SolarSystem.isOpen()){
        sf::Event event;
        while(SolarSystem.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                SolarSystem.close();
            }
        if(currentTime < endTime){
            test.step(deltaTime);
            SolarSystem.clear();
            for(auto body : test.objects)
                SolarSystem.draw(*body);
            SolarSystem.display();


            currentTime += deltaTime;
        }
        else
            SolarSystem.close();
    }
    
    for(auto body : test.objects)
        cout << *body;
    

    return 0;
}
