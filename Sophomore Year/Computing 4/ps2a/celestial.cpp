#include <iostream>
#include "celestial.h"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

CelestialBody::CelestialBody(double radius, double xU, double yU, double xVelU, double yVelU, double massU, string nameU){
    x = (xU / radius) * 300 + 300;
    y = (yU / radius) * 300 + 300;
    xVel = xVelU;
    yVel = yVelU;
    mass = massU;
    name = nameU;

    texture.loadFromFile(name);
    sprite.setTexture(texture);
    sprite.move(x, y);

}

CelestialBody::CelestialBody(){
    name = "default";
}

istream& operator>>(istream& os, CelestialBody& input){
    double xU, yU, xVelU, yVelU, massU;
    string nameU;

    cin >> xU >> yU >> xVelU >> yVelU >> massU >> nameU;

    input.x = (xU / input.radius) * 300 + 300;
    input.y = (yU / input.radius) * 300 + 300;
    input.xVel = xVelU;
    input.yVel = yVelU;
    input.mass = massU; 
    input.name = nameU;

    input.texture.loadFromFile(input.name);
    input.sprite.setTexture(input.texture);
    input.sprite.move(input.x, input.y);

    //cout << input.name << endl;

    return os;
}

void CelestialBody::setRadius(double radiusU){
    radius = radiusU;
}

void CelestialBody::draw(sf::RenderTarget& SolarSystem, sf::RenderStates states) const{
    SolarSystem.draw(sprite);
}


